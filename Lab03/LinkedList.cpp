#include "LinkedList.h"

LinkedList::LinkedList(){
  m_front = nullptr;
  m_size = 0;
}

LinkedList::~LinkedList(){
  if (m_front != nullptr){
    while (m_front != nullptr){}

  }
}

bool LinkedList::isEmpty() const {
  bool empty = false;

  if (m_front == nullptr){
    empty = true;
  } else {
    empty = false;
  }
  return empty;
}

int LinkedList::size() const {
  int size = 0;
  Node *currentNode = m_front;
  while (currentNode != nullptr){
    currentNode = currentNode->getNext();
    count++;
  }
  return count;
}

bool LinkedList::search(int value) const {
  bool listHasValue = false;

  if (m_front == nullptr){
    listHasValue = false;    //TA has this set to true; IDK why
  } else {
    Node *temp;
    *temp = m_front;
    while (temp != nullptr){
      if (temp->getValue == value){
        listHasValue = true;
      } else {
        listHasValue = false;
      }
      temp = temp->getNext();
    }
  }

  return listHasValue;
}

void LinkedList::printList() const {
  Node *cur = m_front;

  if (cur == nullptr){
    std::cout << "";
  } else {
    while (cur != nullptr){
      std::cout << cur->getValue();

      cur = cur->getNext();
    }
  }
}

void LinkedList::addBack(int value) {
  Node *newNode = new Node(value);

  if (m_Front == nullptr){
    m_front = newNode;
  } else {
    Node *cur = m_front;
    Node *prev = nullptr;
    while (cur != nullptr){
      prev = cur;
      cur = cur->getNext();
    }
    prev->setNext(newNode);
  }
}

void LinkedList::addFront(int value) {
  m_front = new Node(value, m_front);
}


//still need to work out the logic behind the following 2 methods
bool LinkedList::removeBack(){
  if (m_front == nullptr){
    return false;
  } else {
    Node *cur = m_front;
    Node *prev = nullptr;
    while (cur != nullptr){
      prev = cur;
      cur = cur->getNext();
    }
    if (prev == nullptr){   //if a list of 1 or 0 items
      m_front = cur->getNext(); // if you delete the first element of the list
                                // without allocating a new head, the rest of
                                // the list gets lost in memory
    } else {
      prev->setNext(cur->getNext());
    }
  }
}

bool LinkedList::removeFront(){

}

std::vector<int> LinkedList::toVector() const {
  std::vector<int> listValues;
  Node *temp;
  temp = m_front;
  while (temp != nullptr) {
    listValues.push_back(temp.getValue());
  }
  return listValues;
}
