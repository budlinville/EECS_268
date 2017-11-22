/*
File: XMLConvention.h
Author: Bud Linville
Date: March 27th, 2016
Purpose: houses methods for checking whether or not a file uses conventional XML syntax
*/

#ifndef _XML_
#define _XML_
#include <string>
#include "Stack.h"
#include <iostream>

class XMLConvention {
  private:
    std::string inputStream;
    char specialChar[14] = {',', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '[', ']', '\''};

    /*
      pre: passes in a string (chunk)
      post: 'chops' chunk into an array of smaller strings
    */
    std::string* getStringPieces(std::string chunk);
    int numPieces = 0;    //number of elements in array of XMLPieces
    std::string *XMLPieces;

  public:
    //constructor and destructor, respectively
    XMLConvention();
    ~XMLConvention();

    /*
      pre: passes in a string of characters that then gets broken into an array of subsstrings via getStringPieces()
      post: returns true if this text is proper XML syntax
    */
    bool isValidXML(std::string XMLChunk) throw (PrecondViolatedExcep);

    /*
      pre: passes in an XML tag enclosed with '<' and '>' characters
      post: returns true if this tag is one of the 6 allowed tags for the purposes of this assignment
    */
    bool isValidTag(std::string tag);

    /*
      pre:
      post: checks to see if the character is allowed
      note: allowed characters include numbers, letters, whitespace, and an array of special characters seen above
    */
    bool isValidCharacter(char c);

    /*
      pre:
      post: prints formatted XML document to screen
    */
    void printXML();
};

#endif
