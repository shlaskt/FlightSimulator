//
// Created by eyal on 12/18/18.
//

#ifndef FLIGHTSIMULATOR_DATABASE_H
#define FLIGHTSIMULATOR_DATABASE_H

#include <map>
#include "../ExpressionInterfaces/Expression.h"

using namespace std;

class DataBase {
private:
    map<string, Expression *> commands_map;
    map<string, double> symbol_table;
    map<string, string> paths_map;
};


#endif //FLIGHTSIMULATOR_DATABASE_H
