//
// Created by tomer on 12/20/18.
//

#ifndef FLIGHTSIMULATOR_SLEEPCOMMAND_H
#define FLIGHTSIMULATOR_SLEEPCOMMAND_H

#include "../Dijkstra.h"

#include "Command.h"

#define MILI_SEC 1000

class SleepCommand : public Command{
    VarDataBase varDataBase;
public:
    virtual void doCommand(vector<string>::iterator &itor, DataReaderServer* server);
};


#endif //FLIGHTSIMULATOR_SLEEPCOMMAND_H
