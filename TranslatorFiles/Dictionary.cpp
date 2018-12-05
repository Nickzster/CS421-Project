/*
Dictionary IMPLEMENTATION FILE FILE
VOCAB TRANSLATOR WRITTEN BY NICK ZIMMERMANN.
Note: Some words are in german / say german... I designed this Dictionary to act as a "dictionary" for my german class...
So I simply made some changes for it to do japanese instead.
*/
    #include <iostream>
    #include <list>
    #include <string>
    #include <fstream>
    #include <ostream>
    #include <istream>
    #include "Dictionary.h"
    using namespace std;

    Dictionary::Dictionary()
    {
        cout << "INITALIZING======================" << endl;
        cout << "calling constructor" << endl;
        read();
        cout << "=================================" << endl;
        cout << endl;
    }
    Dictionary::~Dictionary()
    {   
        cout << endl;
        cout << "INITALIZING======================" << endl;
        cout << "calling destructor" << endl;
        // write();
        cout << "=================================" << endl;
    }

    void Dictionary::read()
    {
        ifstream japaneseFile("lexicon.txt"); //Japanese file to read
        //Read the Japanese file first.
        int japaneseCount = 0;
        if(japaneseFile.is_open()) //if both files exist
        {
            //then read it
            cout << "Reading lexicon.txt..." << endl;
            char japaneseInput[100];
            while(japaneseFile>>japaneseInput) //read Japanese word
            {
                string jword = japaneseInput;
                japaneseFile >> japaneseInput; //then read English word
                string eword = japaneseInput;
                WORDS w;
                w.JapaneseWord = jword;
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

    void Dictionary::printAll()
    {
        for(int i = 0; i < Words.size(); i++)
        {
            WORDS w;
            w = Words.at(i);
            cout << w.EnglishWord;
            cout << " - ";
            cout << w.JapaneseWord << endl;
        }
    }


    int Dictionary::searchForAWord(string word)
    {
        for(int i = 0; i < this->Words.size(); i++)
        {
            WORDS w;
            w = Words.at(i);
            if(word == w.JapaneseWord || word == w.EnglishWord)
            {
                return i;
            }
        }
        return -1;
    }

    string Dictionary::translate(string wordToTranslate)
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
        if(validReturn && w.EnglishWord == wordToTranslate) //If the word is an English word
        {
            return w.JapaneseWord;
        }
        else if(validReturn && w.JapaneseWord == wordToTranslate) //If the word is a Japanese word
        {
            return w.EnglishWord;
        }
        else
        {
            cout << wordToTranslate << " isn't in the dictionary... returning original word..." << endl;
            return wordToTranslate;
        }
    }

