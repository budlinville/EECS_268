/*
File: XMLConvention.h
Author: Bud Linville
Date: March 27th, 2016
Purpose: houses methods for checking whether or not a file uses conventional XML syntax
*/

#ifndef _XML_
#define _XML_
#include <string>
#include "PrecondViolatedExcep.h"
#include <iostream>

class XMLConvention {
  private:

    //array of special characters allowed in these simplified XML documents
    char specialChar[14] = {',', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '[', ']', '\''};

    //array of tags seen as valid for this simplified version of XML documents
    std::string validTags[6] = {"<tab>", "<p>", "<listItem>", "</tab>", "</p>", "</listItem>"};

    /*
      @Pre:
      @Post:
      @Returns: a string corresponding to a tag enclosed with < and >
    */
    std::string getTag(int startingPos, std::string *chunk);

    /*
      pre:
      post: checks to see if the character is allowed
      note: allowed characters include numbers, letters, whitespace, and an array of special characters seen above
    */
    void checkValidTag(std::string inp) throw (PrecondViolatedExcep);

    /*
      pre:
      @paramaters: reference to text chunk as well as the starting and ending indexes of the tag
      post: will fail program if tag passed in does not have whitespace surrounding it
    */
    void checkWhiteSpaceAroundTags(std::string *chunk, int pre, int post) throw (PrecondViolatedExcep);

    /*
      @Post: cycles through isDigit, isLetter, and isSpecial methods to check if valid character
      @Return: true if a valid character; false otherwise
    */
    bool isValidCharacter(char c);

    /*
      @Pre:
      @Post:
      @Return: true if a valid number (0-9); false otherwise
    */
    bool isDigit(char c);

    /*
      @Pre:
      @Post:
      @Return: true if a letter (a-z or A-Z); false otherwise
    */
    bool isLetter(char c);

    /*
      @Pre:
      @Post: checks if a valid Special character as defined in the private specialChar array; if not, calls isWhiteSpace() method
      @Return: true if a valid special character or if isWhiteSpace() returns true; false otherwise
    */
    bool isSpecial(char c);

    /*
      @Pre:
      @Post:
      @Return: true if a valid white space (' ', '\n', '\t'); false otherwise
    */
    bool isWhiteSpace(char c);

    /*
      pre: passes in a string (chunk)
      post: 'chops' chunk into an array of smaller strings; also sets numPieces variable to value corresponding to number of objects in array
    */
    std::string* getStringPieces(std::string chunk);

    //a pointer to the array of whitespace-delimited words as created from getStringPieces() method
    std::string *XMLPieces;

    //a global variable corresponding to the number of objects in array XMLPieces
    int numPieces = 0;    //number of elements in array of XMLPieces

  public:

    //constructor and destructor, respecitvely
    XMLConvention();
    ~XMLConvention();

    /*
      @Pre:
      @Post:
      @Return: returns true if the string passed in follows correct XML syntax
      @Note: recursive
    */
    bool isXML(std::string XMLChunk) throw (PrecondViolatedExcep);

    /*
      pre:
      post: prints formatted XML document to screen
    */
    void printXML(std::string XMLChunk);
};

#endif
