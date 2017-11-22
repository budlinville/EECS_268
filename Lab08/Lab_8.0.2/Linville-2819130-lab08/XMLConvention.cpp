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

void XMLConvention::checkValidTag(std::string inp) throw (PrecondViolatedExcep){
  std::cout << "[Checking for a valid tag]" << std::endl;

  bool validTag = false;

  for (int i = 0; i < 6; i++) {
    if (inp == validTags[i]) {
      validTag = true;
    }
  }
  if (!validTag) {
    throw PrecondViolatedExcep("Invalid tags!");
  }
}

bool XMLConvention::isXML(std::string XMLChunk) throw (PrecondViolatedExcep){
  std::cout << "[Recursing to check XML syntax]" << std::endl;

  std::string openingTag = "";
  std::string expectedTag = "";
  std::string possibleClosingTag = "";
  int endPos = 0;
  std::string *chunkReference = &XMLChunk;
  bool validXML = true;

  if (XMLChunk == "") {   //possible base case
    return true;
  }

  for (int i = 0; i < signed(XMLChunk.length()); i++) {
    if (XMLChunk.at(i) == '<') {
      openingTag = getTag(i, chunkReference);

      if (openingTag.at(1) == '/') {
        throw PrecondViolatedExcep("Unexpected closing tag!");
      } else {
        expectedTag = openingTag;
        expectedTag.insert(1, "/");
      }

      checkValidTag(openingTag);
      checkWhiteSpaceAroundTags(chunkReference, (i - 1), (i + openingTag.length()));

      i = i + openingTag.length();

      int numSameTags = 0;

      for (int j = i; j < signed(XMLChunk.length()); j++) {
        if (XMLChunk.at(j) == '<') {
          possibleClosingTag = getTag(j, chunkReference);

          if (possibleClosingTag == openingTag) {
            numSameTags ++;
          } else if ((possibleClosingTag == expectedTag) && (numSameTags != 0)) {
            numSameTags --;
          } else if ((possibleClosingTag == expectedTag) && (numSameTags == 0)) {
            checkWhiteSpaceAroundTags(chunkReference, (j - 1), (j + possibleClosingTag.length()));
            endPos = j;
            j = XMLChunk.length();    //end loop
          }
        }
      }

      std::string newChunk = XMLChunk;
      newChunk.erase((endPos - 1), (XMLChunk.length() - endPos)).erase(i - openingTag.length(), openingTag.length() + 1);
      i = endPos + possibleClosingTag.length();
      validXML = isXML(newChunk);
      if (validXML == false) {
        return false;
      }
    } else {
      validXML = isValidCharacter(XMLChunk.at(i));
      if (validXML == false) {
        return false;
      }
    }
  }
  return true;
}

std::string XMLConvention::getTag(int startingPos, std::string *chunk) {
  std::cout << "[Extracting tag from string]" << std::endl;

  std::string tag = "<";
  int i = startingPos;
  while (chunk->at(i) != '>') {
    i++;
    tag += chunk->at(i);
  }

  return tag;
}

void XMLConvention::checkWhiteSpaceAroundTags(std::string *chunk, int pre, int post) throw (PrecondViolatedExcep) {
  std::cout << "[Checking white space surrounding tags]" << std::endl;

  bool hasWhiteSpaceAroundTags = false;
  char whiteSpace[3] = {' ', '\n', '\t'};

  if (pre < 0) {
    for (int i = 0; i < 3; i++) {
      if (chunk->at(post) == whiteSpace[i]) {
        hasWhiteSpaceAroundTags = true;
        i = 3; //ends loop
      }
    }
  } else if (post >= signed(chunk->length())) {
    for (int i = 0; i < 3; i++) {
      if (chunk->at(pre) == whiteSpace[i]) {
        hasWhiteSpaceAroundTags = true;
        i = 3; //ends loop
      }
    }
  } else {
    for (int i = 0; i < 3; i++) {
      if (chunk->at(pre) == whiteSpace[i]) {
        for (int j = 0; j < 3; j++) {
          if (chunk->at(post) == whiteSpace[j]) {
            hasWhiteSpaceAroundTags = true;
            i = 3;
            j = 3;
          }
        }
      }
    }
  }
  if (hasWhiteSpaceAroundTags == false) {
    throw PrecondViolatedExcep("Missing white space surrounding tag!");
  }
}

//because im reading in file character by character, I don't really need the recursive method that checks for valid text
bool XMLConvention::isValidCharacter(char c) {
  std::cout << "[Valid Character Check]" << std::endl;

  if (isDigit(c) == true) {
    return true;
  } else if (isLetter(c) == true) {
    return true;
  } else if (isSpecial(c) == true) {
    return true;
  }

  return false;
}

bool XMLConvention::isDigit(char c) {
  std::cout << "[Checking if Digit]" << std::endl;

  return (c >= '0' && c <= '9');
}

bool XMLConvention::isLetter(char c) {
  std::cout << "[Checking if Letter]" << std::endl;

  return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

bool XMLConvention::isSpecial(char c) {
  std::cout << "[Checking if Special Character]" << std::endl;

  for (int i = 0; i < 14; i++) {
    if (c == specialChar[i]) {
      return true;
    }
  }
  return isWhiteSpace(c);
}

bool XMLConvention::isWhiteSpace(char c) {
  std::cout << "[Checking if Whitespace]" << std::endl;

  return (c == ' ' || c == '\n' || c == '\t');
}

void XMLConvention::printXML(std::string XMLChunk) {
  std::cout << "[Printing XML File]" << std::endl;

  int numTabs = 0;
  bool listItem = false;
  bool previousPieceWasText = false;
  XMLPieces = getStringPieces(XMLChunk);

  std::cout << "\n" << std::endl;

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
