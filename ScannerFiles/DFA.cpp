#include <string>
#include <fstream>
#include <iostream>

using namespace std;

// ** MYTOKEN DFA to be replaced by the WORD DFA
// ** Done by:
// ** RE:
bool mytoken(string s)
{
  int state = 0;
  int charpos = 0;

  while (s[charpos] != '\0') 
    {
      if (state == 0 && s[charpos] == 'a')
      state = 1;
      else
      if (state == 1 && s[charpos] == 'b')
      state = 2;
      else
      if (state == 2 && s[charpos] == 'b')
      state = 2;
      else
	  return(false);
      charpos++;
    }//end of while

  // where did I end up????
  if (state == 2) return(true);  // end in a final state
   else return(false);
}

// ** Add the PERIOD DFA here
// ** Done by:

// -----  Tables -------------------------------------

// ** Update the tokentype to be WORD1, WORD2, PERIOD, ERROR, etc.
// Feel free to add a tokentype for the end-of-file marker.
enum tokentype {ERROR, };

// ** string tokenName[30] = { }; for the display names of tokens

// ** Need the reservedwords table to be set up here. 
// ** Do not require any file input for this.
// ** a.out should work without any additional files.
