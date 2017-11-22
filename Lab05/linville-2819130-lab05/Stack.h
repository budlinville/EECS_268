/*
File: Stack.h
Author: Bud Linville
Date: February 22nd, 2016
Purpose: Houses nodes in a LIFO fashion

*taken from Lab 4; removed unnecessary and unconventional 'toVector' and 'size' methods
*/

#ifndef STACK_H
#define STACK_H
#include "StackInterface.h"
#include "Node.h"
#include "PrecondViolatedExcep.h"

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
    void push(const T &value) throw (PrecondViolatedExcep);

    /*
    pre: deletes top element of the stack and pulls all elements up one
    post:
    */
    void pop() throw(PrecondViolatedExcep);

    /*
    pre:
    post: returns value stored in top element of the stack
    */
    T peek() const throw(PrecondViolatedExcep);


    /*
    pre: atypical stack method used to see if the next Node is a nullptr
    post: returns nexd Node
    */
    Node<T>* nextNode() const throw (PrecondViolatedExcep);

    /*
    pre: another atypical stack method
    post: returns value of next node method
    */
    T nextValue() const throw (PrecondViolatedExcep);
};

#include "Stack.hpp"
#endif
