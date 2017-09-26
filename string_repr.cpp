/*
* "string_repr".cpp
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

#include "string_repr.h"
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <sstream>


string_repr::string_repr()
{
	for(int i =0; i < 128; i++)
	{
		charCount[i] = 0;
	}
}

//todo header




void string_repr::setStringToSample(const char * filename)
{
	std::ifstream t;
	int length;
	t.open(filename);      
	t.seekg(0, std::ios::end);    
	length = t.tellg();           
	t.seekg(0, std::ios::beg);    
	workingString = new char[length];    
	t.read(workingString, length);       
	t.close();                    
}


void string_repr::calculateCharFrequency()
{	
	for(char * s = workingString; *s != '\0'; s++)
		charCount[(int)*s]++;
}

void string_repr::printFrequencyTable()
{
	cout << "FREQUENCY TABLE" << endl;
	cout << "char      frequency" << endl;
	cout << "(sp)" << " :    "<< charCount[32] << endl;
	for(int i = 97; i < 123; i++)
			{
				cout << (char)i << "    :    " << charCount[i] << endl; 
			}
}

void string_repr::resetCharCount()
{
	for(int i =0; i < 128; i++)
	{
		charCount[i] = 0;
	}
}

void string_repr::printString()
{
	cout << workingString << endl;
}




