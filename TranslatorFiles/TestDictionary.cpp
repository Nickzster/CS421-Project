#include <string>
#include <iostream>
#include "VocabTranslator.h"

using namespace std;

void testTranslate(string wordToTranslate, VocabTranslator &v)
{
    cout << "Word: " << wordToTranslate << " translates to " << v.translate(wordToTranslate) << endl;
}

int main()
{
    VocabTranslator v;
    string wordToTranslate;
    v.printAll();
    while(true)
    {
        cout << "Enter a word to translate: ";
        cin >> wordToTranslate;
        cout << endl;
        testTranslate(wordToTranslate, v);
        cout << endl << endl;
    }
    return 0;
}