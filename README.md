
 #Author Nick Caamano and Patrizia Pain
 ## Description

 	This program provides the user an interface to create a Huffman Code
 	from a range of frequencies of characters from a sample.txt file of a
 	popular literary work. The huffman code is generated from a binary huffman
 	tree that is created when the sample.txt is read. This tree groups frequencies
 	of characters into nodes and subsequentially generates binary encodings when 
 	the tree is traversed. These encodings are stored in a file called libary.txt when
 	the user chooses this function. The user also has the option to print the frequecy 
 	table of each character in the file. Additionally the user can encode a unique input
 	string as long is it is composed of characters from library.txt. The user can also
 	provide an encoded message and the program will decode it using libary.txt. 
    
  
 ## Instructions

 To compile the program, use:

 $ make 

 To run the program, use:

 $ ./huffman

To use program, type first:


1 

to read sample.txt and generate huffman tree and huffman code into library.txt

Then type either: 

2 

to print the frequency table

or

3 

to encode a specific input string

or 

4
 
to decode a specific binary input string.

NOTE:You must press 1 or 2 before encoding or decoding. Library.txt must
exist to perform these functions. We will sumit this project without
libary.txt so this is necessary. For option 3 you must ONLY use
characters in sample.txt and library.txt
For option 4 if you type a binary encoding that is not recognized by library.txt
nothing will print for the decoded message. 
Be careful with extra spaces or characters when typing in the decoded message. 
Also note that libary.txt is reset after every time the program exits. 
