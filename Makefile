all: huffman 

huffman: huffman.o string_repr.o 
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -o huffman huffman.o string_repr.o 

huffman.o: huffman.cpp string_repr.h 
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -c huffman.cpp

string_repr.o: string_repr.cpp string_repr.h
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -c string_repr.cpp


clean:
	rm -rf huffman
	rm -rf *.o
	rm -rf core.*