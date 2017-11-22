//  Subsetted from:
//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** @file BinarySearchTree.cpp */

#include "BinarySearchTree.h"

// PRIVATE HELPER METHODS - IMPLEMENT THESE

template<typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::destroyTree(BinaryNode<ItemType>* subTreePtr) {
  if(subTreePtr != nullptr) {
    destroyTree(subTreePtr->getLeftChildPtr());
    destroyTree(subTreePtr->getRightChildPtr());
    delete subTreePtr;
  }
}

template<typename ItemType, typename KeyType>
//BinaryNode<ItemType>*
void BinarySearchTree<ItemType,KeyType>::insertInorder(BinaryNode<ItemType>* subTreePtr,
                                                                        BinaryNode<ItemType>* newNodePtr) {
  if (subTreePtr->getItem().operator<(newNodePtr->getItem())) {
    if (subTreePtr->getRightChildPtr() == nullptr) {
      subTreePtr->setRightChildPtr(newNodePtr);
    } else {
      insertInorder(subTreePtr->getRightChildPtr(), newNodePtr);
    }
  } else {
    if (subTreePtr->getLeftChildPtr() == nullptr) {
      subTreePtr->setLeftChildPtr(newNodePtr);
    } else {
      insertInorder(subTreePtr->getLeftChildPtr(), newNodePtr);
    }
  }
}

template<typename ItemType, typename KeyType>
BinaryNode<ItemType>* BinarySearchTree<ItemType, KeyType>::findNode(
				BinaryNode<ItemType>* subTreePtr, const KeyType& target) const {

  ItemType item(target, "");

  if (subTreePtr == nullptr) {    //base case 1.... failure case
    return nullptr;
  } else if (subTreePtr->getItem().getWord() == target) {  //base case 2...found target
    return subTreePtr;
  } else if (subTreePtr->getItem() < item) {
    return findNode(subTreePtr->getRightChildPtr(), target);
  } else {
    return findNode(subTreePtr->getLeftChildPtr(), target);
  }
}

//////////////////////////////////////////////////////////////
//      PUBLIC METHODS BEGIN HERE
//////////////////////////////////////////////////////////////

template<typename ItemType, typename KeyType>
BinarySearchTree<ItemType, KeyType>::BinarySearchTree() : rootPtr(nullptr) {
}

/*
  Copy Constructor: for making an object using a previously declared object of the class
*/
template<typename ItemType, typename KeyType>
BinarySearchTree<ItemType, KeyType>::BinarySearchTree(BinarySearchTree<ItemType, KeyType>* &treePtr) {
  rootPtr = copyTree(treePtr->getRoot());
}

template<typename ItemType, typename KeyType>
BinarySearchTree<ItemType, KeyType>::~BinarySearchTree() {
   this->destroyTree(rootPtr); // Call inherited method
}  // end destructor

template<typename ItemType, typename KeyType>
BinaryNode<ItemType>* BinarySearchTree<ItemType, KeyType>::copyTree(BinaryNode<ItemType>* bNode) {
	if (bNode == nullptr) {
		return nullptr;
	} else {
    BinaryNode<ItemType>* tempNode = new BinaryNode<ItemType>(bNode->getItem());

    tempNode->setRightChildPtr(copyTree(bNode->getRightChildPtr()));
  	tempNode->setLeftChildPtr(copyTree(bNode->getLeftChildPtr()));

  	return tempNode;
  }
}


//////////////////////////////////////////////////////////////
//      Public BinaryTreeInterface Methods Section - IMPLEMENT THESE
//////////////////////////////////////////////////////////////

template<typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::add(const ItemType& newData) {
  BinaryNode<ItemType> *newNodePtr = new BinaryNode<ItemType>(newData);

  if (rootPtr == nullptr) {   //base case
    rootPtr = newNodePtr;
  } else {
    insertInorder(rootPtr, newNodePtr);
  }
}

