/*
* "huffman".cpp
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


#include <iostream>
#include <cstdlib>
#include <string.h>
#include <vector>
#include <queue>
#include <fstream>
#include <sstream>
#include <ios>
#include "string_repr.h"
#include <cctype>

using namespace std;

string input; 
bool quit = false;

/**
 * Makes a Huffman Tree and its nodes
 **/
struct HuffmanTreeNode{
    
  char data;
  int frequency;
  HuffmanTreeNode *left;
  HuffmanTreeNode *right;
  
  HuffmanTreeNode(char data, int freq){
    
    this->data = data;
    this->frequency = freq;
    left = NULL;
    right = NULL;
  }
};

/**
 * Holds the operator overload for comparing frequenies of nodes
 **/
struct Compare{
  bool operator()(HuffmanTreeNode * l, HuffmanTreeNode * r){
    return (l->frequency > r->frequency);
  }
};

/**
 * checks to see if a file is empty
 * @param ifstream& the file being checked
 * @return bool true if empty, false if not empty
 **/
bool isFile_empty(ifstream& pFile)
{
    return pFile.peek() == ifstream::traits_type::eof();
}

/**
 * writes the huffman codes of the tree to library.txt
 * @param struct HuffmanTreenode* the huffman tree codes are being 
 * obtained from
 * @param string the code of each node, found recursively
 **/
void writeCodes(struct HuffmanTreeNode * root, string code){
    
  ofstream file;
  file.open("library.txt", fstream::out | fstream::app);
  
  if(root != NULL){
    
    if(root -> data != '*'){
      
      if(root -> data == ' '){
	file << "(sp) " << code << "\n";
      }
      else
	file << root->data << " " << code << "\n";
    }
    
    writeCodes(root->left, code + "0");
    writeCodes(root->right, code + "1");
  }
  
  file.close();
  
}//encode
  
/**
 * Makes the huffman tree
 * @param char[] the characters that go in the tree
 * @param int[] the characters' corresponding frequencies
 * @param int the size of the tree derived from the number of characters
 **/
void makeCode(char data[], int freq[], int size){

  struct HuffmanTreeNode *left, *right, *top;

  priority_queue<HuffmanTreeNode*, vector<HuffmanTreeNode*>, Compare> queue;

  for(int i = 0; i < size; i++){
    queue.push(new HuffmanTreeNode(data[i], freq[i]));
  }
  
  while(queue.size() != 1){

    left = queue.top();
    queue.pop();

    right = queue.top();
    queue.pop();
    
    top = new HuffmanTreeNode('*', left->frequency + right->frequency);
    top->left = left;
    top->right = right;
    queue.push(top);
  }
  
  //write to library.txt
  writeCodes(queue.top(), "");
}//makeCode

/**
 * Encodes a given string using library.txt
 * @param string the string being encoded
 * @return int the length of the new encoded string
 **/
int encode(string input){
  
  char letters[26];
  string codes[26];

  ifstream ifs("library.txt");
  string content;
  content.assign( (istreambuf_iterator<char>(ifs) ),
                (istreambuf_iterator<char>()    ) );

  
  char *cstr = new char[content.length() + 1];
  strcpy(cstr, content.c_str());
  
  //populate letters array
  for(int i =0; i < 26; i++)
  	letters[i] = (char)(i+97);
  
  //populate codes array
  int j =0;
  for(int i = 97; i < 123; i++)
    {
      for(char * s = cstr; *s != '\0'; s++)
  	{

  	  if(*s == (char)i && *(s+1)=='p')
  	    continue;

  	  if(*s == (char)i && *(s -1) == 's')
  	  	continue;

	  if(*s == (char)i)
	    {
	      
	      for(char * t = s+2; *t != '\n'; t++)
		    codes[j] += *t;
  		}
  	}
      j++;	
    }
  
  delete [] cstr;
  
  char * inputcstr = new char[input.length() + 1];
  strcpy(inputcstr, input.c_str());
  


  string encoding;
 // populate encoding 
  for(char * s = inputcstr; *s != '\0'; s++)
    {
      if(*s == ' ')
        encoding += "01";

        for(int i =0; i < 26; i++)
      	{
      	  if(letters[i] == *s)
      	    {
      	      encoding += (codes[i]);
      	    }
      	}
    }

  cout << "The encoded text is: " <<  encoding << endl;
  
  return sizeof(encoding);
}//encode

