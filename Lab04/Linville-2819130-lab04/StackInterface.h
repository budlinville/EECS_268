/*
File: StackInterface.h
Author: Bud Linville
Date: February 21st, 2016
Purpose: interface for stack class - no actual implementation file because never implemented
*/

#ifndef STACKINT_H
#define STACKINT_H
#include "PreconditionViolationException.h"
#include <vector>

template <class T>
class StackInterface {
  public:
    //destructor
    virtual ~StackInterface() {};
    
    virtual bool isEmpty() const = 0;

    virtual void push(const T value) = 0;

    virtual void pop() throw(PreconditionViolationException) = 0;
  
    virtual T peek() const throw(PreconditionViolationException) = 0;

    virtual int size() const = 0;

    //used for testing; not a standard stack method; front of vector = top of stack;
    virtual std::vector<T> toVector() const = 0;
};

#endif
