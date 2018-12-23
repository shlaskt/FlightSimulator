//
// Created by tomer on 12/19/18.
//

#ifndef FLIGHTSIMULATOR_CONNECTCOMMAND_H
#define FLIGHTSIMULATOR_CONNECTCOMMAND_H

#include "../Dijkstra.h"

#include "Command.h"

class ConnectCommand : public Command {
//    VarDataBase varDataBase;
    int checkValid(string ip, string port_s, Dijkstra shunting_yard, VarDataBase* var_data_base);

public:
    virtual int doCommand(vector<string> line, int i, DataReaderServer *server);
};


#endif //FLIGHTSIMULATOR_CONNECTCOMMAND_H
