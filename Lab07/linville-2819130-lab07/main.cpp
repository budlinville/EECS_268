/*
File: main.cpp
Author: Bud Linville
Date: March 10, 2016
Purpose: To write a recursively defined program that moves a theoretical ches piece across every
				 square of an n x m chess board, while only touching each square once.
*/

#include <cstdlib>
#include <iostream>
#include "ChessBoard.h"
#include "Traversal.h"
#include <iostream>

int main(int argc, char* argv[]){
	int m = 0;	//num of Rows;
	int n = 0; 	//num of columns;
	int initialKnightRow = 0;	//index corresponding to the initial row in which the knight starts
	int initialKnightColumn = 0;	//index corresponding to the initial column in which the knight starts
	m = atoi(argv[1]);
	n = atoi(argv[2]);
	initialKnightRow = atoi(argv[3]);
	initialKnightColumn = atoi(argv[4]);
  ChessBoard board(m,n,initialKnightRow,initialKnightColumn);

	Traversal KnightBoardTraversal(m, n, initialKnightRow, initialKnightColumn);		//object for the "operations class" of the program

	KnightBoardTraversal.beginTraversal();

	return 0;
}
