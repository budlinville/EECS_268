/*
File: PreconditionViolationException.h
Author: Bud Linville
Date: February 21st, 2016
Purpose: exception class for conditions such as popping or peeking an empty stack
*/

#ifndef PVE_H
#define PVE_H
#include <stdexcept>

class PreconditionViolationException:public std::runtime_error {
  public:
    //constructor that passes in a string value that communicates type of exception
    PreconditionViolationException(const std::string message);
};

#endif
