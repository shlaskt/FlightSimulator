//
// Created by tomer on 12/20/18.
//

#ifndef FLIGHTSIMULATOR_EQUALCOMMAND_H
#define FLIGHTSIMULATOR_EQUALCOMMAND_H

#include "../Dijkstra.h"
#include "Command.h"

class EqualCommand : public Command {
    VarDataBase varDataBase;
public:
    EqualCommand() {};

    virtual void doCommand(vector<string>::iterator &itor, DataReaderServer *server);
};


#endif //FLIGHTSIMULATOR_EQUALCOMMAND_H
