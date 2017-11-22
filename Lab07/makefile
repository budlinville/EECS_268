lab07: main.o ChessBoard.o Traversal.o
	g++ -std=c++11 -g -Wall main.o ChessBoard.o Traversal.o -o lab07

main.o: main.cpp ChessBoard.h Traversal.h
	g++ -std=c++11 -g -Wall -c main.cpp

ChessBoard.o: ChessBoard.h ChessBoard.cpp
	g++ -std=c++11 -g -Wall -c ChessBoard.cpp

Traversal.o: Traversal.h Traversal.cpp ChessBoard.h
	g++ -std=c++11 -g -Wall -c Traversal.cpp

clean:
	rm *.o lab07
