#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include <cctype>

#include "BinarySearchTree.h"
#include "BinaryNode.h"

class DictionaryEntry {
	private:
		std::string word;
		std::string defn;
	public:
		//consturctors with varrying paramaters
		DictionaryEntry(std::string w, std::string d): word(w), defn(d) {}

		DictionaryEntry(): word(""), defn("") {}


		//get and set methods for variables: word and defn
		void setWord(std::string inp) {
			word = inp;
		}

		std::string getWord() const {
			return word;
		}

		void setDef(std::string inp) {
			defn = inp;
		}

		std::string getDef() const {
			return defn;
		}

		/*
			@Function: overloads < operator
		*/
		bool operator<(const DictionaryEntry& rightHandSide) const {
		  int i = 0;

			std::string lhs = this->getWord();
			std::string rhs = rightHandSide.getWord();

			while ((i < signed(lhs.length())) && (i < signed(rhs.length()))) {
				if (tolower(lhs.at(i)) < tolower(rhs.at(i))) {
					return true;
				} else {
					return false;
				}
			}

			if (lhs.length() < rhs.length()) {
				return true;
			} else {
				return false;
			}

			return false;
		}
};

/*
	pre:
	post: prints text to terminal screen
	note: searches tree for a user-chosen word and prints its definition
*/
void search(BinarySearchTree<DictionaryEntry, std::string> *BST) {
	std::string userWord = "";
	bool dictContainsWord = false;
	DictionaryEntry entry;

	std::cout << "Enter word to search for: ";
	std::cin.ignore();
	std::getline(std::cin, userWord);

	userWord.at(0) = toupper(userWord.at(0));

	dictContainsWord = BST->contains(userWord);
	if (!dictContainsWord) {
		std::cout << "I'm sorry. The dictionary does not contain that word." << std::endl;
	} else {
		entry = BST->getEntry(userWord);
		std:: cout << entry.getDef() << std::endl;
	}
}

/*
	pre: depending on user intention, may or may not need to have a copy of the dictionary made before-hand
	post: prints text to a file
	@note1: user chooses file name
	@note2: user decides whether to print dictionary in pre, post, or inorder
*/
void save(BinarySearchTree<DictionaryEntry, std::string> *BST, BinarySearchTree<DictionaryEntry, std::string> *BSTcopy) {
	std::string fileName = "";
	ofstream outputFile;
	std::string dictType = "";		//will be a 1 for original or 2 for copy
	std::string inPrePost = "";  //1 == inorder	2 == preorder		3 == postorder
	BinarySearchTree<DictionaryEntry, std::string> *chosenDictionary = nullptr;

	std::cout << "Please give a name for the output file you would like to save the dictionary to (use appropriate '.txt' file extension): " << std::endl;
	std::cin >> fileName;

	std::cout << "Would you like to copy the:\n\t1) Original dictionary\n\t2) Your copy" << std::endl;
	std::cin >> dictType;

	if (dictType == "1") {
		chosenDictionary = BST;
	} else if (dictType == "2") {
		if (BSTcopy == nullptr) {
			std::cout << "I'm sorry. You must first create a copy to perform this function." << std::endl;
			return;
		} else {
			chosenDictionary = BSTcopy;
		}
	} else {
		std::cout << "Invalid input." << std::endl;
		return;
	}

	std::cout << "Would you like to print this in:\n\t1) Inorder\n\t2) Preorder\n\t3) Postorder" << std::endl;
	std::cin >> inPrePost;

	if (inPrePost != "1" && inPrePost != "2" && inPrePost != "3") {
		std::cout << "Invalid input." << std::endl;
		return;
	}

	outputFile.open(fileName);

	if (inPrePost == "1") {
		BST->inorderTraverse(chosenDictionary->getRoot(), outputFile);
	} else if (inPrePost == "2") {
		BST->preorderTraverse(chosenDictionary->getRoot(), outputFile);
	} else if (inPrePost == "3") {
		BST->postorderTraverse(chosenDictionary->getRoot(), outputFile);
	}

	outputFile.close();
}

BinarySearchTree<DictionaryEntry, std::string>* copy(std::string fileName) {
	BinarySearchTree<DictionaryEntry, std::string> *BSTcopy = new BinarySearchTree<DictionaryEntry, std::string>;

	std::ifstream inp(fileName);
	DictionaryEntry dictEntry("", "");

	std::string c = "";
	std::string line = "";

	while (inp >> c) {
		dictEntry.setWord(c);
		getline(inp, line);
		dictEntry.setDef(line);
		BSTcopy->add(dictEntry);
	}

	std::cout << "Dictionary has successfully been copied." << std::endl;

	return BSTcopy;
}

