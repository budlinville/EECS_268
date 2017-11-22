/*
File: make.cpp
Author: Bud Linville
Date: February 21st, 2016
Purpose: main method for lab04 project using a stack memory management technique
*/

#include <iostream>
#include "Stack.h"
#include "PreconditionViolationException.h"

int main() {
  Stack<int> myStack;
  int userNum = 0;
  int original = 0;
  int numModded = 0;
  bool validInput = false;
  int count = 1;
  int reverse = 0;
  bool stopPlaying = false;
  char inp = ' ';
  
  while (stopPlaying == false) {
    while (validInput == false){
      try {
        std::cout << "Input a number: ";
        std::cin >> userNum;
        original = userNum;			//maintains orginal value while userNum gets modified
        while (userNum != 0){
          numModded = userNum % 10;
          userNum = userNum / 10;		//will turn 54 to 5 and 839 to 83
          myStack.push(numModded);
        }

        validInput = true;
      } catch (std::exception &e){
        validInput = false;
      }
    }
    validInput = false;

    while (myStack.isEmpty() != true){
      reverse += (myStack.peek() * count);
      myStack.pop();
      count = count * 10;
    }

    std::cout << original << " backwards is " << reverse << std::endl;
    
    if (original == reverse) {
      std::cout << original << " is a palindrome" << std::endl;
    } else {
      std::cout << original << " is not a palindrome" << std::endl;
    }
    
    count = 1;
    reverse = 0;
    std::cout << std::endl << "Would you like to keep playing? (y/n): ";
    std::cin >> inp;
    if (inp == 'y'){
	stopPlaying = false;
    } else {
        stopPlaying = true;
    }
  }

  return 0;
}
