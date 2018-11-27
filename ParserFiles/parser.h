#include "scanner.h"
#include <iostream>
using std::string;
#include "queue.h"

#ifndef __PARSER_H__
#define __PARSER_H__

void setSavedLexeme(string lexeme);
void syntax_error1(tokentype thetype, string saved_lexeme); //when match() function does not match
void syntax_error2(string pFunction, string saved_lexeme);
tokentype next_token();
bool match(tokentype expected);
//10 <tense> := VERBPAST  | VERBPASTNEG | VERB | VERBNEG
void pushParseQueue(string lexeme);

void emptyParseQueue();

void tense();

//9 <be> ::=   IS | WAS
void be();

//8 <verb> ::= WORD2
void verb();

//7 <noun> ::= WORD1 | PRONOUN 
void noun();

//6 <after verb> ::= <tense> PERIOD
void after_verb();

//5 <after destination> ::= <verb> <after verb> PERIOD
void after_destination();

//4 <after object> ::= <verb> <after verb> | <noun> DESTINATION <after destination>
void after_object();

//3 <after noun> ::= <be> PERIOD  | DESTINATION <after destination> | OBJECT <after object>
void after_noun();

//2 <after subject> ::= <verb> <tense> PEROD | <noun> <after noun>
void after_subject();

//1 <s> ::= [CONNECTOR] <noun> SUBJECT <after subject>
void S();
#endif