//
// Created by Eyal on 16/12/18.
//

#ifndef FLIGHT_PARSER_H
#define FLIGHT_PARSER_H


#include <map>
#include "Commands/Command.h"
#include "InputReader/InputReader.h"
#include <fstream>
#include <string.h>
#include <map>
#include <list>


class Interpreter {
private:
    map<string, double> *symbolTable;
    map<string, Command *> *commandMap;
public:

    Interpreter(map<string, double> *symbolTable, map<string, Command *> *commandMap);

    vector<string> parser(string line);

    bool interpreteFile(vector<vector<string>>);

    int countLoopIf(vector<vector<string>>);

    vector<string> lexer(string line);

    vector<vector<string>> readFromFile(InputReader *inputReader);

};


#endif //FLIGHT_PARSER_H
