//
// Created by reut on 13/12/18.
//

#ifndef FLIGHT_COMMAND_H
#define FLIGHT_COMMAND_H
#include <string>
#include <algorithm>
#include <map>
#include <list>
#include "DataReaderServer.h"
#include "DataClient.h"
#include "Dijkstra.h"
using namespace std;

class Command
{
protected:
    DataReaderServer* server1;
    DataClient* dataClient;
    Dijkstra* dijkstra1;
    pthread_mutex_t *mut;

public:
    Command(DataReaderServer* server2,DataClient* dataClient1,Dijkstra* dijkstra,pthread_mutex_t *mut){
        this->server1 = server2;
        this->dataClient = dataClient1;
        this->dijkstra1 = dijkstra;
        this->mut = mut;
    }
    virtual int doCommand(vector<vector<string>> vector1,map<string, double>* map1,int index)=0;
};


#endif //FLIGHT_COMMAND_H
