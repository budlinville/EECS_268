#include "Node.h"

Node::Node(){
  m_value = 0;
  m_next = nullptr;
}

Node::Node(int value, Node *nextNode){
  m_value = value;
  m_next = nextNode;
}

void Node::setValue(int val){
  m_value = val;
}

int Node::getValue() const{
  return m_value;
}

void Node::setNext(Node *prev){
  m_next = prev;
}

Node* Node::getNext() const{
  return m_next;
}
