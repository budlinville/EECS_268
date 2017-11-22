/*
File: main.cpp
Author: Bud Linville
Date: March 2, 2016
Purpose: main file for lab06 project

turns postfix expressions into infix expressions
*/

#include "Stack.h"
#include <string>
#include <iostream>
#include "PrecondViolatedExcep.h"

/*
pre: stack has values a and b, stacked linearally
post: stack now combines a and b according to the operation passed as a char paramater and stores (a [operation] b)
return: #N/A
*/

void doOperation(Stack<std::string> *m_stack, std::string operation) throw (PrecondViolatedExcep) {
  try {
    string op1, op2, result;
    op1 = m_stack->peek();
    m_stack->pop();
    op2 = m_stack->peek();
    m_stack->pop();
    result = "(" + op2 + operation + op1 + ")";
    m_stack->push(result);

  } catch (PrecondViolatedExcep &e) {
    throw PrecondViolatedExcep("You entered an invalid postfix string: it is missing operands.");
  }
}

int main() {
  std::string expression = "";
  string index = "";
  Stack<std::string> *operandStack = new Stack<std::string>();
  const string FLAG = "#";
  bool validInput = true;
  bool illegalChar = false;


  while (expression != FLAG) {
    std::cout << "Enter a string: ";
    std::cin >> expression;

    if (expression != FLAG) {
      for (int i = 0; i < signed (expression.length()); i++){
        index = expression[i];
        if ((index >= "A" && index <= "Z") || (index >= "a" && index <= "z")) {
          operandStack->push(index);
        } else if (index == "+") {
          doOperation(operandStack, "+");
        } else if (index == "-") {
          doOperation(operandStack, "-");
        } else if (index == "*") {
          doOperation(operandStack, "*");
        } else if (index == "/") {
          doOperation(operandStack, "/");
        } else {
          std::cout << "You entered an invalid postfix string: it containts the illegal character '" << index << "'" << std::endl;
          validInput = false;
          i = expression.length();
          illegalChar = true;
        }
      }

      /*should only be one element in stack
        otherwise there is an error
        must first check if the user tried to pass in an illegal character.
        If so, there will be nothing in stack and we would be popping/ppeking
        an empty stack which would throw an exception
      */
      if (!illegalChar) {
        std::string temp = operandStack->peek();
        operandStack->pop();
        if (operandStack->isEmpty() != true) {  //alternative way to check: check to see that there is 1 less operator as there are operands
          std::cout << "You entered an invalid postfix string: it is missing one or more operators." << std::endl;
          validInput = false;
        }
        operandStack->push(temp);
      }
      illegalChar = false;    //reset

      if (validInput == true) {
        std::cout << "You entered a valid postfix string. The equivalent infix: " << operandStack->peek() << std::endl;
      }
      validInput = true;    //reset

      while (operandStack->isEmpty() != true) {
        operandStack->pop();
      }
    }
  }

  return 0;
}
