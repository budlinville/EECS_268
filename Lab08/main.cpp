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
#include "Stack.h"
#include "Queue.h"
#include "PrecondViolatedExcep.h"
#include "XMLConvention.h"

/*
  @Pre:
  @Post:
  @Returns: a string corresponding to a tag enclosed with < and >
*/
std::string getTag(std::ifstream *fStream) throw (PrecondViolatedExcep) {
  Queue<char> *tagQueue = new Queue<char>();
  string tag = "";
  char c = ' ';

  tagQueue->enqueue('<');

  try { //this needs work... needs to handle event that there is not a '>'
    while (c != '>') {
      fStream->get(c);
      tagQueue->enqueue(c);
    }
    while (tagQueue->isEmpty() == false) {
      tag.push_back(tagQueue->peekFront());
      tagQueue->dequeue();
    }
  } catch (PrecondViolatedExcep &e) {
    throw PrecondViolatedExcep("A tag has been left open. Need '>' character!");
  }

  return tag;
}

/*
  Pre: file name passed in as argv paramter
  Post: Displays Formattede XML onto the screen
*/
int main(int argc, char* argv[]) throw (PrecondViolatedExcep){
  std::string fileName = argv[1];
  std::ifstream fileStream(fileName);
  XMLConvention *xmlc = new XMLConvention();
  bool validText = false;
  string textChunk = "";          //a string that holds inputted content in a way such that isXML() method can read it
  string possibleTag = "";
  char possibleCharacter = ' ';
  char previousCharacter = '\0';

  char c;
  while (fileStream.get(c)) {
    if (c == '<') {     //tag
      possibleTag = getTag(&fileStream);
      validText = xmlc->isValidTag(possibleTag);
      if (validText == true) {
        if (previousCharacter == ' ') {
          textChunk += (possibleTag + " ");
        } else {
          textChunk += (" " + possibleTag + " ");
        }

      } else {
        throw PrecondViolatedExcep("There is an invalid tag.");
      }

      previousCharacter = ' ';
    } else {
      possibleCharacter = c;
      if (possibleCharacter == ' ' && previousCharacter == ' ') {
        textChunk.pop_back();
      }
      validText = xmlc->isValidCharacter(possibleCharacter);

      if (validText == true) {
        if (possibleCharacter != '\t' && possibleCharacter != '\n') {
          textChunk += c;
        }
      } else {
        throw PrecondViolatedExcep("There is invalid content.");
      }

      previousCharacter = possibleCharacter;
    }
  }

  validText = xmlc->isValidXML(textChunk);

  xmlc->printXML();

  fileStream.close();
  return 0;
}
