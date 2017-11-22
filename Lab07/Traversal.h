/*
File: Traversal.h
Author: Bud Linville
Date: March 20, 2016
Purpose: To perform all operations that are required in moving the knight across the board
*/

#ifndef _TRA_
#define _TRA_
#include "ChessBoard.h"
#include <iostream>

class Traversal {
  private:
    ChessBoard *board;
    int numMoves;
    int BOARD_SIZE;
    int rowMove[8] = {-2, -1, 1, 2, 2, 1, -1, -2};     //8 possible moves
    int colMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    bool traverseBoard(int currentRow, int currentCol);

    /*
      @pre:
      @post:
      @return: a boolean value corresponding to whether or not a move is available to move to
      @Note: An invalid move is one that is either out of bound or has been landed on previously
    */
    bool isMoveAvailable(int nextRow, int nextCol);

    /*
      @pre:
      @post:
      @return: a boolean value corresponding to whether or not the move was out of bounds.
    */
    bool isMoveInBounds(int nextRow, int nextCol);

  public:

    /*
      @Constructor
      @Note1: moveNumber refers the total number of moves the chess piece has made
      @Note2: possibleMove refers to an index of one of the 8 potential moves that a knight piece
        can make on a chess board.
    */
    Traversal(int numRows, int numCols, int startRow, int startCol);

    ~Traversal();

    /*
      @pre: Called from main class, cycles through the 8 possible moves a knight can make
    */
    void beginTraversal();
};

#endif
