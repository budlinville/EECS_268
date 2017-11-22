/*
File: Stack.cpp
Author: Bud Linville
Date: February 21st, 2016
Purpose: implementation of stack class
*/

template<typename T>
Stack<T>::Stack() {
  tos = nullptr;
  stackSize = 0;
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
void Stack<T>::push(const T value) {
  Node<T> *newNode = new Node<T>(value);
  if (this->isEmpty() == true) {
    tos = newNode;
  } else {
    newNode->setNext(tos);
    tos = newNode;
  }

  stackSize++;
}

template<typename T>
void Stack<T>::pop() throw(PreconditionViolationException) {
  if (this->isEmpty() != true){
    Node<T> *temp = tos;
    tos = tos->getNext();
    delete temp;
    stackSize--;
  } else {
    throw PreconditionViolationException("pop attempted on an empty stack");
  }
}

template<typename T>
T Stack<T>::peek() const throw(PreconditionViolationException) {
  if (this->isEmpty() != true) {
    return (tos->getValue());
  } else {
    throw PreconditionViolationException("peek attempted on an empty stack");
  }
}

template<typename T>
int Stack<T>::size() const {
  return(stackSize);
}

//used for testing; not a standard stack method; front of vector = top of stack;

template<typename T>
std::vector<T> Stack<T>::toVector() const {
  std::vector<int> listValues;
  Node<T> *temp;
  temp = tos;
  while (temp->getNext() != nullptr) {
    listValues.push_back(temp->getValue());
    temp = temp->getNext();
  }
  return listValues;
}


