#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

// ** MYTOKEN DFA to be replaced by the WORD DFA
// ** Done by: Clay Flores
// ** RE:
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
	  return(false);
      charpos++;
    }//end of while

  // where did I end up????
  if ((state == 0) || (state == 6))
	{ return(true); }  // end in a final state q0 (0) or q0' (6)
   else return(false);
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
			return true;
		}
		charpos++;
	}
	return false;
}
// -----  Tables -------------------------------------

// ** Update the tokentype to be WORD1, WORD2, PERIOD, ERROR, etc.
// Feel free to add a tokentype for the end-of-file marker.
enum tokentype {ERROR, WORD1, WORD2, PERIOD, VERB, VERBNEG, VERBPAST, VERBPASTNEG, IS, WAS, OBJECT, SUBJECT, DESTINATION, PRONOUN, CONNECTOR, EOFM};

// ** string tokenName[30] = { }; for the display names of tokens

// ** Need the reservedwords table to be set up here. 
// ** Do not require any file input for this.
// ** a.out should work without any additional files.
// these are the hard coded reserved words as well as their token types
// these use the pair data structure to have a string in the first slot and a token type in the second
// a vector of pairs holds them all and is returned by the function
// note about pairs: they use pairname.first or pairname.second to access elements in them
vector<pair<string, tokentype>> reservedWords()
{
	vector<pair<string, tokentype>> reserved[18];
	reservedWords[0].make_pair("masu", VERB);
	reservedWords[1].make_pair("masen", VERBNEG);
	reservedWords[2].make_pair("mashita", VERBPAST);
	reservedWords[3].make_pair("masendeshita", VERBPASTNEG);
	reservedWords[4].make_pair("desu", IS);
	reservedWords[5].make_pair("deshita", WAS);
	reservedWords[6].make_pair("o", OBJECT);
	reservedWords[7].make_pair("wa", SUBJECT);
	reservedWords[8].make_pair("ni", DESTINATION);
	reservedWords[9].make_pair("watashi", PRONOUN);
	reservedWords[10].make_pair("anata", PRONOUN);
	reservedWords[11].make_pair("kare", PRONOUN);
	reservedWords[12].make_pair("kanojo", PRONOUN);
	reservedWords[13].make_pair("sore", PRONOUN);
	reservedWords[14].make_pair("mata", CONNECTOR);
	reservedWords[15].make_pair("soshite", CONNECTOR);
	reservedWords[16].make_pair("shikashi", CONNECTOR);
	reservedWords[17].make_pair("dakara", CONNECTOR);
	reservedWords[18].make_pair("eofm", EOFM);
	return reserved;
}