template<typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::removeWord(const KeyType& word) {
  BinaryNode<ItemType>* nodeToDelete = findNode(rootPtr, word);

  BinaryNode<ItemType>* replacementNode = findReplacementNode(nodeToDelete->getRightChildPtr(), true);

  if (replacementNode == nullptr) {
    if (nodeToDelete->getLeftChildPtr() != nullptr) {
      nodeToDelete->setItem(nodeToDelete->getLeftChildPtr()->getItem());
      nodeToDelete->setLeftChildPtr(nodeToDelete->getLeftChildPtr()->getLeftChildPtr());
      nodeToDelete->setRightChildPtr(nodeToDelete->getLeftChildPtr()->getRightChildPtr());
      delete nodeToDelete->getLeftChildPtr();
    } else {                //would be a leaf in this case
      delete nodeToDelete;
    }
  } else {
    nodeToDelete->setItem(replacementNode->getItem());
    if (replacementNode->getRightChildPtr() != nullptr) {
      BinaryNode<ItemType>* tempNode = nodeToDelete->getRightChildPtr();
      while (tempNode->getLeftChildPtr() != replacementNode) {
        tempNode = tempNode->getLeftChildPtr();
      }

      tempNode->setLeftChildPtr(replacementNode->getRightChildPtr());
    }

    delete replacementNode;
  }
}

template<typename ItemType, typename KeyType>
BinaryNode<ItemType>* BinarySearchTree<ItemType, KeyType>::findReplacementNode(BinaryNode<ItemType>* treePtr, bool firstIteration) {
  if (treePtr == nullptr && firstIteration == true) {    //initial call has no right child pointer
    return nullptr;
  } else if (treePtr->getLeftChildPtr() == nullptr) {
    return treePtr;
  } else {
    return findReplacementNode(treePtr->getLeftChildPtr(), false);
  }
}


template<typename ItemType, typename KeyType>
ItemType BinarySearchTree<ItemType, KeyType>::getEntry(const KeyType& aKey) const throw(NotFoundException) {
  BinaryNode<ItemType>* foundItemPtr = nullptr;
  foundItemPtr = findNode(rootPtr, aKey);
  if (foundItemPtr == nullptr) {
    throw NotFoundException("Entry was not found.");
  } else {
    return foundItemPtr->getItem();
  }
}

template<typename ItemType, typename KeyType>
BinaryNode<ItemType>* BinarySearchTree<ItemType, KeyType>::getNodeWith(const KeyType& aKey) const throw(NotFoundException) {
  BinaryNode<ItemType>* foundItemPtr = nullptr;
  foundItemPtr = findNode(rootPtr, aKey);
  if (foundItemPtr == nullptr) {
    throw NotFoundException("Entry was not found.");
  } else {
    return foundItemPtr;
  }
}

template<typename ItemType, typename KeyType>
bool BinarySearchTree<ItemType, KeyType>::contains(const KeyType& aKey) const {
  BinaryNode<ItemType>* foundItemPtr = nullptr;
  foundItemPtr = findNode(rootPtr, aKey);
  if (foundItemPtr == nullptr) {
    return false;
  } else {
    return true;
  }
}
template<typename ItemType, typename KeyType>
BinaryNode<ItemType>* BinarySearchTree<ItemType, KeyType>::getRoot() const{
  return rootPtr;
}

//////////////////////////////////////////////////////////////
//      Public Traversals Section - IMPLEMENT THESE
//////////////////////////////////////////////////////////////

template<typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::inorderTraverse(BinaryNode<ItemType>* treePtr, ofstream& fileStream) const {
   if (treePtr != nullptr) {

     inorderTraverse(treePtr->getLeftChildPtr(), fileStream);
     fileStream << treePtr->getItem().getWord() << treePtr->getItem().getDef() << std::endl;
     inorderTraverse(treePtr->getRightChildPtr(), fileStream);
   }
}

template<typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::postorderTraverse(BinaryNode<ItemType>* treePtr, ofstream& fileStream) const {
  if (treePtr != nullptr) {
    postorderTraverse(treePtr->getLeftChildPtr(), fileStream);
    postorderTraverse(treePtr->getRightChildPtr(), fileStream);
    fileStream << treePtr->getItem().getWord() << treePtr->getItem().getDef() << std::endl;
  }
}

template<typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::preorderTraverse(BinaryNode<ItemType>* treePtr, ofstream& fileStream) const {
  if (treePtr != nullptr) {
    fileStream << treePtr->getItem().getWord() << treePtr->getItem().getDef() << std::endl;
    preorderTraverse(treePtr->getLeftChildPtr(), fileStream);
    preorderTraverse(treePtr->getRightChildPtr(), fileStream);
  }
}

template<typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::inorderPrint(BinaryNode<ItemType>* treePtr) const{
	if (treePtr != nullptr) {
		inorderPrint(treePtr->getLeftChildPtr());
    std::cout << treePtr->getItem().getWord() << treePtr->getItem().getDef() << std::endl;
    inorderPrint(treePtr->getRightChildPtr());
  }
}
