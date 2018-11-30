#include <iostream>
#include <fstream>
#include <string>
#include "scanner.h"

using namespace std;

//=====================================================
// File scanner.cpp written by: Group Number: *16* 
//=====================================================

// --------- DFAs ---------------------------------
string w;
ifstream fin;

void readFile(string filename)
{
	fin.open(filename.c_str());
    //fin >> w;
	cout << "Successfully opened " << filename << " initalizing to: " << w << endl;
}

void closeFile()
{
	fin.close();
}

// ** MYTOKEN DFA to be replaced by the WORD DFA
// ** Done by: Clay Flores
// ** RE: 
// (b|g|h|k|m|n|p|r) (y ((a|e|i|o|u|E|I)^+ | (a|e|i|o|u|E|I)^+ n) | (a|e|i|o|u|E|I)^+ | (a|e|i|o|u|E|I)^+ n)
// (a|e|i|o|u|E|I)^+ | (a|e|o|i|u|E|I)^+ n
// (d|j|w|y|z) ( (a|e|i|o|u|E|I)^+ | (a|e|i|o|u|E|I)^+ n)
// s ( h ( (a|e|i|o|u|E|I)^+ | (a|e|i|o|u|E|I)^+ n) ) | ( (a|e|i|o|u|I|E)^+ |  (a|e|i|o|u|I|E)^+ n) )
// t ( s ( (a|e|i|o|u|I|E)^+ | (a|e|i|o|u|I|E)^+ n) ) ) | ( (a|e|i|o|u|I|E)^+ | (a|e|i|o|u|I|E)^+ n )
// c h ( (a|e|i|o|u|I|E)^+ | (a|e|i|o|u|I|E)^+ n)

