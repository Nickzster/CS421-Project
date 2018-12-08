#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include "scanner.h"
#include "parser.h"
#include "translator.h"

using namespace std;

//---------------------------------------

// The new test driver to start the parser
// Done by:  *Nick Z*
int main()
{
    init(); //for reserved words list
	string w;
	string filename;
    ifstream fin;
	cout << "Enter the input file name: ";
	cin >> filename;
    readFile(filename);
    int numberOfSentences = 1;
	while(true)
	{
        cout << "=======================================" << endl << endl;
        cout << "***READING SENTENCE " << numberOfSentences << "***" <<  endl;
        cout << endl << "=======================================" << endl;
        S();
        cout << "***DONE READING SENTENCE " << numberOfSentences << "***" << endl;
        numberOfSentences++;
	}	
	//** calls the <story> to start parsing
	//** closes the input file 
    cout << "Something went wrong (called from testdriver:main)" << endl;
	return 0;
}// end
 //** require no other input files!
 //** syntax error EC requires producing errors.text of messages