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
    list<Expression *> list_of_commands;

    vector<string> getConditionStatement(vector<string>::iterator &itor);

    bool checkCondition(string expression_1, string condition, string expression_2, Dijkstra shunting_yard);

public:
    // pure virtual - cant create condition command without if / while
    void setListOfCommands(list<Expression *> command_list);

    virtual void doCommand(vector<string>::iterator &itor, DataReaderServer *server) = 0;
};


#endif //FLIGHTSIMULATOR_CONDITIONCOMMAND_H