bool word(string s)
{

	int state = 0;
	int charpos = 0;

	while (s[charpos] != '\0')
	{
		// THE STATES ARE AS FOLLOWS:
		//		   q0  == 0
		//	   conson  == 1
		//		 pair  == 2
		//			s  == 3
		//			t  == 4
		//          c  == 5
		//          q1 == 6

		// q0 
		// conson = (d|j|w|y)
		if (state == 0 && s[charpos] == 'd')
			state = 1;
		else if (state == 0 && s[charpos] == 'j')
			state = 1;
		else if (state == 0 && s[charpos] == 'w')
			state = 1;
		else if (state == 0 && s[charpos] == 'y')
			state = 1;
		// pair = (b|g|h|k|m|n|p|r)
		else if (state == 0 && s[charpos] == 'b')
			state = 2;
		else if (state == 0 && s[charpos] == 'g')
			state = 2;
		else if (state == 0 && s[charpos] == 'h')
			state = 2;
		else if (state == 0 && s[charpos] == 'k')
			state = 2;
		else if (state == 0 && s[charpos] == 'm')
			state = 2;
		else if (state == 0 && s[charpos] == 'n')
			state = 2;
		else if (state == 0 && s[charpos] == 'p')
			state = 2;
		else if (state == 0 && s[charpos] == 'r')
			state = 2;
		// s path = s
		else if (state == 0 && s[charpos] == 's')
			state = 3;
		// t path = t
		else if (state == 0 && s[charpos] == 't')
			state = 4;
		// c path = c
		else if (state == 0 && s[charpos] == 'c')
			state = 5;
		// q0' = (a|e|i|o|u|E|I)
		else if (state == 0 && s[charpos] == 'a')
			state = 6;
		else if (state == 0 && s[charpos] == 'e')
			state = 6;
		else if (state == 0 && s[charpos] == 'i')
			state = 6;
		else if (state == 0 && s[charpos] == 'E')
			state = 6;
		else if (state == 0 && s[charpos] == 'I')
			state = 6;
		else if (state == 0 && s[charpos] == 'o')
			state = 6;
		else if (state == 0 && s[charpos] == 'u')
			state = 6;
		// conson 
		// q0' = (a|e|i|o|u|E|I)
		else if (state == 1 && s[charpos] == 'a')
			state = 6;
		else if (state == 1 && s[charpos] == 'e')
			state = 6;
		else if (state == 1 && s[charpos] == 'i')
			state = 6;
		else if (state == 1 && s[charpos] == 'E')
			state = 6;
		else if (state == 1 && s[charpos] == 'I')
			state = 6;
		else if (state == 1 && s[charpos] == 'o')
			state = 6;
		else if (state == 1 && s[charpos] == 'u')
			state = 6;
		// pair
		// conson = y
		else if (state == 2 && s[charpos] == 'y')
			state = 1;
		// q0' = (a|e|i|o|u|E|I)
		else if (state == 2 && s[charpos] == 'a')
			state = 6;
		else if (state == 2 && s[charpos] == 'e')
			state = 6;
		else if (state == 2 && s[charpos] == 'i')
			state = 6;
		else if (state == 2 && s[charpos] == 'E')
			state = 6;
		else if (state == 2 && s[charpos] == 'I')
			state = 6;
		else if (state == 2 && s[charpos] == 'o')
			state = 6;
		else if (state == 2 && s[charpos] == 'u')
			state = 6;
		// s 
		// conson = h
		else if (state == 3 && s[charpos] == 'h')
			state = 1;
		// q0' = (a|e|i|o|u|E|I)
		else if (state == 3 && s[charpos] == 'a')
			state = 6;
		else if (state == 3 && s[charpos] == 'e')
			state = 6;
		else if (state == 3 && s[charpos] == 'i')
			state = 6;
		else if (state == 3 && s[charpos] == 'E')
			state = 6;
		else if (state == 3 && s[charpos] == 'I')
			state = 6;
		else if (state == 3 && s[charpos] == 'o')
			state = 6;
		else if (state == 3 && s[charpos] == 'u')
			state = 6;
		// t
		// conson = s
		else if (state == 4 && s[charpos] == 's')
			state = 1;
		// q0' = (a|e|i|o|u|E|I)
		else if (state == 4 && s[charpos] == 'a')
			state = 6;
		else if (state == 4 && s[charpos] == 'e')
			state = 6;
		else if (state == 4 && s[charpos] == 'i')
			state = 6;
		else if (state == 4 && s[charpos] == 'E')
			state = 6;
		else if (state == 4 && s[charpos] == 'I')
			state = 6;
		else if (state == 4 && s[charpos] == 'o')
			state = 6;
		else if (state == 4 && s[charpos] == 'u')
			state = 6;
		// c
		// conson = h
		else if (state == 5 && s[charpos] == 'h')
			state = 1;
		// q0'
		// q0' = (a|e|i|o|u|E|I)^*
		else if (state == 6 && s[charpos] == 'a')
			state = 6;
		else if (state == 6 && s[charpos] == 'e')
			state = 6;
		else if (state == 6 && s[charpos] == 'i')
			state = 6;
		else if (state == 6 && s[charpos] == 'o')
			state = 6;
		else if (state == 6 && s[charpos] == 'u')
			state = 6;
		else if (state == 6 && s[charpos] == 'E')
			state = 6;
		else if (state == 6 && s[charpos] == 'I')
			state = 6;

		// q0 = n
		else if (state == 6 && s[charpos] == 'n')
			state = 0;
		// conson = (d|j|w|y|z)
		else if (state == 6 && s[charpos] == 'd')
			state = 1;
		else if (state == 6 && s[charpos] == 'j')
			state = 1;
		else if (state == 6 && s[charpos] == 'w')
			state = 1;
		else if (state == 6 && s[charpos] == 'y')
			state = 1;
		else if (state == 6 && s[charpos] == 'z')
			state = 1;
		// pair = (b|g|h|k|m|n|p|r)
		else if (state == 6 && s[charpos] == 'b')
			state = 2;
		else if (state == 6 && s[charpos] == 'g')
			state = 2;
		else if (state == 6 && s[charpos] == 'h')
			state = 2;
		else if (state == 6 && s[charpos] == 'k')
			state = 2;
		else if (state == 6 && s[charpos] == 'm')
			state = 2;
		else if (state == 6 && s[charpos] == 'n')
			state = 2;
		else if (state == 6 && s[charpos] == 'p')
			state = 2;
		else if (state == 6 && s[charpos] == 'r')
			state = 2;
		// s path = s
		else if (state == 6 && s[charpos] == 's')
			state = 3;
		// t path = t
		else if (state == 6 && s[charpos] == 't')
			state = 4;
		// c path = c
		else if (state == 6 && s[charpos] == 'c')
			state = 5;
		else
			return ERROR;
		charpos++;
	}//end of while

	 // where did I end up????
	if (state == 0)
	{
		return WORD1;
	}
	else if (state == 6)  // end in a final state q0 (0) or q0' (6)
	{
		return WORD2;
	}
	else
		return ERROR;

}

// ** Add the PERIOD DFA here
// ** Done by: Clay Flores
bool period(string s)
{
	int state = 0;
	int charpos = 0;

	while (s[charpos] != '\0')
	{
		// logic to say that if the char is a period and there is no next char
		if ((s[charpos] == '.') && (s[charpos + 1] == '\0'))
		{
			return PERIOD;
		}
		charpos++;
	}
	return ERROR;
}
// -----  Tables -------------------------------------

// ** Update the tokentype to be WORD1, WORD2, PERIOD, ERROR, etc.
// Feel free to add a tokentype for the end-of-file marker.

string tokenName[30] = { "ERROR", "WORD1", "WORD2", "PERIOD", "VERB", "VERBNEG", "VERBPAST", "VERBPASTNEG", "IS", "WAS", "OBJECT", "SUBJECT", "DESTINATION", "PRONOUN", "CONNECTOR", "EOFM" }; //for the display names of tokens

// ** Need the reservedwords table to be set up here. 
// ** Do not require any file input for this.
// ** a.out should work without any additional files.
struct reservedWord
{
	string WORD;
	tokentype TYPE;
};

vector <reservedWord> reservedWordsList;
// these are the hard coded reserved words as well as their token types
// these use the pair data structure to have a string in the first slot and a token type in the second
// a vector of pairs holds them all and is returned by the function
// note about pairs: they use pairname.first or pairname.second to access elements in them

