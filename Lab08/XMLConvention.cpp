/*
File: XMLConvention.cpp
Author: Bud Linville
Date: March 27th, 2016
Purpose: Implementation of XMLConvention.h
*/

#include "XMLConvention.h"

XMLConvention::XMLConvention() {
  XMLPieces = nullptr;
  numPieces = 0;
}

XMLConvention::~XMLConvention() {
  for (int i = 0; i < numPieces; i++) {
    delete XMLPieces;
  }
}

bool XMLConvention::isValidTag(std::string inp) {
  std::string validTags[6] = {"<tab>", "<p>", "<listItem>", "</tab>", "</p>", "</listItem>"};

  for (int i = 0; i < 6; i++) {
    if (inp == validTags[i]) {
      return true;
    }
  }

  return false;
}

bool XMLConvention::isValidCharacter(char c) {
  if (c >= '0' && c <= '9') {
    return true;
  } else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
    return true;
  } else if (c == ' ' || c == '\n' || c == '\t') {
    return true;
  } else {
    for (int i = 0; i < 14; i++) {
      if (c == specialChar[i]) {
        return true;
      }
    }
  }

  return false;
}

bool XMLConvention::isValidXML(std::string XMLChunk) throw (PrecondViolatedExcep){
  XMLPieces = getStringPieces(XMLChunk);
  Stack<std::string> tagStack;

  for (int i = 0; i < numPieces; i++) {
    if (XMLPieces[i] == "<p>" || XMLPieces[i] == "<tab>" || XMLPieces[i] == "<listItem>") {
      tagStack.push(XMLPieces[i]);
    } else if (XMLPieces[i] == "</p>") {
      if (tagStack.peek() != "<p>") {
        throw PrecondViolatedExcep("Invalid XML file: Unexpected closing tab encountered.");
      }
      tagStack.pop();
    } else if (XMLPieces[i] == "</tab>") {
      if (tagStack.peek() != "<tab>") {
        throw PrecondViolatedExcep("Invalid XML file: Unexpected closing tab encountered.");
      }
      tagStack.pop();
    } else if (XMLPieces[i] == "</listItem>") {
      if (tagStack.peek() != "<listItem>") {
        throw PrecondViolatedExcep("Invalid XML file: Unexpected closing tab encountered.");
      }
      tagStack.pop();
    }
  }

  if (tagStack.isEmpty() != true) {
    throw PrecondViolatedExcep("Invalid XML file: Imbalance between number of opening and closing tabs.");
  }

  return true;
}

std::string* XMLConvention::getStringPieces(std::string chunk) {
  for (int i = 0; i < signed (chunk.length()); i++) {
    if (chunk.at(i) == ' ') {
      numPieces ++;
    }
  }

  std::string *stringPieces = new string[numPieces];

  for (int i = 0; i < numPieces; i++) {     //initialize
    stringPieces[i] = "";
  }

  //could potentially result in seg fault
  for (int i = 0; i < numPieces; i++) {
    int numElementsToDelete = chunk.find(" ", 1);
    stringPieces[i] = chunk.substr(0, numElementsToDelete);
    chunk.erase(0, numElementsToDelete);
    stringPieces[i].erase(0, 1);     //need to erase " " before every element
  }

  return stringPieces;
}

void XMLConvention::printXML() {
  int numTabs = 0;
  bool listItem = false;
  bool previousPieceWasText = false;

  for (int i = 0; i < numPieces; i++) {
    std::cout << XMLPieces[i] << std::endl;
  }

  for (int i = 0; i < numPieces; i++) {
    if (XMLPieces[i] == "<tab>") {
      numTabs++;
      previousPieceWasText = false;
    } else if (XMLPieces[i] == "</p>") {
      std::cout << "\n";
      previousPieceWasText = false;
    } else if (XMLPieces[i] == "<listItem>") {
      std::cout << "\n";
      listItem = true;
      previousPieceWasText = false;
    } else if (XMLPieces[i] == "</listItem>") {
      std::cout << "\n";
      previousPieceWasText = false;
    } else if (XMLPieces[i] == "</tab>") {
      numTabs--;
      previousPieceWasText = false;
    } else if (XMLPieces[i] == "<p>") {
      //nothing
      previousPieceWasText = false;
    } else {
      if (previousPieceWasText == false) {
        for (int i = 0; i < numTabs; i++) {
          std::cout << "\t";
        }
      }

      if (listItem) {
        std::cout << "*" << XMLPieces[i] << " ";
        listItem = false;
      } else {
        std::cout << XMLPieces[i] << " ";
      }

      previousPieceWasText = true;
    }
  }

  std::cout << std::endl;
}
