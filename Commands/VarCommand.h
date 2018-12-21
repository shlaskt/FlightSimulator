//
// Created by tomer on 12/20/18.
//

#ifndef FLIGHTSIMULATOR_VARCOMMAND_H
#define FLIGHTSIMULATOR_VARCOMMAND_H

#include "../Dijkstra.h"

#include "Command.h"

class VarCommand : Command{
    VarDataBase varDataBase;
public:
    virtual void doCommand(vector<string>::iterator &itor, DataReaderServer* server);

};


#endif //FLIGHTSIMULATOR_VARCOMMAND_H
