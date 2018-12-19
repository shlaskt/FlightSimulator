//
// Created by eyal on 12/18/18.
//

#ifndef FLIGHTSIMULATOR_DATABASE_H
#define FLIGHTSIMULATOR_DATABASE_H

#include <map>
#include <vector>
#include <list>
#include "../Sockets/DataReaderServer.h"
#include "../ExpressionInterfaces/Expression.h"
#include "../ExpressionInterfaces/ExpressionCommand.h"

using namespace std;

class VarDataBase {
private:
    map<string, Command *> commands_map;
    map<string, double> paths_map;
    map<string, double> symbol_table;
    map<string, string> var_bind;
    vector<ExpressionCommand *> to_delete;

    void initMaps();

public:
    VarDataBase();

    ExpressionCommand *getCommand(vector<string>::iterator &it, DataReaderServer &reader);

    void createAndBindVarToPath(string var, string path);

    double getVarValue(string var);

    void assignVarValue(string var, double val);

    double getPathValue(string path);

    void assignPathValue(string path, double val);
};


#endif //FLIGHTSIMULATOR_VarDataBase_H
