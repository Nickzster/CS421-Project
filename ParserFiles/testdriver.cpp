#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include "scanner.h"
#include "parser.h"

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
	fin.open(filename.c_str());
	while(true)
	{
        fin >> w;
        if (w == "eofm")
        {
            break;
        }
        while(true)
        {
        pushParseQueue(w);
            if (w == ".")
            {
                break;
            }
            else
            {
                fin>>w;
            }
        }
        S();
        emptyParseQueue();
	}	
	//** calls the <story> to start parsing
	//** closes the input file 
    cout << "SUCCESSFULLY PARSED STORY!" << endl;
	return 0;
}// end
 //** require no other input files!
 //** syntax error EC requires producing errors.text of messages