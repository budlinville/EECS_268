#include "Stack.h"

virtual Stack<T>::Stack(){
  tos = nullptr;
}

virtual Stack<T>::~StackInterface() {

}

virtual bool Stack<T>::isEmpty() const {
  if (tos == nullptr){
    return true;
  } else {
    return false;
  }
}

virtual void Stack<T>::push(const T value) {
  Node *newNode = new Node(value);
  if (this.isEmpty == true) {
    tos = newNode;
  } else {
    newNode->setNext(tos)
    tos = newNode;
  }
}

virtual void Stack<T>::pop() throw(PreconditionViolationException) {
  if (this.isEmpty != true){
    Node *temp = tos;
    tos = tos->getNext();
    delete temp;
  } else {
    throw PreconditionViolationException("pop attempted on an empty stack");
  }
}

virtual T Stack<T>::peek() const throw(PreconditionViolationException) {
  if (this.isEmpty != true) {
    return (tos->getValue);
  } else {
    throw PreconditionViolationException("peek attempted on an empty stack");
  }
}

virtual int Stack<T>::size() const {

}

//used for testing; not a standard stack method; front of vector = top of stack;
virtual std::vector<T> toVector const {

}
