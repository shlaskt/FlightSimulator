//
// Created by eyal on 12/18/18.
//

#ifndef FLIGHTSIMULATOR_DATABASE_H
#define FLIGHTSIMULATOR_DATABASE_H

#include <map>
#include <vector>
#include "../ExpressionInterfaces/Expression.h"

using namespace std;

class VarDataBase {
private:
    map<string, double> paths_map;
    map<string, double> symbol_table;
    map<string, string> var_bind;

    void initPathMap();

public:
    VarDataBase();

    const map<string, double> &getSymbolTable() const;

    void createAndBindVarToPath(string var, string path);

    double getVarValue(string var) const;

    void assignVarValue(string var, double val);

    double getPathValue(string path) const;

    void assignPathValue(string path, double val);

    void updateSymbolTable();

};


#endif //FLIGHTSIMULATOR_VarDataBase_H
