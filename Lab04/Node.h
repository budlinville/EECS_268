/*
File: Node.h
Author: Bud Linville
Date: February 14th, 2016
Purpose: houses a single int and a pointer to the following node

taken from lab 1 modified to become a templated version
*/

#pragma once

template <class T>
class Node<T>{
  private:
    T m_value;    //stored value of type integer
    Node* m_next;   //pointer to next node in list

  public:

    //constructors with differing parameters based on intended use
    Node();

    Node(T value, Node *nextNode);

    Node(T value);


    /*
    pre: passes an int as parameter
    post: updates m_value to new value
    */
    void setValue(T val);

    /*
    pre:
    post: returns node's m_value
    */
    int getValue() const;

    /*
    pre: passes a node in as a parameter
    post: updates node's pointer to that of the next node
    */
    void setNext(Node *prev);

    /*
    pre:
    post: returns node's m_next value
    */
    Node* getNext() const;
};
