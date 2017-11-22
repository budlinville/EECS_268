/*
File: Stack.h
Author: Bud Linville
Date: February 21st, 2016
Purpose: Houses nodes in a LIFO fashion
*/

#ifndef STACK_H
#define STACK_H
#include "StackInterface.h"
#include "Node.h"
#include "PreconditionViolationException.h"
#include <vector>

template <typename T>
class Stack:public StackInterface<T> {
  private:
    Node<T> *tos;
    int stackSize;
  public:
    //constructor
    Stack();

    //destructor
    ~Stack();

    /*
    pre: checks to see if top element of stack is a null pointer (stack empty)
    post: if so, returns true; false otherwise
    */
    bool isEmpty() const;

    /*
    pre: pushes all values down the stack and adds new element to the front
    post:
    */
    void push(const T value);

    /*
    pre: deletes top element of the stack and pulls all elements up one
    post:
    */
    void pop() throw(PreconditionViolationException);

    /*
    pre:
    post: returns value stored in top element of the stack
    */
    T peek() const throw(PreconditionViolationException);

    /*
    pre: 
    post: returns number of elements in stack
    */
    int size() const;

    //used for testing; not a standard stack method; front of vector = top of stack;
    std::vector<T> toVector() const;
};

#include "Stack.cpp"
#endif
