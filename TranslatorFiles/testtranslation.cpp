#include <iostream>
#include <fstream>
using namespace std;

fstream translation(translation.txt);

saved_token;

saved_E_word;

void gen(string line)
{
    if(!translation.is_open())
    {

    }
    else
    {
        if (line == "TENSE")
        {
            saved_token = "TENSE";
            translation << saved_token;
        }
        else
        {
            saved_E_word = line + " ";
            translation << saved_E_word;
        }
    }
}

int main()
{
    saved_E_word = "rika";
    gen("ACTOR: ");
}