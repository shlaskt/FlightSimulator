//
// Created by tomer on 12/21/18.
//

#ifndef FLIGHTSIMULATOR_CONDITIONCOMMAND_H
#define FLIGHTSIMULATOR_CONDITIONCOMMAND_H


#include "../Dijkstra.h"
#include "Command.h"
#include "../ExpressionInterfaces/ExpressionCommand.h"

using namespace std;

class ConditionCommand : public Command {
protected: // for if and while commands only
    vector<Expression *> list_of_commands;

    vector<string> getConditionStatement(vector<string> line, int i);

    bool checkCondition(string expression_1, string condition, string expression_2, Dijkstra shunting_yard);

public:
    // pure virtual - cant create condition command without if / while
    void setListOfCommands(vector<Expression *> command_list);

    virtual int doCommand(vector<string> line, int i, DataReaderServer *server, VarDataBase *var_data_base) = 0;
};


#endif //FLIGHTSIMULATOR_CONDITIONCOMMAND_H
