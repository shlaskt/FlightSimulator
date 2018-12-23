//
// Created by tomer on 12/18/18.
//

#ifndef FLIGHTSIMULATOR_OPENDATASERVER_H
#define FLIGHTSIMULATOR_OPENDATASERVER_H

#include <thread>

#include <iostream>
#include <string>
#include "Command.h"
#include "../Sockets/DataReaderServer.h"
#include "../Dijkstra.h"
#include "pthread.h"
#include <pthread.h>

using namespace std;

class OpenDataServer : public Command {
//    VarDataBase varDataBase;

    void CreateThread(struct params_to_socket *params);

    struct params_to_socket *initParams(double i_port, double i_time,
            DataReaderServer *server);

public:
    OpenDataServer(){};

    virtual int doCommand(vector<string> line, int i, DataReaderServer *server, VarDataBase* var_data_base);
};


#endif //FLIGHTSIMULATOR_OPENDATASERVER_H
