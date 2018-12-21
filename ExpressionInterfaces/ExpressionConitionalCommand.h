//
// Created by eyal on 12/21/18.
//

#ifndef FLIGHTSIMULATOR_EXPRESSIONCONITIONALCOMMAND_H
#define FLIGHTSIMULATOR_EXPRESSIONCONITIONALCOMMAND_H


#include <list>
#include "ExpressionCommand.h"

class ExpressionConitionalCommand: public Expression {
private:
    Command *command;
    vector<string>::iterator iterator;
    DataReaderServer &reader;
    list<ExpressionCommand *> command_lists;
public:
    ExpressionConitionalCommand(Command *command,vector<string>::iterator &iterator,
            DataReaderServer &reader,list<ExpressionCommand *> list_c);

    double calculate();
};


#endif //FLIGHTSIMULATOR_EXPRESSIONCONITIONALCOMMAND_H
