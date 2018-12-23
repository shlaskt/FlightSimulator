//
// Created by tomer on 12/20/18.
//

#ifndef FLIGHTSIMULATOR_PRINTCOMMAND_H
#define FLIGHTSIMULATOR_PRINTCOMMAND_H

#include "../Dijkstra.h"

#include "Command.h"

class PrintCommand : public Command {
    // VarDataBase varDataBase;
public:
    virtual int doCommand(vector<string> line, int i, DataReaderServer *server, VarDataBase* var_data_base);
};


#endif //FLIGHTSIMULATOR_PRINTCOMMAND_H
