#include "scanner.h"
#include <iostream>
using std::string;

#ifndef __PARSER_H__
#define __PARSER_H__

void setSavedLexeme(string lexeme); //Sets the saved lexeme.
string getCurrentLexeme(); //Gets the current lexeme. Used by translator.
string getCurrentToken(); //Gets the current token. Used by translator.
void syntax_error1(tokentype thetype, string saved_lexeme); //when match() function does not match
void syntax_error2(string pFunction, string saved_lexeme); //When we hit a "default" in a switch.
tokentype next_token();
bool match(tokentype expected);

//10 <tense> := VERBPAST  | VERBPASTNEG | VERB | VERBNEG
void tense();

//9 <be> ::=   IS | WAS
void be();

//8 <verb> ::= WORD2
void verb();

//7 <noun> ::= WORD1 | PRONOUN 
void noun();

//6 <after verb> ::= <tense> #gen("TENSE")# PERIOD
void after_verb();

//5 <after destination> ::= <verb> #getEword# #gen("ACTION")# <after verb>
void after_destination();

//4 <after object> ::= <verb> #getEword# #gen("ACTION")# <after verb> | <noun> #getEword# DESTINATION #gen("TO")# <after destination>
void after_object();

//3 <after noun> ::= <be> #gen("DESCRIPTION")# #gen("TENSE")# PERIOD  | #getEword# DESTINATION #gen("TO")# <after destination> | OBJECT #gen("OBJECT")# <after object>
void after_noun();

//2 <after subject> ::= <verb> #getEword# #gen("ACTION")# <tense> #gen("TENSE")# PERIOD | <noun> #getEword# <after noun>
void after_subject();

//1 <s> ::= [CONNECTOR #getEword# #gen("CONNECTOR")#] <noun> #getEword# SUBJECT #gen("ACTOR")# <after subject>
void S();

#endif