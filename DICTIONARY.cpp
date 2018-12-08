#include <iostream>
#include <stdlib.h>
#include <string> 
#include <iterator>
#include <fstream>
#include <map>

#include "DICTIONARY.h"

using namespace std;

WORDS Dictionary::lookUp(string word)
{
    if(englishWords[word].active)
    {
        return englishWords[word];
    }
    else if(germanWords[word].active)
    {
        return germanWords[word];
    }
    else
    {
        WORDS empty;
        empty.active = false;
        cout << "Not in dictionary" << endl;
        return empty;
    }
}

void Dictionary::readMoreThanOne(string expected, ifstream &fin, vector <string> &readVector)
{
    string input;
    while(true)
    {
        fin >> input;
        this->lineCount++;
        if(input == expected)
        {
            break;
        }
        else
        {
            readVector.push_back(input);
        }
    }
}

bool Dictionary::readWord(ifstream &fin)
{
    string input;
    bool moreThanOneflag = false;
    while(true)
    {
        vector <string> inputVector;
        fin >> input;
        this->lineCount++;
        if(input == "$eword")
        {
            readMoreThanOne(input, fin, inputVector);
            this->eWordToRead.word = inputVector;
        }
        else if(input == "$gword")
        {
            readMoreThanOne(input, fin, inputVector);
            this->gWordToRead.word = inputVector;
        }
        else if(input == "$econj")
        {
            readMoreThanOne(input, fin, inputVector);
            this->eWordToRead.conjugations = inputVector;
        }
        else if(input == "$gconj")
        {
            readMoreThanOne(input, fin, inputVector);
            this->gWordToRead.conjugations = inputVector;
        }
        else if(input == "$type")
        {
            fin >> input;
            this->lineCount++;
            eWordToRead.type = input;
            gWordToRead.type = input;
            fin >> input;
        }
        else if(input == "$case")
        {
            fin >> input;
            this->lineCount++;
            eWordToRead.wordCase = input;
            gWordToRead.wordCase = input;
            fin >> input;
        }
        else if(input == "$word")
        {
            return true;
        }
        else
        {
            displayError("a <$SYMBOL>", input);
            exit(EXIT_FAILURE);
        }
    }
}

void Dictionary::displayError(string expected, string got)
{
    cout << "LINE: " << lineCount << ": Expected " << expected << ", but got " << got << endl;

}

void Dictionary::read()
{
    ifstream dictionaryFile("../_IOFILES/dictionary.txt");
    string input;
    this->lineCount = 0;
    if(!dictionaryFile.is_open())
    {
        cout << "CANNOT FIND DICTIONARY.TXT" << endl;
        exit(EXIT_FAILURE);
    }
    else
    {
        while(dictionaryFile >> input)
        {
            this->lineCount++;
            if(!(input == "$word"))
            {
                displayError("$word", input);
                exit(EXIT_FAILURE);
            }
            else if(readWord(dictionaryFile)) //read until we encounter $word
            {
                    WORDS empty;
                    //cout << eWordToRead.word << endl;
                    string englishIndex;
                    string germanIndex;
                    if(eWordToRead.type == "pronoun")
                    {
                        germanIndex = "gpronoun";
                        englishIndex = "epronoun";
                    }
                    else
                    {
                        germanIndex = gWordToRead.word.at(0);
                        englishIndex = eWordToRead.word.at(0);
                    }
                    this->eWordToRead.translation = germanIndex;
                    this->gWordToRead.translation = englishIndex;
                    this->eWordToRead.active = true;
                    this->gWordToRead.active = true;
                    this->englishWords.insert(pair<string, WORDS>(englishIndex, this->eWordToRead));
                    this->germanWords.insert(pair<string, WORDS>(germanIndex, this->gWordToRead));
                    this->gWordToRead = empty;
                    this->eWordToRead = empty;
            }
        }
    }
    //englishWords.insert(pair<string, WORDS>(w.name, w));
}


Dictionary::Dictionary()
{
    this->wordCaseStrings[0] = "NOMINATIVE";
    this->wordCaseStrings[1] = "ACCUSATIVE";
    this->wordCaseStrings[2] = "DATIVE";
    read();
}
Dictionary::~Dictionary()
{

}
