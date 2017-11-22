#include <iostream>
#include <string>

#include "BinarySearchTree.h"

class DictionaryEntry
{
private:
	std::string word;
	std::string defn;
public:
	DictionaryEntry(std::string w, std::string d): word(w), defn(d)
	{}
};

int main(int argc, char* argv[])
{
	BinarySearchTree<DictionaryEntry, std::string> bst;
	DictionaryEntry de("rock", "a hard object often found on the ground");
	bst.add(de);
	return 0;
}