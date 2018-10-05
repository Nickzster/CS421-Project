#include<iostream>
#include<fstream>
#include<string>
using namespace std;

// INSTRUCTION:  copy and edit your parser.cpp to create this file.
// cp ../ParserFiles/parser.cpp .
// Complete all ** parts.
// --------------------------------------------------------

//=================================================
// File translator.cpp written by Group Number: **
//=================================================

// ----- Changes to the parser.cpp ---------------------

// ** Declare dictionary that will hold the content of lexicon.txt
// Make sure it is easy and fast to look up the translation
// Do not change the format or content of lexicon.txt 

// ** Additions to parser.cpp here:
//    getEword - using the current lexeme, look up the English word
//               in the Lexicon if it is there -- save the result   
//               in saved_E_word
//    gen(line_type) - using the line type,
//                     sends a line of an IR to translated.txt
//                     (saved_E_word or saved_token is used)

// ** Be sure to put the name of the programmer above each function

// ** Be sure to put the corresponding grammar 
//    rule with semantic routines
//    above each non-terminal function



// -------------------------------------------

// The final test driver to start the translator
// Done by  **
int main()
{
  //** opens the lexicon.txt file and reads it in
  //** closes lexicon.txt 

  //** opens the output file translated.txt

  cout << "Enter the input file name: ";
  cin >> filename;
  fin.open(filename.c_str());

  //** calls the <story> to start parsing

  //** closes the input file 
  //** closes traslated.txt
 
}// end



