#include "PreconditionViolationException.h"

PreconditionViolationException::PreconditionViolationException(const std::string message){
  try {

  } catch (std::exception& e) {
    std::cout << e.what();
  }
}
