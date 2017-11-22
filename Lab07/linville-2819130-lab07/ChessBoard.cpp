/*
File: ChessBoard.cpp
Author: Bud Linville
Date: March 10, 2016
Purpose: Implementation of ChessBoard.h
*/

#include "ChessBoard.h"

ChessBoard::ChessBoard() : numRows(5), numColumns(5), startingRow(0), startingColumn(0) {
  spaceOpen = new bool*[numRows];
  moveOrder = new int*[numRows];
  for (int i = 0; i < numRows; i++) {
    for (int j = 0; j < numColumns; j++) {
      spaceOpen[i] = new bool[numColumns];
      moveOrder[i] = new int[numColumns];
    }
  }
  for (int i = 0; i < numRows; i++) {
    for (int j = 0; j < numColumns; j++) {
      spaceOpen[i][j] = true;
      moveOrder[i][j] = 0;
    }
  }
}

ChessBoard::ChessBoard(const int &r, const int &c, const int &sr, const int &sc) : numRows(r), numColumns(c), startingRow(sr), startingColumn(sc) {
  spaceOpen = new bool*[numRows];
  moveOrder = new int*[numRows];
  for (int i = 0; i < numRows; i++) {
    for (int j = 0; j < numColumns; j++) {
      spaceOpen[i] = new bool[numColumns];
      moveOrder[i] = new int[numColumns];
    }
  }
  for (int i = 0; i < numRows; i++) {
    for (int j = 0; j < numColumns; j++) {
      spaceOpen[i][j] = true;
      moveOrder[i][j] = 0;
    }
  }
}

ChessBoard::~ChessBoard(){
  for (int i = 0; i < numRows; i++) {
    delete[] spaceOpen[i];
    delete[] moveOrder[i];
  }
  delete spaceOpen;
  delete moveOrder;
}

void ChessBoard::setSpaceToClosed(int r, int c){
  spaceOpen[r][c] = false;
}

void ChessBoard::setSpaceToOpen(int r, int c){
  spaceOpen[r][c] = true;
}

bool ChessBoard::getSpaceOpen(int r, int c){
  return (spaceOpen[r][c] == true);
}

void ChessBoard::setMoveOrder(int r, int c, int order){
  moveOrder[r][c] = order;
}

int ChessBoard::getMoveOrder(int r, int c){
  return (moveOrder[r][c]);
}

int ChessBoard::getNumRows(){
  return numRows;
}

int ChessBoard::getNumColumns(){
  return numColumns;
}

int ChessBoard::getStartingRow(){
  return startingRow;
}

int ChessBoard::getStartingColumn(){
  return startingColumn;
}

void ChessBoard::printBoard(){
  for (int i = 0; i < numRows; i++) {
    for (int j = 0; j < numColumns; j ++){
      std::cout << "[" << moveOrder[i][j] << "]\t";
    }
    std::cout << std::endl;
  }
}
