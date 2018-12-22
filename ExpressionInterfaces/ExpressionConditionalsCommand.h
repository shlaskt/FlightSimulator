//
// Created by eyal on 12/21/18.
//

#ifndef FLIGHTSIMULATOR_EXPRESSIONCONITIONALCOMMAND_H
#define FLIGHTSIMULATOR_EXPRESSIONCONITIONALCOMMAND_H


#include <list>
#include "ExpressionCommand.h"
#include "../Commands/ConditionCommand.h"

class ExpressionConditionalsCommand : public Expression {
private:
    ConditionCommand *command;
    vector<string>::iterator &iterator;
    DataReaderServer *reader;
    list<Expression *> command_lists;
public:
    ExpressionConditionalsCommand(ConditionCommand *command, vector<string>::iterator &iterator,
                                  DataReaderServer *reader, list<Expression *> list_c);

    double calculate();
};


#endif //FLIGHTSIMULATOR_EXPRESSIONCONITIONALCOMMAND_H
