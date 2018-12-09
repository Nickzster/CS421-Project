#ifndef __TRANSLATOR_H__
#define __TRANSLATOR_H__

#include <iostream>
#include <string>
using std::string;

void getEword(); 

void gen(string line);

void writeBlank(); //Writes a blank to the output file. Used in main, after S() completes.

#endif