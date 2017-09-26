/*
* "string_repr".h
* Group Members: Nick Caamano, Patrizia Pain
* Submission Date: April 23rd 2017
* 
* Purpose: Project 4
* 
* Statement of Academic Honesty: 
* 
* The following code represents our own work. Wehave neither
* received nor given inappropriate assistance. Wehave not copied
* or modified code from any source other than the course webpage
* or the course textbook. Werecognize that any unauthorized
* assistance or plagiarism will be handled in accordance with
* the University of Georgia's Academic Honesty Policy and the
* policies of this course. Werecognize that my work is based
* on an assignment created by the Department of Computer
* Science at the University of Georgia. Any publishing
* or posting of source code for this project is strictly
* prohibited unless you have written consent from the Department
* of Computer Science at the University of Georgia.
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
