//
// Created by eyal on 12/18/18.
//

#ifndef FLIGHTSIMULATOR_INPUTMANAGEMENT_H
#define FLIGHTSIMULATOR_INPUTMANAGEMENT_H

#include <string>
#include <vector>

#include <iostream>
#include <sstream>
#include "ExpressionInterfaces/Expression.h"
#include "DataManagement/CommandDataBase.h"

using namespace std;

vector<string> lexer(string line);

vector<string> parser(string line);
void parserTests();
void lexerTests();

#endif //FLIGHTSIMULATOR_INPUTMANAGEMENT_H
