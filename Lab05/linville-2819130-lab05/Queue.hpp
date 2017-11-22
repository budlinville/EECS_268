/*
File: Queue.hpp
Author: Bud Linville
Date: February 28th 2016
Purpose: implementation of queue
*/

template <typename T>
Queue<T>::Queue() {
  front = nullptr;
  rear = nullptr;
}

template <typename T>
Queue<T>::~Queue() {
  Node<T> *tempNode = nullptr;
  while(rear != nullptr){
    tempNode = rear;
    rear = rear->getNext();
    delete tempNode;
  }
}

template <typename T>
bool Queue<T>::isEmpty() const {
  return (front == nullptr);
}

template <typename T>
void Queue<T>::enqueue(const T &value) throw (PrecondViolatedExcep) {
  Node<T> *newItem = new Node<T>(value);
  if (newItem == nullptr) {
    throw PrecondViolatedExcep("Heap memory full"); //unlikely but should be accounted for all the same
  } else {
    if (rear == nullptr) {
      rear = newItem;
      front = newItem;
    } else {
      newItem->setNext(rear);
      rear = newItem;
    }
  }
}

template <typename T>
void Queue<T>::dequeue() throw (PrecondViolatedExcep) {
  if (rear == nullptr) {
    throw PrecondViolatedExcep("dequeue attempted on an empty queue");
  } else {
    Node<T> *h = front;
    front = front->getNext();
    delete h;
    if (front == nullptr) {
      rear = nullptr;
    }
  }
}

template <typename T>
T Queue<T>::peekFront() const throw (PrecondViolatedExcep) {
  if (front == nullptr) {
    throw PrecondViolatedExcep("peekFront attempted on an empty queue");
  } else {
    return front->getValue();
  }
}

template <typename T>
Node<T>* Queue<T>::nextNode() const throw (PrecondViolatedExcep) {
  if (front == nullptr) {
    throw PrecondViolatedExcep("nextNode attempted on too small of a queue.");
  } else if (front == rear) {
    return nullptr;
  } else {
    Node<T>* tempNode = rear;
    while (tempNode->getNext() != front) {
      tempNode = tempNode->getNext();
    }
    return tempNode;
  }
}

template <typename T>
T Queue<T>::nextValue() const throw (PrecondViolatedExcep) {
  if (front == nullptr) {
    throw PrecondViolatedExcep("nextNode attempted on too small of a queue.");
  } else if (front == rear) {
    return nullptr;
  } else {
    Node<T>* tempNode = rear;
    while (tempNode->getNext() != front) {
      tempNode = tempNode->getNext();
    }
    return tempNode->getValue();
  }
}
