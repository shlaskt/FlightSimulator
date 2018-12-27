//
// Created by reut on 16/12/18.
//

#ifndef FLIGHT_PARSER_H
#define FLIGHT_PARSER_H


#include <map>
#include "Command.h"


class Parser {
private:
    map<string,double >* symbolTable;
    map<string, Command*>* commandMap;
public:

    Parser(map<string,double >* symbolTable,map<string, Command*>* commandMap){
        this->symbolTable = symbolTable;
        this->commandMap = commandMap;
    }
    int interpLine(vector<vector<string>>);
    int countLoopIf(vector<vector<string>>);

};


#endif //FLIGHT_PARSER_H
