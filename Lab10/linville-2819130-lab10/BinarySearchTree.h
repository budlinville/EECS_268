//  Subsetted from:
//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

// Listing 16-4.

/** Link-based implementation of the ADT binary search tree.
 @file BinarySearchTree.h */

#ifndef _BINARY_SEARCH_TREE
#define _BINARY_SEARCH_TREE

#include "BinaryNode.h"
#include "NotFoundException.h"
#include <iostream>
#include <fstream>

template<typename ItemType, typename KeyType>
class BinarySearchTree
{
private:
   BinaryNode<ItemType>* rootPtr;

   // Recursively deletes all nodes from the tree.
   void destroyTree(BinaryNode<ItemType>* subTreePtr);

   // Recursively finds where the given node should be placed and
   // inserts it in a leaf at that point.
   //BinaryNode<ItemType>*
   void insertInorder(BinaryNode<ItemType>* subTreePtr,
                                       BinaryNode<ItemType>* newNode);

   // Returns a pointer to the node containing the given value,
   // or nullptr if not found.
   BinaryNode<ItemType>* findNode(BinaryNode<ItemType>* treePtr,
                                  const KeyType& target) const;

   /*
    @pre: tree has all nodes
    @post: at last call of this recursive method, tree still has all nodes
    @note: a recursive method used in the process of removind a node
    @return: returns a node that may or may not be removed depending on certain conditions found in removeWord() method
   */
   BinaryNode<ItemType>* findReplacementNode(BinaryNode<ItemType>* treePtr, bool firstIteration);

public:
   //------------------------------------------------------------
   // Constructor and Destructor Section.
   //------------------------------------------------------------
   BinarySearchTree();

   //copy constructor
   BinarySearchTree(BinarySearchTree<ItemType, KeyType>* &b);
   virtual ~BinarySearchTree();

   //------------------------------------------------------------
   // Public Methods Section.
   //------------------------------------------------------------
   void add(const ItemType& newEntry);

   /*
    @pre: tree has all nodes
    @post: tree now had one fewer node
  */
   void removeWord(const KeyType& word);

   /*
   @pre:
   @post:
   @returns: value of type ItemType based on value of type KeyType passed in as paramater
   */
   ItemType getEntry(const KeyType& aKey) const throw(NotFoundException);

   /*
    @Note: exact same as getEntry() but returns the actual node that houses value of
           type ItemType as opposed to returning the value of type ItemType
   */
   BinaryNode<ItemType>* getNodeWith(const KeyType& aKey) const throw(NotFoundException);

   /*
   pre:
   post:
   @returns: boolean value corresponding to whether or not the BST has a node with KeyType aKey
   */
   bool contains(const KeyType& aKey) const;
   BinaryNode<ItemType>* getRoot() const;
   BinaryNode<ItemType>* copyTree(BinaryNode<ItemType>* bNode);


   //------------------------------------------------------------
   // Public Traversals Section.
   //------------------------------------------------------------
   void inorderTraverse(BinaryNode<ItemType>* treePtr, ofstream& fileStream) const;
   void postorderTraverse(BinaryNode<ItemType>* treePtr, ofstream& fileStream) const;
   void preorderTraverse(BinaryNode<ItemType>* treePtr, ofstream& fileStream) const;

   /*
    pre:
    post: exact same as inorderTraverse except that it prints to terminal screen as opposed to a seperate file
   */
   void inorderPrint(BinaryNode<ItemType>* treePtr) const;
}; // end BinarySearchTree

#include "BinarySearchTree.cpp"

#endif
