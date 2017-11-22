/*
File: main.cpp
Author: Bud Linville
Date: March 27th, 2016
Purpose: starts program that reads in simple xml files, formats the text accordingly, and displays it on the screen
*/

//still need to make comments and fix up exceptions that get thrown.


#include <iostream>
#include <fstream>
#include <string>
#include "PrecondViolatedExcep.h"
#include "XMLConvention.h"

/*
  Pre: file name passed in as argv paramter
  Post: Displays Formattede XML onto the screen
  Note: reads in characters from file one at a time and transforms it into a string that I call "chunk"
  Note2: replaces all whitespace with ' ' for simplification later on in program
*/
int main(int argc, char* argv[]) throw (PrecondViolatedExcep){
  std::string fileName = argv[1];
  std::ifstream fileStream(fileName);
  XMLConvention *xmlc = new XMLConvention();
  std::string textChunk = "";          //a string that holds inputted content in a way such that isXML() method can read it
  char previousCharacter = '\0';
  char c;

  while (fileStream.get(c)) {
    if (c == '\n' || c == '\t') {
      c = ' ';
    }

    textChunk += c;

    if (c == ' ' && previousCharacter == ' ') {
      textChunk.pop_back();
    }
    previousCharacter = c;
  }

  bool validXML = xmlc->isXML(textChunk);

  if (validXML) {
    xmlc->printXML(textChunk);
  } else {
    std::cout << "INVALID" << std::endl;
  }

  return 0;
}
