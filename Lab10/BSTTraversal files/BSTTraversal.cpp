template<typename ItemType, typename KeyType>
BSTTraversal<ItemType, KeyType>::BSTTraversal(std::string fileName, BinarySearchTree<ItemType, KeyType> *BST) {
  outputFile = new ofstream(fileName.c_str());
  int inPrePost = 0;
  BinaryNode<ItemType>* rootPtr = BST->getRoot();

  std::cout << "Would you like to print this in:\n\t1) Inorder\n\t2) Preorder3) Postorder" << std::endl;
	std::cin >> inPrePost;

	if (inPrePost == 1) {
		inorderTraverse(rootPtr);
	} else if (inPrePost == 2) {
		preorderTraverse(rootPtr);
	} else if (inPrePost == 3) {
		postorderTraverse(rootPtr);
	}
}

template<typename ItemType, typename KeyType>
BSTTraversal<ItemType, KeyType>::~BSTTraversal() {
  outputFile->close();
}

template<typename ItemType, typename KeyType>
void BSTTraversal<ItemType, KeyType>::visit(ItemType& anItem) const{
  std::string word = anItem.getWord();
  std::string def = anItem.getDef();

  outputFile << word << def << std::endl;
}
/*
template<typename ItemType, typename KeyType>
void BSTTraversal<ItemType, KeyType>::inorderTraverse(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const {
   if (treePtr != nullptr) {
     inorderTraverse(visit, treePtr->getLeftChildPtr());
     BSTTraversal<typename ItemType, typename KeyType>::visit(treePtr.getItem());
     inorderTraverse(visit, treePtr->getRightChildPtr());
   }
}

template<typename ItemType, typename KeyType>
void BSTTraversal<ItemType, KeyType>::postorderTraverse(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const {
  if (treePtr != nullptr) {
    postorderTraverse(visit, treePtr->getLeftChildPtr());
    postorderTraverse(visit, treePtr->getRightChildPtr());
    BSTTraversal<typename ItemType, typename KeyType>::visit(treePtr.getItem());
  }
}

template<typename ItemType, typename KeyType>
void BSTTraversal<ItemType, KeyType>::preorderTraverse(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const {
  if (treePtr != nullptr) {
    BSTTraversal<typename ItemType, typename KeyType>::visit(treePtr.getItem());
    preorderTraverse(visit, treePtr->getLeftChildPtr());
    preorderTraverse(visit, treePtr->getRightChildPtr());
  }
}
*/

template<typename ItemType, typename KeyType>
void BSTTraversal<ItemType, KeyType>::inorderTraverse(BinaryNode<ItemType>* treePtr) const {
   if (treePtr != nullptr) {
     inorderTraverse(treePtr->getLeftChildPtr());
     visit(treePtr->getItem());
     inorderTraverse(treePtr->getRightChildPtr());
   }
}

template<typename ItemType, typename KeyType>
void BSTTraversal<ItemType, KeyType>::postorderTraverse(BinaryNode<ItemType>* treePtr) const {
  if (treePtr != nullptr) {
    postorderTraverse(treePtr->getLeftChildPtr());
    postorderTraverse(treePtr->getRightChildPtr());
    visit(treePtr->getItem());
  }
}

template<typename ItemType, typename KeyType>
void BSTTraversal<ItemType, KeyType>::preorderTraverse(BinaryNode<ItemType>* treePtr) const {
  if (treePtr != nullptr) {
    visit(treePtr->getItem());
    preorderTraverse(treePtr->getLeftChildPtr());
    preorderTraverse(treePtr->getRightChildPtr());
  }
}
