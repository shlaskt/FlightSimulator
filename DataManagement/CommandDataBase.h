//
// Created by eyal on 12/19/18.
//

#ifndef FLIGHTSIMULATOR_COMMANDDATABASE_H
#define FLIGHTSIMULATOR_COMMANDDATABASE_H

#include <map>
#include <vector>
#include "../Commands/Command.h"
#include "../ExpressionInterfaces/ExpressionCommand.h"
#include "../Commands/ConditionCommand.h"
#include "../ExpressionInterfaces/ExpressionConditionalsCommand.h"

using namespace std;

class CommandDataBase {
private:
    map<string, Command *> commands_map;
    map<string, ConditionCommand *> condition_commands_map;
    vector<Expression *> to_delete;

public:
    CommandDataBase();

    ExpressionCommand *getCommand(vector<string>::iterator &it, DataReaderServer *reader);

    ExpressionConditionalsCommand *getConditionCommand(vector<string>::iterator &it,
            DataReaderServer *reader,list<Expression *> command_list);

    ~CommandDataBase();
};

#endif //FLIGHTSIMULATOR_COMMANDDATABASE_H
