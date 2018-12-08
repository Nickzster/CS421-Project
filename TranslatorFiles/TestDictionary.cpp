#include <string>
#include <iostream>
#include "DICTIONARY.h"

using namespace std;


int main()
{
    Dictionary d;
    string wordToTranslate;
    while(true)
    {
        cout << "Enter a word to translate: ";
        cin >> wordToTranslate;
        cout << wordToTranslate << " translated is " << d.lookUp(wordToTranslate) << endl;
    }
    return 0;
}