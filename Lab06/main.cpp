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
  int numOperators = 0;
  int numOperands = 0;

  while (expression != FLAG) {
    std::cout << "Enter a string: ";
    std::cin >> expression;

    if (expression != FLAG) {
      for (int i = 0; i < signed (expression.length()); i++){
        index = expression[i];
        if ((index >= "A" && index <= "Z") || (index >= "a" && index <= "z")) {
          operandStack->push(index);
          numOperands ++;
        } else if (index == "+") {
          doOperation(operandStack, "+");
          numOperators++;
        } else if (index == "-") {
          doOperation(operandStack, "-");
          numOperators++;
        } else if (index == "*") {
          doOperation(operandStack, "*");
          numOperators++;
        } else if (index == "/") {
          doOperation(operandStack, "/");
          numOperators++;
        } else {
          std::cout << "You entered an invalid postfix string: it containts the illegal character '" << index << "'" << std::endl;
          validInput = false;
          i = expression.length();
        }
      }

      if (numOperands > numOperators + 1) {
       std::cout << "You entered an invalid postfix string: it is missing one or more operators." << std::endl;
       validInput = false;
      }

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
