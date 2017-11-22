lab10: main.o NotFoundException.o
	g++ -std=c++11 -g -Wall main.o NotFoundException.o -o lab10

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

NotFoundException.o: NotFoundException.h NotFoundException.cpp
	g++ -std=c++11 -g -Wall -c NotFoundException.cpp

clean:
	rm *.o lab10
