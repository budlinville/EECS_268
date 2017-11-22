lab08: main.o PrecondViolatedExcep.o XMLConvention.o
	g++ -std=c++11 -g -Wall main.o PrecondViolatedExcep.o XMLConvention.o -o lab08

main.o: main.cpp Stack.h Queue.h PrecondViolatedExcep.h XMLConvention.h
	g++ -std=c++11 -g -Wall -c main.cpp

PrecondViolatedExcep.o: PrecondViolatedExcep.h PrecondViolatedExcep.cpp
	g++ -std=c++11 -g -Wall -c PrecondViolatedExcep.cpp

XMLConvention.o: XMLConvention.h XMLConvention.cpp
	g++ -std=c++11 -g -Wall -c XMLConvention.cpp

clean:
	rm *.o lab08
