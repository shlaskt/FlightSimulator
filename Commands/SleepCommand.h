//
// Created by tomer on 12/20/18.
//

#ifndef FLIGHTSIMULATOR_SLEEPCOMMAND_H
#define FLIGHTSIMULATOR_SLEEPCOMMAND_H

#include "../Dijkstra.h"

#include "Command.h"

#define MILI_SEC 1000

class SleepCommand : public Command{
//    VarDataBase varDataBase;
public:
    virtual int doCommand(vector<string> line, int i, DataReaderServer *server, VarDataBase* var_data_base);
};


#endif //FLIGHTSIMULATOR_SLEEPCOMMAND_H
