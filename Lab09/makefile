lab09: main.o PrecondViolatedExcep.o bubbleSort.o insertionSort.o mergesort.o quicksort.o selectionSort.o
	g++ -std=c++11 -g -Wall main.o PrecondViolatedExcep.o bubbleSort.o insertionSort.o mergesort.o quicksort.o selectionSort.o -o lab09

main.o: main.cpp bubbleSort.cpp insertionSort.cpp mergesort.cpp quicksort.cpp selectionSort.cpp PrecondViolatedExcep.h
	g++ -std=c++11 -g -Wall -c main.cpp

PrecondViolatedExcep.o: PrecondViolatedExcep.h PrecondViolatedExcep.cpp
	g++ -std=c++11 -g -Wall -c PrecondViolatedExcep.cpp

bubbleSort.o: bubbleSort.cpp
	g++ -std=c++11 -g -Wall -c bubbleSort.cpp

insertionSort.o: insertionSort.cpp
	g++ -std=c++11 -g -Wall -c insertionSort.cpp

mergesort.o: mergesort.cpp
	g++ -std=c++11 -g -Wall -c mergesort.cpp

quicksort.o: quicksort.cpp
	g++ -std=c++11 -g -Wall -c quicksort.cpp

selectionSort.o: selectionSort.cpp
	g++ -std=c++11 -g -Wall -c selectionSort.cpp

clean:
	rm *.o lab09
