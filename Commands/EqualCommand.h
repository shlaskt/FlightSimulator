//
// Created by tomer on 12/20/18.
//

#ifndef FLIGHTSIMULATOR_EQUALCOMMAND_H
#define FLIGHTSIMULATOR_EQUALCOMMAND_H

#include "../Dijkstra.h"
#include "Command.h"
#define SPACE ' '
#define RN "\r\n"

class EqualCommand : public Command {
//    VarDataBase varDataBase;
public:
    EqualCommand() {};

    virtual int doCommand(vector<string> line, int i, DataReaderServer *server,Client *client,
            VarDataBase* var_data_base);
};


#endif //FLIGHTSIMULATOR_EQUALCOMMAND_H
