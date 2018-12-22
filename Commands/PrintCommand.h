//
// Created by tomer on 12/20/18.
//

#ifndef FLIGHTSIMULATOR_PRINTCOMMAND_H
#define FLIGHTSIMULATOR_PRINTCOMMAND_H

#include "../Dijkstra.h"

#include "Command.h"

class PrintCommand : public Command {
    VarDataBase varDataBase;
public:
    virtual void doCommand(vector<string>::iterator &itor, DataReaderServer* server);
};


#endif //FLIGHTSIMULATOR_PRINTCOMMAND_H
