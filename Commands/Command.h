//
// Created by Eyal on 13/12/18.
//

#ifndef FLIGHT_COMMAND_H
#define FLIGHT_COMMAND_H

#include <string>
#include <algorithm>
#include <map>
#include <list>
#include "DataReaderServer.h"
#include "Client.h"
#include "../Dijkstra.h"

using namespace std;

class Command {
protected:
    DataReaderServer *dataServer;
    Client *client;
    Dijkstra *dijkstra;
    pthread_mutex_t *mut;

public:
    Command(DataReaderServer *dataServer, Client *client1, Dijkstra *dijkstra, pthread_mutex_t *mut) {
        this->dataServer = dataServer;
        this->client = client1;
        this->dijkstra = dijkstra;
        this->mut = mut;
    }

    virtual int doCommand(vector<vector<string>> lines, map<string, double> *map1, int index) = 0;
};


#endif //FLIGHT_COMMAND_H
