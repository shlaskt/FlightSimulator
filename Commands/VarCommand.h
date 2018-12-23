//
// Created by tomer on 12/20/18.
//

#ifndef FLIGHTSIMULATOR_VARCOMMAND_H
#define FLIGHTSIMULATOR_VARCOMMAND_H

#include "../Dijkstra.h"

#include "Command.h"

class VarCommand : public Command{
    VarDataBase varDataBase;
public:
    virtual int doCommand(vector<string> line, int i, DataReaderServer *server);

};


#endif //FLIGHTSIMULATOR_VARCOMMAND_H
