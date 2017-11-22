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

   BinaryNode<ItemType>* findReplacementNode(BinaryNode<ItemType>* treePtr, bool firstIteration);

public:
   //------------------------------------------------------------
   // Constructor and Destructor Section.
   //------------------------------------------------------------
   BinarySearchTree();
   BinarySearchTree(BinarySearchTree<ItemType, KeyType>* &b);
   virtual ~BinarySearchTree();

   //------------------------------------------------------------
   // Public Methods Section.
   //------------------------------------------------------------
   void add(const ItemType& newEntry);
   void removeWord(const KeyType& word);
   ItemType getEntry(const KeyType& aKey) const throw(NotFoundException);
   BinaryNode<ItemType>* getNodeWith(const KeyType& aKey) const throw(NotFoundException);
   bool contains(const KeyType& aKey) const;
   BinaryNode<ItemType>* getRoot() const;
   BinaryNode<ItemType>* copyTree(BinaryNode<ItemType>* bNode);


   //------------------------------------------------------------
   // Public Traversals Section.
   //------------------------------------------------------------
   void inorderTraverse(BinaryNode<ItemType>* treePtr, ofstream& fileStream) const;
   void postorderTraverse(BinaryNode<ItemType>* treePtr, ofstream& fileStream) const;
   void preorderTraverse(BinaryNode<ItemType>* treePtr, ofstream& fileStream) const;
   void inorderPrint(BinaryNode<ItemType>* treePtr) const;
}; // end BinarySearchTree

#include "BinarySearchTree.cpp"

#endif
