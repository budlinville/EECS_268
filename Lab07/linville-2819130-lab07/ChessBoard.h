/*
File: ChessBoard.h
Author: Bud Linville
Date: March 10, 2016
Purpose: To house all data corrsponding to the chessboard and the movement of the "Knight" across it
*/

#ifndef _CB_
#define _CB_
#include <iostream>

class ChessBoard {
  private:
    int numRows;
    int numColumns;
    int startingRow;
    int startingColumn;
    bool **spaceOpen;  //holds false if client can move to this position; false otherwise;
    int **moveOrder;  //holds value corresponding to order in which a space was filled;

  public:
    /*
      @Constructor: default - will create 2D arrays corresponding to a 5x5 board with starting point (0,0)
    */
    ChessBoard();

    /*
      @Constructor: constructor actually used in implementation of program
      @Pre:
      @Post: board is created according to user-set size and user-set starting point
             passed in as parameters
    */
    ChessBoard(const int &r, const int &c, const int &sr, const int &sc);

    /*
      @Destructor:
      @Pre: Dynamically allocated arrays filled
      @Post: Deletes contents of the arrays and then the arrays themselves.
    */
    ~ChessBoard();

    /*
      @Pre: Space has either been landed on (false) or not (true)
      @Post: Space is no longer open and variable - "spaceOpen" - is set to False
    */
    void setSpaceToClosed(int r, int c);

    /*
      @Pre: Space has either been landed on (false) or not (true)
      @Post: Space is now open and variable - "spaceOpen" - is set to True
    */
    void setSpaceToOpen(int r, int c);

    /*
    @pre:
    @post:
    @return: returns boolean value corresponding to whether the space is available or not
    @Return: if space corresponding to position (r,c) is open returns true; false otherwise;
    */
    bool getSpaceOpen(int r, int c);

    /*
    @post: sets value at position (r, c) to the int-value passed as a parameter (moveOrder);
    */
    void setMoveOrder(int r, int c, int order);

    /*
    @Return: value of position corresponding to the time at which position (r, c) was filled;
    */
    int getMoveOrder(int r, int c);

    /*
      @Return: get methods for rows, columns, starting row, and starting column;
      @Note: set methods have been avoided for all of the above because
             these values should remain constant
    */
    int getNumColumns();

    int getNumRows();

    int getStartingRow();

    int getStartingColumn();

    void printBoard();
};

#endif
