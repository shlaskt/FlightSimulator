//
// Created by tomer on 12/20/18.
//

#ifndef FLIGHTSIMULATOR_IFCOMMAND_H
#define FLIGHTSIMULATOR_IFCOMMAND_H

#include "../Dijkstra.h"

#include "ConditionCommand.h"

class IfCommand :public ConditionCommand{
//    VarDataBase varDataBase;
public:
    virtual int doCommand(vector<string> line, int i, DataReaderServer *server,
            Client *client, VarDataBase* var_data_base);

};


#endif //FLIGHTSIMULATOR_IFCOMMAND_H
