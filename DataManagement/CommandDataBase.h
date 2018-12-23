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
#include "../Commands/ConnectCommand.h"
#include "../Commands/OpenDataServer.h"
#include "../Commands/EqualCommand.h"
#include "../Commands/IfCommand.h"
#include "../Commands/WhileCommand.h"
#include "../Commands/PrintCommand.h"
#include "../Commands/SleepCommand.h"
#include "../Commands/VarCommand.h"
#include "../Sockets/Client.h"
using namespace std;

class CommandDataBase {
private:
    map<string, Command *> commands_map;
    map<string, ConditionCommand *> condition_commands_map;
    vector<Expression *> to_delete;

public:
    CommandDataBase();

    ExpressionCommand *getCommand(vector<string> vec,int index, DataReaderServer *reader,
            Client *client,VarDataBase *varDataBase
    );

    ExpressionConditionalsCommand *getConditionCommand(vector<string> vec,int index,
            DataReaderServer *reader,Client *client,vector<Expression *> command_list,VarDataBase *varDataBase);

    ~CommandDataBase();
};

#endif //FLIGHTSIMULATOR_COMMANDDATABASE_H
