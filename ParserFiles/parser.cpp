#include<iostream>
#include<fstream>
#include<string>

using namespace std;

#include "scanner.cpp"
int scanner(tokentype& a, string& w);

bool word(string s);
bool period(string s);
void init();
// INSTRUCTION:  Complete all ** parts.
// You may use any method to connect this file to scanner.cpp
// that you had written.  
// You can copy scanner.cpp here by cp ../ScannerFiles/scanner.cpp .
// -----------------------------------------------------

//=================================================
// File parser.cpp written by Group Number: 16
//=================================================

// globally declared to be available, as per instructions
string saved_lexeme;
tokentype saved_token;
bool token_available = false;

// ----- Utility and Globals -----------------------------------

// ** Need syntaxerror1 and syntaxerror2 functions (each takes 2 args)
// ** Be sure to put the name of the programmer above each function
// i.e. Done by:
void syntax_error1(tokentype thetype, string saved_lexeme)//when match() function does not match
{
	cout << "ERROR: expected " << thetype << " but found " << saved_lexeme <<  endl;
	cout << "Exiting Program" << endl;
	exit(EXIT_FAILURE);
}
//--------------------------------------------------
void syntax_error2(string pFunction, string saved_lexeme)//when a switch statement goes to default
{
	cout << "ERROR: unexpected " << saved_lexeme << " found in " << pFunction << endl;
	cout << "Exiting Program" << endl;
	exit(EXIT_FAILURE);//always ends program
}
// ** Need the updated match and next_token (with 2 global vars)
// ** Be sure to put the name of the programmer above each function
// next_token(void)
//    Looks ahead to see what token comes next from the scanner.
//    HOW: checks first to see if the token_available flag is false.
//    If so, saved_token gets scanner() result.
//    and the flag is set true.
//    A token is grabbed but is not eaten up.
//    Returns the saved_token
//   Done by : Clay Flores
tokentype next_token()
{
	if (!token_available)					 // if there is no saved token yet
	{
		scanner(saved_token, saved_lexeme);	 // call scanner to grab a new token
		token_available = true;				 // mark that fact that you have saved it
	}
	return saved_token;    // return the saved token
}

//match(expected)
//		Checks and eats up the expected token.
//		HOW: checks to see if expected is different from next_token()
//		and if so, generates a syntax error and handles the error
//		else token_available becomes false (eat up) and returns true.
bool match(tokentype expected)
{
	if (next_token() != expected)  // mismatch has occurred with the next token
	{ // calls a syntax error function here to  generate a syntax error message here and do recovery
		syntax_error1(expected, saved_lexeme);
	}
	else  // match has occurred
	{
		cout << "Matched " << expected << endl;
		token_available = false;  // eat up the token
		return true;              // say there was a match
	}
}


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
	/*
	cout << "Enter the input file name: ";
	cin >> filename;
	fin.open(filename.c_str());
	*/
	//** calls the <story> to start parsing
	//** closes the input file 

}// end
 //** require no other input files!
 //** syntax error EC requires producing errors.text of messages

