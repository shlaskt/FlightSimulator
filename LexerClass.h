//
// Created by reut on 13/12/18.
//

#ifndef FLIGHT_LEXER_H
#define FLIGHT_LEXER_H
#include <string>
#include <algorithm>
#include <map>
#include <list>
#include <vector>

using namespace std;

class LexerClass {

public:
    vector<string> Lexer();
    vector<string> splitToCommand(string line);
    vector<vector<string>> readFromFile(string fileName);
    };


#endif //FLIGHT_LEXER_H
