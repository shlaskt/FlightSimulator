//
// Created by Tomer & Eyal on 13/12/18.
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

class Command
{
protected:
    DataReaderServer* server;
    Client* client;
    Dijkstra* shunting_yard;
    pthread_mutex_t *mut;

public:
    /*
     * Ctor for the interface - all the sucsseors have the same.
     */
    Command(DataReaderServer* server,Client* client,Dijkstra* shunting_yard,pthread_mutex_t *mut){
        this->server = server;
        this->client = client;
        this->shunting_yard = shunting_yard;
        this->mut = mut;
    }
    virtual int doCommand(vector<vector<string>> lines,map<string, double>* symbolTable,int line)=0;
};


#endif //FLIGHT_COMMAND_H
