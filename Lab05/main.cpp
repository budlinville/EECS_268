/*
File: Stack.h
Author: Bud Linville
Date: February 28th, 2016
Purpose: starts lab5
*/

#include <iostream>
#include <string>
#include "Queue.h"
#include "Stack.h"
#include <iostream>
#include <fstream>
#include <cstring>

/*
  pre: input file gets passed as arg with conditions such as 'done' 'show' 'VIP_' and customer namespace
  post: outputs what is happening in Queue and Stack according to how file is written.
*/
int main(int argc, char* argv[]) {
  Queue<std::string> *customerQueue = new Queue<std::string>();
  Stack<std::string> *VIPStack = new Stack<std::string>();

  std::string fileName = argv[1];
  std::ifstream inp(fileName);

  string nextTask = "";

  while(inp >> nextTask) {
    if (nextTask.substr(0,3) == "VIP") {
      if (VIPStack->isEmpty()){
        VIPStack->push(nextTask);
      } else {
        int newVIP = std::stoi(nextTask.substr(3,1));
        string topVIP = VIPStack->peek();
        int oldVIP = std::stoi(topVIP.substr(3,1));
        if (newVIP > oldVIP) {
            VIPStack->push(nextTask);
        }
      }
    } else if (nextTask == "show") {
      if (!(VIPStack->isEmpty())) {
        std::cout << VIPStack->peek() << " is currently being served; ";
        if (VIPStack->nextNode() == nullptr) {
          if (customerQueue->isEmpty() == true) {
            std::cout << "no one is behind him/her." << std::endl;
          } else {
            std::cout << customerQueue->peekFront() << " is waiting at the front of the queue." << std::endl;
          }
        } else {
          std::cout << VIPStack->nextValue() << " is waiting at the front of the stack." << std::endl;
        }
      } else {
        if (!(customerQueue->isEmpty())) {
          std::cout << customerQueue->peekFront() << " is currently being served; ";
          if (customerQueue->nextNode() == nullptr) {
            std::cout << "no on is behind him/her." << std::endl;
          } else {
            std::cout << customerQueue->nextValue() << " is waiting at the front of the queue." << std::endl;
          }
        } else {
          std::cout << "No one in line. Lydia rests." << std::endl;
        }
      }
    } else if (nextTask == "done") {
      if (!(VIPStack->isEmpty())) {
        std::cout << VIPStack->peek() << " is done; ";
        VIPStack->pop();
        if (VIPStack->isEmpty()){
          if (customerQueue->isEmpty()){
            std::cout << "no one is waiting; Lydia rests." << std::endl;
          } else {
            std::cout << customerQueue->peekFront() << " is resuming." << std::endl;
          }
        } else {
          std::cout << VIPStack->peek() << " is resuming." << std::endl;
        }
      } else {
        if (customerQueue->isEmpty()) {
          std::cout << "No one is in line, Lydia rests." << std::endl;
        } else {
          std::cout << customerQueue->peekFront() << " is done; ";
          customerQueue->dequeue();
          if (customerQueue->isEmpty()) {
            std::cout << "no one is in line. Lydia rests." << std::endl;
          } else {
            std::cout << customerQueue->peekFront() << " is resuming." << std::endl;
          }
        }
      }
    } else {
      customerQueue->enqueue(nextTask);
    }
  }

  inp.close();
  return 0;
}
