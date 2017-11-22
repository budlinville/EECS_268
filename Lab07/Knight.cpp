/*
File: ChessBoard.cpp
Author: Bud Linville
Date: March 20, 2016
Purpose: Implementation of Knight.h
*/

#include "Knight.h"

Knight::Knight(int inRow, int inCol, ChessBoard *knightBoard){
  row = inRow;
  col = inCol;
  board = knightBoard;
}

int Knight::getRow() const {
  return row;
}

int Knight::getCol() const {
  return col;
}

void Knight::nextSpace(int r, int c, int moveNumber) {
  row = r;
  col = c;
  board->setSpaceToClosed(r, c);
  board->setMoveOrder(r, c, moveNumber);
}

void Knight::lastSpace(int r, int c) {
  board->setSpaceToOpen(r, c);
  board->setMoveOrder(r, c, 0);
}

bool Knight::isMoveAvailable(int nextRow, int nextCol) {
  bool moveOpen = false;
  bool outOfBounds = false;

  outOfBounds = isMoveOutOfBounds(nextRow, nextCol);

  if (outOfBounds == true) {
    moveOpen = false;
  } else {
    moveOpen = board->getSpaceOpen(nextRow, nextCol);
  }

  return moveOpen;
}

bool Knight::isMoveOutOfBounds(int nextRow, int nextCol){
  bool moveOutOfBounds = false;

  if ((nextRow < 0) || (nextRow > board->getNumRows() - 1)) {
    moveOutOfBounds = true;
  } else if ((nextCol < 0) || (nextCol > board->getNumColumns() - 1)) {
    moveOutOfBounds = true;
  } else {
    moveOutOfBounds = false;
  }

  return moveOutOfBounds;
}
