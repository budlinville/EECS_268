#ifndef _BSTT_
#define _BSTT_

#include "BinarySearchTree.h"
#include "BinaryNode.h"

#include <string>
#include <iostream>

template<typename ItemType, typename KeyType>
class BSTTraversal {
  private:
    ofstream *outputFile;
    std::string fileName;

    void visit(ItemType& anItem) const;

    void inorderTraverse(BinaryNode<ItemType>* treePtr) const;
    void postorderTraverse(BinaryNode<ItemType>* treePtr) const;
    void preorderTraverse(BinaryNode<ItemType>* treePtr) const;

  public:
    BSTTraversal(std::string fName, BinarySearchTree<ItemType, KeyType> *BST);
    ~BSTTraversal();
};

#include "BSTTraversal.cpp"

#endif
