/*
File: PreconditionViolationException.cpp
Author: Bud Linville
Date: February 21st, 2016
Purpose: implementation of PVE class
*/

#include "PreconditionViolationException.h"

PreconditionViolationException::PreconditionViolationException(const std::string message):runtime_error(message.c_str()){
 
}
