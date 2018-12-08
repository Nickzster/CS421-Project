/*
DICTIONARY.h - by Nick Zimmermann.
Header file for Dictionary.

*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <fstream>
using std::string;
using std::vector;
using std::unordered_map;
using std::ifstream;

#ifndef DICTIONARY

#define DICTIONARY

//WORDS holds two elements in it
struct WORDS
{
    string englishWord;
    string japaneseWord;
};


class Dictionary
{
    private:
        //Both maps hold the same pointers for the same words... different access indicies, however.
        //Allowing you to look up the word either in japanese or english in o(1).
        unordered_map <string, WORDS*> englishWords; //Map of english words. 
        unordered_map <string, WORDS*> japaneseWords; //Map of japanese words.
        //used for dictionary input.
        void read();
    public:
        //constructors
        Dictionary();
        ~Dictionary();
        string lookUp(string);
};

#endif