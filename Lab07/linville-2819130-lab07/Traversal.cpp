/*
File: main.cpp
Author: Bud Linville
Date: March 10, 2016
Purpose: Implementation of Traversal.h
*/

#include "Traversal.h"

Traversal::Traversal(int numRows, int numCols, int startRow, int startCol) {
  board = new ChessBoard(numRows, numCols, startRow, startCol);
  numMoves = 0;
  BOARD_SIZE = numRows * numCols;     //number of squares or possible moves
}

Traversal::~Traversal() {
  delete board;
}

void Traversal::beginTraversal() {
  bool itWorked = traverseBoard(board->getStartingRow(), board->getStartingColumn());

  if (itWorked) {
    board->printBoard();
	} else {
    std::cout << "Failed!" << std::endl;
    board->printBoard();
	}
}

bool Traversal::traverseBoard(int currentRow, int currentCol) {
  board->setMoveOrder(currentRow, currentCol, numMoves);
  board->setSpaceToClosed(currentRow, currentCol);

  if (numMoves == BOARD_SIZE - 1) {
    return true;
  } else {
    for (int i = 0; i < 8; i++) {
      if (isMoveAvailable(currentRow + rowMove[i], currentCol + colMove[i]) == true) {
        numMoves++;
        if (traverseBoard(currentRow + rowMove[i], currentCol + colMove[i]) == true) {
          return true;
      }
    }
  }
    numMoves--;
    board->setSpaceToOpen(currentRow, currentCol);
    //board->setMoveOrder(currentRow, currentCol, 0);
    return false;
  }
}


bool Traversal::isMoveAvailable(int nextRow, int nextCol) {
  bool moveOpen = false;
  bool inBounds = false;

  inBounds = isMoveInBounds(nextRow, nextCol);

  if (inBounds == false) {
    moveOpen = false;
  } else {
    moveOpen = board->getSpaceOpen(nextRow, nextCol);
  }

  return moveOpen;
}

bool Traversal::isMoveInBounds(int nextRow, int nextCol){
  bool moveInBounds = false;

  if ((nextRow < 0) || (nextRow > board->getNumRows() - 1)) {
    moveInBounds = false;
  } else if ((nextCol < 0) || (nextCol > board->getNumColumns() - 1)) {
    moveInBounds = false;
  } else {
    moveInBounds = true;
  }

  return moveInBounds;
}
