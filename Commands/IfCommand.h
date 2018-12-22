//
// Created by tomer on 12/20/18.
//

#ifndef FLIGHTSIMULATOR_IFCOMMAND_H
#define FLIGHTSIMULATOR_IFCOMMAND_H

#include "../Dijkstra.h"

#include "ConditionCommand.h"

class IfCommand :public ConditionCommand{
    VarDataBase varDataBase;
public:
    virtual void doCommand(vector<string>::iterator &itor, DataReaderServer* server);

};


#endif //FLIGHTSIMULATOR_IFCOMMAND_H
