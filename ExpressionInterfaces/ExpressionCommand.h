//
// Created by eyal on 12/18/18.
//

#ifndef FLIGHTSIMULATOR_EXPRESSIONCOMMAND_H
#define FLIGHTSIMULATOR_EXPRESSIONCOMMAND_H


#include "../Commands/Command.h"
#include "Expression.h"
#include "../Sockets/DataReaderServer.h"
#include <vector>

class ExpressionCommand : Expression {
private:
    Command *command;
    vector<string>::iterator iterator;
    DataReaderServer &reader;

public:
    ExpressionCommand(Command *command,vector<string>::iterator &iterator, DataReaderServer &reader);

    double calculate();

};


#endif //FLIGHTSIMULATOR_EXPRESSIONCOMMAND_H
