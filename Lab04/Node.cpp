/*
File: main.cpp
Author: Bud Linville
Date: February 14th, 2016
Purpose: implementation of node class
*/

#include "Node.h"

Node::Node(){
  m_next = nullptr;
}

Node::Node(T value, Node *nextNode){
  m_value = value;
  m_next = nextNode;
}

Node::Node(T value){
  m_value = value;
  m_next = nullptr;
}

void Node::setValue(T val){
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
