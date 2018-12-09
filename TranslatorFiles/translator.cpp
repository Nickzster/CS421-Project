#include <iostream>
#include <fstream>
#include <string>
#include "parser.h"
#include "DICTIONARY.h"
using namespace std;

// INSTRUCTION:  copy and edit your parser.cpp to create this file.
// cp ../ParserFiles/parser.cpp .
// Complete all ** parts.
// --------------------------------------------------------

//=================================================
// File translator.cpp written by Group Number: *G16*
//=================================================

// ----- Changes to the parser.cpp ---------------------

// ** Declare dictionary that will hold the content of lexicon.txt
// Make sure it is easy and fast to look up the translation
// Do not change the format or content of lexicon.txt 

// ** Additions to parser.cpp here:

ofstream translation("translation.txt");

string saved_E_word;
string savedToken;
Dictionary d;
//    getEword - using the current lexeme, look up the English word
//               in the Lexicon. If the current lexeme is there , then  save the result   
//               in saved_E_word.
//Written by Nick Murrin & Nick Zimmermann
void getEword()
{
    saved_E_word = d.lookUp(getCurrentLexeme());
}
//    gen(line_type) - using the line type,
//                     sends a line of an IR to translated.txt
//                     (saved_E_word or saved_token is used)
//Written by Clay Flores
void gen(string line)
{
    if(!translation.is_open())
    {

    }
    else
    {
        if (line == "TENSE")
        {
            savedToken = "TENSE: " + getCurrentToken();
            translation << savedToken << endl;
        }
        else
        {
            saved_E_word =  line + ": " + saved_E_word;
            translation << saved_E_word << endl;
        }
    }
}

void writeBlank()
{
    translation << endl;
}

// ** Be sure to put the name of the programmer above each function

// ** Be sure to put the corresponding grammar 
//    rule with semantic routines
//    above each non-terminal function



// -------------------------------------------

// The final test driver to start the translator
// SEE TESTDRIVER.CPP



