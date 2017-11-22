#include <stdexcept>

class PreconditionViolationException: public runtime_error {
  public:
    PreconditionViolationException(const std::string message);
};
