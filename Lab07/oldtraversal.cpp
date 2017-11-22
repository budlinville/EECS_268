/*
File: main.cpp
Author: Bud Linville
Date: March 10, 2016
Purpose: Implementation of Traversal.h
*/

#include "Traversal.h"
#include "iostream"

Traversal::Traversal(ChessBoard &mkb){
  myKnightBoard = mkb;
  moveNumber = 1;
  possibleMove = 1;   //8 possible moves - all of which may or may not need to be checked;
  BOARD_SIZE = myKnightBoard.getNumRows() * myKnightBoard.getNumColumns();
}

bool Traversal::isMoveOutOfBounds(int nextRow, int nextColumn){
  bool moveOutOfBounds = false;

  if ((nextRow < 0) || (nextRow > myKnightBoard.getNumRows() - 1)) {
    moveOutOfBounds = true;
  } else if ((nextColumn < 0) || (nextColumn > myKnightBoard.getNumColumns() - 1)) {
    moveOutOfBounds = true;
  } else {
    moveOutOfBounds = false;
  }

  return moveOutOfBounds;
}

bool Traversal::isMoveOpen(int nextRow, int nextColumn){
  bool moveOpen = false;
  bool outOfBounds = false;

  outOfBounds = isMoveOutOfBounds(nextRow, nextColumn);

  if (outOfBounds == true) {
    moveOpen = false;
  } else {
    moveOpen = myKnightBoard.getSpaceOpen(nextRow, nextColumn);
  }

  return moveOpen;
}

bool Traversal::checkPossibleMoves(int currentRow, int currentColumn){
  bool moveWorks = false;

  while (moveNumber < BOARD_SIZE - 1) {
    while (moveWorks == false) {
      switch (possibleMove) {
        case 1 : moveWorks = traverseBoard(currentRow - 2, currentColumn + 1);
          if (moveWorks == false) {
            possibleMove++;
          } else {
              return true;
        break;

        case 2 : moveWorks = traverseBoard(currentRow - 1, currentColumn + 2);
          if (moveWorks == false) {
            possibleMove++;

          } else {
            return true;
          }
        break;

        case 3 : moveWorks = traverseBoard(currentRow + 1, currentColumn + 2);
          if (moveWorks == false) {
            possibleMove++;

          } else {
            return true;
          }
        break;

        case 4 : moveWorks = traverseBoard(currentRow + 2, currentColumn + 1);
          if (moveWorks == false) {
            possibleMove++;
          } else {
            return true;
          }
        break;

        case 5 : moveWorks = traverseBoard(currentRow + 2, currentColumn - 1);
          if (moveWorks == false) {
            possibleMove++;
          } else {
            return true;
          }
        break;

        case 6 : moveWorks = traverseBoard(currentRow + 1, currentColumn - 2);
          if (moveWorks == false) {
            possibleMove++;
          } else {
            return true;
          }
        break;

        case 7 : moveWorks = traverseBoard(currentRow - 1, currentColumn - 2);
          if (moveWorks == false) {
            possibleMove++;
          } else {
            return true;
          }
        break;

        case 8 : moveWorks = traverseBoard(currentRow - 2, currentColumn - 1);
          if (moveWorks == false) {
            return false;
          } else {
            return true;
          }
        break; //special case
        }
      }
    }
  }
}

bool Traversal::traverseBoard(int curRow, int curCol) {
  bool nextMoveWorks;
  bool moveOpen = isMoveOpen(curRow, curCol);

    if (moveOpen == false) {
      possibleMove++;
      return false;
    } else {
      myKnightBoard.setSpaceToClosed(curRow, curCol);
      myKnightBoard.setMoveOrder(curRow, curCol, moveNumber);
      moveNumber++;
    }
    if (moveNumber == BOARD_SIZE - 1) {
      return true;    //ending condition - board is full;
    }
    //otherwise:
    nextMoveWorks = checkPossibleMoves(curRow, curCol);

    if (nextMoveWorks == false){
      myKnightBoard.setSpaceToOpen(curRow, curCol);
      myKnightBoard.setMoveOrder(curRow, curCol, 0);
      moveNumber--;
    }

    return nextMoveWorks;
}
