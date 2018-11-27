#include <string>
#include <vector>
using std::vector;

#ifndef __SCANNER_H__
#define __SCANNER_H__
    enum tokentype {ERROR, WORD1, WORD2, PERIOD, VERB, VERBNEG, VERBPAST, VERBPASTNEG, IS, WAS, OBJECT, SUBJECT, DESTINATION, PRONOUN, CONNECTOR, EOFM};
    int scanner(tokentype& a, std::string& w);
    bool word(std::string s);
    bool period(std::string s);
    void init();
#endif