/*
VOCABTRANSLATOR IMPLEMENTATION FILE FILE
VOCAB TRANSLATOR WRITTEN BY NICK ZIMMERMANN.
Note: Some words are in german / say german... I designed this VocabTranslator to act as a "dictionary" for my german class...
So I simply made some changes it to do japanese instead.
*/

    
    #include <iostream>
    #include <list>
    #include <string>
    #include <fstream>
    #include <ostream>
    #include <istream>
    #include "VocabTranslator.h"
    using namespace std;

    VocabTranslator::VocabTranslator()
    {
        cout << "INITALIZING======================" << endl;
        cout << "calling constructor" << endl;
        read();
        cout << "=================================" << endl;
        cout << endl;
    }
    VocabTranslator::~VocabTranslator()
    {   
        cout << endl;
        cout << "INITALIZING======================" << endl;
        cout << "calling destructor" << endl;
        // write();
        cout << "=================================" << endl;
    }

    void VocabTranslator::read()
    {
        ifstream japaneseFile("lexicon.txt"); //german file to read
        //Read the german file first.
        int japaneseCount = 0;
        if(japaneseFile.is_open()) //if both files exist
        {
            //then read it
            cout << "Reading lexicon.txt..." << endl;
            char japaneseInput[100];
            while(japaneseFile>>japaneseInput) //read japanese word
            {
                string jword = japaneseInput;
                japaneseFile >> japaneseInput; //then read english word
                string eword = japaneseInput;
                WORDS w;
                w.GermanWord = jword;
                w.EnglishWord = eword;
                this->Words.push_back(w); //Fill the Words array.
                japaneseCount++;
            }
            cout << "Done reading lexicon.txt." << endl;
        }
        else if(!japaneseFile.is_open())
        {
            cout << "SOMETHING IS MISSING!!!" << endl;
        }
        japaneseFile.close();
    }

    void VocabTranslator::printAll()
    {
        for(int i = 0; i < Words.size(); i++)
        {
            WORDS w;
            w = Words.at(i);
            cout << w.EnglishWord;
            cout << " - ";
            cout << w.GermanWord << endl;
        }
    }


    int VocabTranslator::searchForAWord(string word)
    {
        for(int i = 0; i < this->Words.size(); i++)
        {
            WORDS w;
            w = Words.at(i);
            if(word == w.GermanWord || word == w.EnglishWord)
            {
                return i;
            }
        }
        return -1;
    }

    string VocabTranslator::translate(string wordToTranslate)
    {
        //First, we search for a vocab word.
        int index = searchForAWord(wordToTranslate);
        WORDS w;
        bool validReturn = false;
        if(!(index == -1))
        {
            w = this->Words.at(index);
            validReturn = true;
        }
        if(validReturn && w.EnglishWord == wordToTranslate) //If the word is an english word
        {
            return w.GermanWord;
        }
        else if(validReturn && w.GermanWord == wordToTranslate) //If the word is a german word
        {
            return w.EnglishWord;
        }
        else
        {
            cout << wordToTranslate << " isn't in the dictionary..." << endl;
            return "INVALID";
        }
    }

