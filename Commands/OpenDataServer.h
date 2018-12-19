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
#include "pthread.h"

using namespace std;

class OpenDataServer : Command {
public:
    void CreateThread(struct params_to_socket* params);
//    void* CreateSocket (void* pVoid);

    virtual void doCommand(vector<string>::iterator &itor, DataReaderServer* server);
};


#endif //FLIGHTSIMULATOR_OPENDATASERVER_H
