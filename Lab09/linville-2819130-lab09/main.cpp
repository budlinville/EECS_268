/*
File: main.cpp
Author: Bud Linville
Date:April 17th, 2016
Purpose: Tests speeds of various sorting algorithms
*/

#include "PrecondViolatedExcep.h"
#include "bubbleSort.cpp"
#include "insertionSort.cpp"
#include "mergesort.cpp"
#include "quicksort.cpp"
#include "selectionSort.cpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

int main(int argc, char* argv[]) throw (PrecondViolatedExcep){
  srand48(0);
  int arraySize = atoi(argv[1]);
  std::string arrayType = argv[2];
  std::string sortType = argv[3];
  double arr[arraySize];
  clock_t startTime, endTime, diff;

  if (arrayType == "ascending") {
    for (int i = 0; i < arraySize; i++) {
      arr[i] = 0.001*static_cast<double>(i);
    }
  } else if (arrayType == "descending") {
    for (int i = 0; i < arraySize; i++) {
      arr[i] = 0.001*static_cast<double>(arraySize - i - 1);
    }
  } else if (arrayType == "random") {
    for (int i = 0; i < arraySize; i++) {
      arr[i] = drand48();
    }
  } else {
    throw PrecondViolatedExcep("ERROR. Did not pass a valid arrayType as an argv paramater.");
  }

  if (sortType == "bubble") {
    startTime = clock();
    bubbleSort(arr, arraySize);
    endTime = clock();
  } else if (sortType == "insertion") {
    startTime = clock();
    insertionSort(arr, arraySize);
    endTime = clock();
  } else if (sortType == "selection") {
    startTime = clock();
    selectionSort(arr, arraySize);
    endTime = clock();
  } else if (sortType == "merge") {
    startTime = clock();
    mergeSort(arr, arraySize);
    endTime = clock();
  } else if (sortType == "quick") {
    startTime = clock();
    quickSort(arr, 0, (arraySize - 1));
    endTime = clock();
  } else {
    throw PrecondViolatedExcep("ERROR. Did not pass a valid sorting algorithm name as an argv paramater.");
  }

  diff = endTime - startTime;

  std::cout << "It took " << (diff/(double)(CLOCKS_PER_SEC)) << " seconds to do the operation." << std::endl;
}
