//
// Created by eyal on 12/21/18.
//

#ifndef FLIGHTSIMULATOR_EXPRESSIONCONITIONALCOMMAND_H
#define FLIGHTSIMULATOR_EXPRESSIONCONITIONALCOMMAND_H


#include <list>
#include <vector>
#include "ExpressionCommand.h"
#include "../Commands/ConditionCommand.h"

class ExpressionConditionalsCommand : public Expression {
private:
    ConditionCommand *command;
    vector<string> vec;
    int index;
    DataReaderServer *reader;
    list<Expression *> command_lists;
    VarDataBase *varDataBase;
public:
    ExpressionConditionalsCommand(ConditionCommand *command, vector<string> vec, int index,
                                  DataReaderServer *reader, list<Expression *> command_lists,VarDataBase *vdb);

    double calculate();
};


#endif //FLIGHTSIMULATOR_EXPRESSIONCONITIONALCOMMAND_H