/**
 * Decodes a given string using library.txt
 * @param input the string being decoded
 **/
void decode(string input){

  ifstream file;
  file.open("library.txt");
  
  string toParse;
  char letters[27];
  string codes[27];
  int count=0;
  int index=0;
  
  if(file){
    while(getline(file, toParse)){
      
      if(count == 8){
	letters[8] = ' ';
	codes[8] = toParse.substr(5, sizeof(toParse));
      }
      else{
	string letter = toParse.substr(0,1);
	letters[count] = *(letter.c_str());
	
	string code = toParse.substr(2, sizeof(toParse));
	codes[count] = code;       
      }
      count++;
    }//while
  }//if
  
  int start=0;
  int end=1;
  bool found=false;
  string decoding;
  int endCount = 0;
  
  //searches for the codes
  while(endCount < (int)input.size()){
    
    string sub = input.substr(start, end);
    int indexFound = 0;
    string stringCode;
    
    for(int i = 0; i < 27; i++){
      
      if(codes[i].compare(sub) == 0){
	found = true;
	indexFound = i;
	break;
      }
    }//for
    
    if(found){
      decoding += letters[indexFound];
      index += end;
      start = index;
      end = 1;
      found = false;
    }
    else{
      end++;
    }
    endCount++;
  }//while
  
  cout << "The decoded text is: " << decoding << endl;
  file.close();
}//decode

/**
 * Driver function for the project
 * Holds the user interface
 **/
int main(){
  
    string_repr str; //initialize a string_repr instance
    int oneCount;
    
    while (quit == false)
      {
	cout << endl;
	cout << "Please choose from the following:  " << endl;
	cout << "Note : Library must be built before encoding or decoding." << endl;
	cout << endl;
	cout << "1: Build the library file from sample.txt" << endl;
	cout << "2: Print the character list and the frequency of each char in sample.txt" << endl;
	cout << "3: Encode a message" << endl;
	cout << "4: Decode a message" << endl;
	cout << "q: To exit" << endl;
	cout << ">> " ;

	getline(cin,input);
	cout << endl;
	
	if(input == "quit" || input == "Quit" || input == "q" || input == "Q")
	{
	  quit = true;
	}
	
	else if(input == "1")
	  {
	    oneCount++;

	    str.setStringToSample("sample.txt");
	    cout << "File is successfully opened." << endl;
	    
	    str.calculateCharFrequency();
	    
	    if(oneCount == 1){
	      char alphabet[27];
	      int frequency[27];
	      int count = 0;
	      
	      for(int i = 97; i < 123; i++){
		alphabet[count] = (char)i;
		count++;
	      }
	      alphabet[26] = ' ';
	      
	      for(int i = 0, j = 97; i < 26; i++, j++){
		frequency[i] = str.charCount[j];
	      }
	      frequency[26] = str.charCount[32];

	      int size = 27;
	      
	      makeCode(alphabet, frequency, size);
	    }
	    else
	      cout << "library.txt has already been made" << endl;
	   
	  }
	
	else if(input == "2")
	  {
	    str.setStringToSample("sample.txt");

	    str.resetCharCount();
	    str.calculateCharFrequency();
	    str.printFrequencyTable();
	  }
	else if(input == "3"){
	  string message;

	  cout << endl;
	  cout << "Please enter the text to be encoded" << endl;
	  cout << ">> ";
	  getline(cin, message);
	  
	  //encode here
	  double encodeSize = encode(message);
	  
	  double ratio = sizeof(message)/(encodeSize * 8);
	  cout << "The compression ratio is: " << ratio << endl;
	}
	else if(input == "4"){
	  string message;

	  cout << endl;
	  cout << "Please enter an encoded message: " << endl;
	  cout << ">> ";
	  getline(cin, message);
	  
	  string decoded;
	  
	  decode(message);
	  
	}
      } //user interface loop
    
    
    ofstream file;
    file.open("library.txt", ios::out | ios::trunc);
    file.close(); 
   
    
    return EXIT_SUCCESS;
    
  }
  
