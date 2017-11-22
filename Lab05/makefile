lab05: main.o PrecondViolatedExcep.o
	g++ -std=c++11 -g -Wall main.o PrecondViolatedExcep.o -o lab05

main.o: main.cpp Stack.h  Stack.hpp Queue.h Queue.hpp PrecondViolatedExcep.h
	g++ -std=c++11 -g -Wall -c main.cpp

PrecondViolatedExcep.o: PrecondViolatedExcep.h PrecondViolatedExcep.cpp
	g++ -std=c++11 -g -Wall -c PrecondViolatedExcep.cpp

clean:
	rm *.o lab05
