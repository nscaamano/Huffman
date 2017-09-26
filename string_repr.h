/*
* "string_repr".h
* Author: Nick Caamano
*/

#ifndef STRING_REPR_H
#define STRING_REPR_H
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <sstream>


using namespace std;


class string_repr
{
  
 public:
  
  char * workingString;
  int charCount[128];

  /**
   * Default constructor 
   **/
  string_repr();
  
  /**
   * Makes the working string equal to the contents in file
   * @param const char* the file being set to working string
   **/
  void setStringToSample(const char * filename);
  
  /**
   * Calculates the frequencies of the characters in sample.txt
   **/
  void calculateCharFrequency();

  /**
   * Prints the characters and its corresponding frequencies to 
   * standard output
   **/
  void printFrequencyTable();
  
  /**
   * Resets the character count array 
   **/
  void resetCharCount();

  /**
   * Prints the working string to standard output
   **/
  void printString();
 




};
#endif
