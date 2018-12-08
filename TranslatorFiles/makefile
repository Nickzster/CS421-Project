CXXFLAGS = -std=c++11

BUILD: DICTIONARY.o scanner.o parser.o translator.o main.o
	g++ -O -o G16Translator DICTIONARY.o scanner.o parser.o translator.o main.o

DICTIONARY.o: DICTIONARY.cpp DICTIONARY.h
	g++ -c -std=c++11 DICTIONARY.cpp
scanner.o: scanner.h scanner.cpp
	g++ -c scanner.cpp
parser.o: parser.h parser.cpp
	g++ -c parser.cpp
translator.o: translator.h translator.cpp
	g++ -c -std=c++11 translator.cpp
main.o: main.cpp
	g++ -c main.cpp		
clean: 
	rm *.o G16Translator