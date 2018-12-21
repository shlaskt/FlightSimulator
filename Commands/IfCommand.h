//
// Created by tomer on 12/20/18.
//

#ifndef FLIGHTSIMULATOR_IFCOMMAND_H
#define FLIGHTSIMULATOR_IFCOMMAND_H

#include "../Dijkstra.h"

#include "Command.h"

class IfCommand : Command{
    VarDataBase varDataBase;
    bool checkCondition(double, string, double);
public:
    virtual void doCommand(vector<string>::iterator &itor, DataReaderServer* server);

};


#endif //FLIGHTSIMULATOR_IFCOMMAND_H
