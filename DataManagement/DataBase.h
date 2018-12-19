//
// Created by eyal on 12/18/18.
//

#ifndef FLIGHTSIMULATOR_DATABASE_H
#define FLIGHTSIMULATOR_DATABASE_H

#include <map>
#include <vector>
#include "../Sockets/DataReaderServer.h"
#include "../ExpressionInterfaces/Expression.h"
#include "../ExpressionInterfaces/ExpressionCommand.h"

using namespace std;

class DataBase {
private:
    map<string, Command *> commands_map;
    map<string, double> paths_map;
    map<string, double> symbol_table;
    map<string, string> var_bind;
    void initMaps();

public:
    DataBase();

    double getVarValue(string var);
    ExpressionCommand * getCommand(const vector<string>::iterator &it, DataReaderServer rd);
};


#endif //FLIGHTSIMULATOR_DATABASE_H
