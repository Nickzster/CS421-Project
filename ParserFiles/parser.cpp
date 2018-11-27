#include<iostream>
#include<fstream>
#include<string>
using namespace std;

// INSTRUCTION:  Complete all ** parts.
// You may use any method to connect this file to scanner.cpp
// that you had written.  
// You can copy scanner.cpp here by cp ../ScannerFiles/scanner.cpp .
// -----------------------------------------------------

//=================================================
// File parser.cpp written by Group Number: **
//=================================================

// ----- Utility and Globals -----------------------------------

//  Need syntax_error1 and syntax_error2 functions (each takes 2 args)
//  Be sure to put the name of the programmer above each function
// i.e. Done by: Nick Murrin
// Global File Type
fstream toParse;
fstream Errors;
// Syntax Errors
int error_found = 0;
void syntax_error1(tokentype); // first syntax error function
void syntax_error2(string);   // second syntax error function
/* Extra Credit
//char trace_syntax_error = 'n';
//char trace_errors_output = 'n';
//char trace_remove_errors = 'n';
*/
// Functions:
void syntax_error1(tokentype thetype)//when match() function does not match
{
  error_found = 1;
  //output to screen and error.txt file
  cout << "SYNTAX ERROR: expected " << tokenName[thetype] << " but found " << saved_lexeme << endl;

  if(Errors.is_open())
    Errors << "SYNTAX ERROR: expected " << tokenName[thetype] << " but found " << saved_lexeme << endl;

  if (trace_syntax_error == 'y')//error checking WIP, never goes here
    {
      cout << "Instead of "<< saved_lexeme << " try (eofm to exit): ";
      cin >> saved_lexeme;
    }
  else
    {
      Errors << "===================="  << endl;
      exit(EXIT_FAILURE);//end program
    }
}
//--------------------------------------------------
void syntax_error2(string parseFunc)//when a switch statement goes to default
{
  error_found = 1;
  //output to screen and error.txt file
  cout << "SYNTAX ERROR: unexpected " << saved_lexeme << " found in " << parseFunc << endl;

  if(Errors.is_open())
    Errors << "SYNTAX ERROR: unexpected " << saved_lexeme << " found in " << parseFunc  << endl;

  Errors << "===================="  << endl;
  exit(EXIT_FAILURE);//always finishes the program
}

// ** Need the updated match and next_token (with 2 global vars)
// ** Be sure to put the name of the programmer above each function
// i.e. Done by:


// ----- RDP functions - one per non-term -------------------

// ** Make each non-terminal into a function here
// ** Be sure to put the corresponding grammar rule above each function
// i.e. Grammar: 
// ** Be sure to put the name of the programmer above each function
// i.e. Done by:


//---------------------------------------

// The new test driver to start the parser
// Done by:  **
int main()
{
  cout << "Enter the input file name: ";
  cin >> filename;
  fin.open(filename.c_str());

  //** calls the <story> to start parsing
  //** closes the input file 

}// end
//** require no other input files!
//** syntax error EC requires producing errors.text of messages

