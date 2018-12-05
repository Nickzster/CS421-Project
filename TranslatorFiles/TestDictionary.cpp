#include <string>
#include <iostream>
#include "Dictionary.h"

using namespace std;

void testTranslate(string wordToTranslate, Dictionary &v)
{
    cout << "Word: " << wordToTranslate << " translates to " << v.translate(wordToTranslate) << endl;
}

int main()
{
    Dictionary v;
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