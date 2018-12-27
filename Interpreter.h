//
// Created by Eyal on 16/12/18.
//

#ifndef FLIGHT_PARSER_H
#define FLIGHT_PARSER_H

#include <fstream>
#include <string.h>
#include <list>
#include <map>
#include "Commands/Command.h"
#include "InputReader/InputReader.h"
#include "Commands/ConditionCommand.h"

class Interpreter {
private:
    map<string, double> *symbolTable;
    map<string, Command *> *commandMap;
    map<string, ConditionCommand *> *connditionMap;
    InputReader *reader;
public:

    Interpreter(map<string, double> *symbolTable, map<string, Command *> *commandMap,
                map<string, ConditionCommand *> *connditionMap1, InputReader *reader);

    Command *interprateLine(vector<string> parsered_line);

    bool CheckValidityOfConditionCommand(vector<string> &vec);

    vector<Command *> conditionParser(bool find_parenthesis);

    vector<string> lexer(string line);

    vector<string> parser(string line);

    vector<vector<string>> readFromFile(string fileName);

};


#endif //FLIGHT_PARSER_H