/*
	pre: dictionary copy has been made
	post: a user-chosen word has been added to dictionary copy
*/
void add(BinarySearchTree<DictionaryEntry, std::string> *BSTcopy) {
	if (BSTcopy == nullptr) {
		std::cout << "I'm sorry. You must first create a copy before performing this function." << std::endl;
	} else {
		DictionaryEntry newEntry("", "");
		std::string newWord;
		std::string newDef;

		std::cout << "Please enter a new word: ";
		std::cin.ignore();
		std::getline(std::cin, newWord);
		newWord.at(0) = toupper(newWord.at(0));

		std::cout << "Please enter a definition for the new word: ";
		std::cin.ignore();
		std::getline(std::cin, newDef);

		newEntry.setWord(newWord);
		newEntry.setDef(newDef);

		BSTcopy->add(newEntry);
	}
}

/*
pre: dictionary copy has been made
post: a user-chosen word has been removed from dictionary copy
*/
void dremove(BinarySearchTree<DictionaryEntry, std::string> *BSTcopy) {
	if (BSTcopy == nullptr) {
		std::cout << "I'm sorry. You must first create a copy before performing this function." << std::endl;
	} else {
		std::string wordToRemove = "";

		std::cout << "Please enter the word you would like to remove: ";
		std::cin >> wordToRemove;

		BSTcopy->removeWord(wordToRemove);
	}
}

/*
	A test method that tests program's ability to add words to a BST
*/
void testAdds(BinarySearchTree<DictionaryEntry, std::string> dictionary) {
	std::string word = "";
	std::string defn = "";
	DictionaryEntry newEntry("", "");

	std::cout << "Please enter a new word: ";
	std::cin.ignore();
	std::getline(std::cin, word);
	word.at(0) = toupper(word.at(0));
	newEntry.setWord(word);

	std::cout << "Please enter a definition for the new word: ";
	std::cin.ignore();
	std::getline(std::cin, defn);
	defn = " " + defn;	//formatted like all other entries
	newEntry.setDef(defn);

	dictionary.add(newEntry);

	BinaryNode<DictionaryEntry>* tempPtr = dictionary.getNodeWith(word);
	dictionary.inorderPrint(tempPtr);
}

/*
	A test method that tests program's ability to remove words to a BST
*/
void testRemoves(BinarySearchTree<DictionaryEntry, std::string> dictionary) {
	std::string wordToRemove = "";

	std::cout << "Please enter a word you would like to remove: ";
	std::cin.ignore();
	std::getline(std::cin, wordToRemove);
	wordToRemove.at(0) = toupper(wordToRemove.at(0));

	BinaryNode<DictionaryEntry>* tempPtr = dictionary.getNodeWith(wordToRemove);
	dictionary.removeWord(wordToRemove);

	dictionary.inorderPrint(tempPtr);
}

/*
	A test method that tests program's ability to write words from a BST to a file in inorder
*/
void testWriteToFile(BinarySearchTree<DictionaryEntry, std::string> dictionary) {
	std::string fileName = "";
	ofstream outputFile;

	std::cout << "Please give a name for the output file you would like to save the dictionary to (use appropriate '.txt' file extension): " << std::endl;
	std::cin >> fileName;

	outputFile.open(fileName);

	dictionary.inorderTraverse(dictionary.getRoot(), outputFile);
}

/*
	main function for program - initialises BST
	@note: handles what the user intends to do and then directs functionality to other methods accordingly
*/
int main(int argc, char* argv[]) {
	std::string fileName = argv[1];
	std::ifstream inp(fileName);
	std::string fileInput = "";
	std::string line = "";
	DictionaryEntry dictEntry("", "");
	bool stopLooping = false;
	int userChoice = 0;
	int testChoice = 0;
	//bool validInput = false;
	BinarySearchTree<DictionaryEntry, std::string> *dictBST = new BinarySearchTree<DictionaryEntry, std::string>;
	BinarySearchTree<DictionaryEntry, std::string> *dictCopy = nullptr;

	std::string c = "";
	while (inp >> c) {
		dictEntry.setWord(c);
		getline(inp, line);
		dictEntry.setDef(line);
		dictBST->add(dictEntry);
	}

	while (!stopLooping) {
		std::cout << "Please enter the number corresponding to the intended action: " << std::endl;
		std::cout << "\t1) Search \n\t2) Save\n\t3) Copy\n\t4) Add\n\t5) Remove\n\t6) Test\n\t7) Quit\n" << std::endl;

		std::cin >> userChoice;

		switch (userChoice) {
			case 1 : search(dictBST); break;
			case 2 : save(dictBST, dictCopy); break;
			case 3 : dictCopy = copy(argv[1]); break;
			case 4 : add(dictCopy); break;
			case 5 : dremove(dictCopy); break;
			case 6 : std::cout << "Would you like to:\n\t1) Test Adds\n\t2) Test Removes\n\t3) Test Write to File" << std::endl;
							 std::cin >> testChoice;
							 switch (testChoice) {
								 case 1 : testAdds(dictBST); break;
								 case 2 : testRemoves(dictBST); break;
								 case 3 : testWriteToFile(dictBST); break;
								 default : std::cout << "Improper input." << std::endl; break;
							 }; break;
			case 7 : stopLooping = true; break;
			default : std::cout << "Improper input." << std::endl; break;
		}

	}
	return 0;
};
