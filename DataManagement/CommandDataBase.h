//
// Created by eyal on 12/19/18.
//

#ifndef FLIGHTSIMULATOR_COMMANDDATABASE_H
#define FLIGHTSIMULATOR_COMMANDDATABASE_H

#include <map>
#include <vector>
#include "../Commands/Command.h"
#include "../ExpressionInterfaces/ExpressionCommand.h"

using namespace std;

class CommandDataBase {
private:
    map<string, Command *> commands_map;
    vector<ExpressionCommand *> to_delete;

public:
    CommandDataBase();

    ExpressionCommand *getCommand(vector<string>::iterator &it, DataReaderServer *reader);


    ~CommandDataBase();
};

#endif //FLIGHTSIMULATOR_COMMANDDATABASE_H
