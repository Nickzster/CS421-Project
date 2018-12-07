/*
Dictionary HEADER FILE
VOCAB TRANSLATOR WRITTEN BY NICK ZIMMERMANN.
Note: Some words are in german / say german... I designed this Dictionary to act as a "dictionary" for my German class...
So I simply made some changes it to do Japanese instead.
*/
#include <iostream>
#include <list>
#include <string>
#include <vector>
using std::string;
using std::vector;
#ifndef TRANSLATOR
#define TRANSLATOR
struct WORDS
{
    string EnglishWord;
    string JapaneseWord;
};
struct VERBS
{
    string EnglishVerb;
    vector <string> JapaneseConjugations;
};
class Dictionary
{
    private:
        vector <WORDS> Words;
        vector <VERBS> Verbs;
        int searchForAWord(string);
    public:
    Dictionary();
    ~Dictionary();
    void write();
    void read();
    void printAll();
    string translate(string);
};
#endif