void init()
{

	reservedWord r;
	r.WORD = "masu";
	r.TYPE = VERB;
	reservedWordsList.push_back(r);

	r.WORD = "masen";
	r.TYPE = VERBNEG;
	reservedWordsList.push_back(r);

	r.WORD = "mashita";
	r.TYPE = VERBPAST;
	reservedWordsList.push_back(r);


	r.WORD = "masendeshita";
	r.TYPE = VERBPASTNEG;
	reservedWordsList.push_back(r);


	r.WORD = "desu";
	r.TYPE = IS;
	reservedWordsList.push_back(r);


	r.WORD = "deshita";
	r.TYPE = WAS;
	reservedWordsList.push_back(r);


	r.WORD = "o";
	r.TYPE = OBJECT;
	reservedWordsList.push_back(r);


	r.WORD = "wa";
	r.TYPE = SUBJECT;
	reservedWordsList.push_back(r);


	r.WORD = "ni";
	r.TYPE = DESTINATION;
	reservedWordsList.push_back(r);


	r.WORD = "watashi";
	r.TYPE = PRONOUN;
	reservedWordsList.push_back(r);


	r.WORD = "anata";
	r.TYPE = PRONOUN;
	reservedWordsList.push_back(r);


	r.WORD = "kare";
	r.TYPE = PRONOUN;
	reservedWordsList.push_back(r);


	r.WORD = "kanojo";
	r.TYPE = PRONOUN;
	reservedWordsList.push_back(r);


	r.WORD = "sore";
	r.TYPE = PRONOUN;
	reservedWordsList.push_back(r);


	r.WORD = "mata";
	r.TYPE = CONNECTOR;
	reservedWordsList.push_back(r);


	r.WORD = "soshite";
	r.TYPE = CONNECTOR;
	reservedWordsList.push_back(r);


	r.WORD = "shikashi";
	r.TYPE = CONNECTOR;
	reservedWordsList.push_back(r);


	r.WORD = "dakara";
	r.TYPE = CONNECTOR;
	reservedWordsList.push_back(r);



	r.WORD = "eofm";
	r.TYPE = EOFM;
	reservedWordsList.push_back(r);
}

// ------------ Scaner and Driver ----------------------- 

//ifstream fin;  // global stream for reading from the input file

// Scanner processes only one word each time it is called
// Gives back the token type and the word itself
// ** Done by: Nick Zimmermann
 
int scanner(tokentype& a, string& w)
{

  // ** Grab the next word from the file via fin
  fin >> w;
  
  // 2. Call the token functions one after another (if-then-else)
  if(word(w)) //if it is in the regular DFA
  {
    if(w.at(w.size()-1) == 'I' || w.at(w.size()-1) == 'E') //if the word ends in I or E
    { //then the expression is WORD2
      a = WORD2;
    }
    else //otherwise, it is WORD1
    { 
      a = WORD1;
    }
    //if it is a reserved word, then overwrite the token type.
    for(int i = 0; i < reservedWordsList.size(); i++)
    {
      reservedWord r = reservedWordsList.at(i);
      if(r.WORD == w) //if the word is found in the reserved list
      {
        a = r.TYPE; //then append its token type
        break; 
      }
    }
  }
  else if(period(w)) //if it is in the period DFA
  {
    a = PERIOD;
    // for(int i = 0; i < reservedWordsList.size(); i++)
    // {
    //   reservedWord r = reservedWordsList.at(i);
    //   if(r.WORD == w) //if the word is found in the reserved list
    //   {
    //     a = r.TYPE; //then append its token type
    //     break; 
    //   }
    // }
  }
  else //if it is not found in any of the word DFA's
  {
    a = ERROR;
  }

  if(a == ERROR)
  {
    cout << "***Lexical Error: " << w << " is not a valid token." << "***" << endl;
  }

    return 1;
  //    And generate a lexical error message if both DFAs failed.
  //    Let the token_type be ERROR in that case.
  // 3. Make sure WORDs are checked against the reservedwords list
  //    If not reserved, token_type is WORD1 or WORD2.
  // 4. Return the token type & string  (pass by reference)
  


}//the end of scanner


/*
// The temporary test driver to just call the scanner repeatedly  
// This will go away after this assignment
// DO NOT CHANGE THIS!!!!!! 
// Done by:  Rika
int main()
{
  tokentype thetype;
  init();
  string theword; 
  string filename;

  cout << "Enter the input file name: ";
  cin >> filename;

  fin.open(filename.c_str());

  // the loop continues until eofm is returned.
   while (true)
    {
       scanner(thetype, theword);  // call the scanner
       if (theword == "eofm") break;  // stop now
       cout << "========================================" << endl;
       cout << "Type is:" << tokenName[thetype] << endl;
       cout << "Word is:" << theword << endl;   
       cout << "========================================" << endl << endl;
    }

   cout << "End of file is encountered." << endl;
   fin.close();

}// end */