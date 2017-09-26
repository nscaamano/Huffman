/*
* "string_repr".cpp
* Author: Nick Caamano
* 
* 
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




