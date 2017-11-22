#include "StackInterface.h"
#include "Node.h"

template <class T>
class Stack<T> {
  private:
    Node *tos;
    T *items;
    int max;
  public:
    virtual Stack();

    virtual ~Stack();

    virtual bool isEmpty() const;

    virtual void push(const T value);

    virtual void pop() throw(PreconditionViolationException);

    virtual T peek() const throw(PreconditionViolationException);

    virtual int size() const;

    //used for testing; not a standard stack method; front of vector = top of stack;
    virtual std::vector<T> toVector const;
};
