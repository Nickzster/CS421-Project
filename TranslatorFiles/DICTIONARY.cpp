/*
    DICTIONARY.CPP - by Nick Zimmermann.
    Implementation of the dictionary.
*/

#include <iostream>
#include <stdlib.h>
#include <string> 
#include <iterator>
#include <fstream>
#include <map>

#include "DICTIONARY.h"

using namespace std;

string Dictionary::lookUp(string word)
{
    WORDS* ew = this->englishWords[word]; //store the english word.
    WORDS* jw = this->japaneseWords[word]; //store the japanese word.
    if(ew != NULL && ew->englishWord == word) //If the word entered exists, and it is in the english map...
    {
        word = ew->japaneseWord; //then return the japanese translation.
    }
    else if(jw != NULL && jw->japaneseWord == word) //If the word exists, and it is in the japanese map...
    {
        word = jw->englishWord; //then return the english translation
    }
    else //Otherwise, it is not in the dictionary, and will return the original word.
    {
        cout << "**From Dictionary::lookUp: " << word << " is not in the dictionary.***" << endl;
    }
    return word;
}


void Dictionary::read()
{
    cout << "Reading lexicon.txt..." << endl;
    ifstream dictionaryFile("lexicon.txt");
    string input;
    if(!dictionaryFile.is_open())
    {
        cout << "CANNOT FIND LEXICON.TXT" << endl;
        exit(EXIT_FAILURE);
    }
    else
    {
        while(dictionaryFile >> input)
        {
            WORDS* wordInput = new WORDS;
            wordInput->japaneseWord = input; //read in a japanese word
            dictionaryFile >> input;
            wordInput->englishWord = input; //read in an english word
            this->japaneseWords.insert(pair<string, WORDS*>(wordInput->japaneseWord, wordInput)); //and push it onto the japanese map
            this->englishWords.insert(pair<string, WORDS*>(wordInput->englishWord, wordInput)); //and push it onto the english map
        }
    }
    //englishWords.insert(pair<string, WORDS>(w.name, w)
    cout << "DONE!" << endl;
}

Dictionary::Dictionary()
{
    read();
}
Dictionary::~Dictionary() //cleanup
{
    this->japaneseWords.clear();
    this->englishWords.clear();
}
