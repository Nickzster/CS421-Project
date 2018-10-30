#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//=====================================================
// File scanner.cpp written by: Group Number: *16* 
//=====================================================

// --------- DFAs ---------------------------------

//See DFA.cpp. 
#include "DFA.cpp"

// ------------ Scaner and Driver ----------------------- 

ifstream fin;  // global stream for reading from the input file

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

}// end

