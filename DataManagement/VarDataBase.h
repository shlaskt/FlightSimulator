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
    map<string, double> *symbol_table;
    map<string, string> var_bind;

    void initPathMap();

public:

    // for testing the mutex problem
    map<string, double> *getSymbol_table();

    map<string, double> &getPaths_map();

    map<string, string> &getVar_bind();

    VarDataBase();

    map<string, double> *getSymbolTable();

    void createAndBindVarToPath(string var, string path);

    double getVarValue(string var) const;

    bool isVarExists(string var);

    bool isVarBinded(string var);

    void assignVarValue(string var, double val);

    double getPathValue(string path) const;

    string getPath(string var) const;

    void assignPathValue(string path, double val);

    void updateSymbolTable();

    virtual ~VarDataBase();

};


#endif //FLIGHTSIMULATOR_VarDataBase_H
