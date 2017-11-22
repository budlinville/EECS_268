/*
File: ChessBoard.h
Author: Bud Linville
Date: March 20, 2016
Purpose: To house all data corrsponding to the knight
*/

#ifndef _K_
#define _K_
#include "ChessBoard.h"

class Knight {
  private:
    int row;
    int col;
    ChessBoard *board;

  public:
    Knight(int inRow, int inCol, ChessBoard *knightBoard);

    int getRow() const;

    int getCol() const;

    //moves knight to next space and updates values accordingly
    void nextSpace(int r, int c, int moveNumber);

    //knight has been moved to last space and updates values accordingly
    void lastSpace(int r, int c);

    bool isMoveAvailable(int nextRow, int nextCol);

    bool isMoveOutOfBounds(int nextRow, int nextCol);
};

#endif
