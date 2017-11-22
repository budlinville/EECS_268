/*
File: Stack.hpp
Author: Bud Linville
Date: February 22nd, 2016
Purpose: implementation of stack class
*/

template<typename T>
Stack<T>::Stack() {
  tos = nullptr;
}

template<typename T>
Stack<T>::~Stack() {
  Node<T> *tempTos = tos;
  while(tos != nullptr){
    tempTos = tos;
    tos = tos->getNext();
    delete tempTos;
  }
}

template<typename T>
bool Stack<T>::isEmpty() const {
  return(tos == nullptr);
}

template<typename T>
void Stack<T>::push(const T &value) throw (PrecondViolatedExcep){
  Node<T> *newNode = new Node<T>(value);
  if (this->isEmpty() == true) {
    tos = newNode;
  } else {
    newNode->setNext(tos);
    tos = newNode;
  }
}

template<typename T>
void Stack<T>::pop() throw(PrecondViolatedExcep) {
  if (this->isEmpty() != true){
    Node<T> *temp = tos;
    tos = tos->getNext();
    delete temp;
  } else {
    throw PrecondViolatedExcep("pop attempted on an empty stack");
  }
}

template<typename T>
T Stack<T>::peek() const throw(PrecondViolatedExcep) {
  if (this->isEmpty() != true) {
    return (tos->getValue());
  } else {
    throw PrecondViolatedExcep("peek attempted on an empty stack");
  }
}

template<typename T>
Node<T>* Stack<T>::nextNode() const throw (PrecondViolatedExcep) {
  if (tos == nullptr){
    throw PrecondViolatedExcep("nextNode attempted on too small of a Stack.");
  } else {
    return tos->getNext();
  }
}

template<typename T>
T Stack<T>::nextValue() const throw (PrecondViolatedExcep) {
  if (tos == nullptr){
    throw PrecondViolatedExcep("nextNode attempted on too small of a Stack.");
  } else {
    Node<T>* nextNode = tos->getNext();
    return nextNode->getValue();
  }
}
