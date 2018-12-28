//
// Created by Tomer & Eyal on 21/12/18.
//

#ifndef FLIGHT_SLEEPCOMMAND_H
#define FLIGHT_SLEEPCOMMAND_H


#include "Command.h"
#include <unistd.h>
class SleepCommand : public Command{
public:
    SleepCommand(DataReaderServer* serverData,Client* client1,Dijkstra* dij,pthread_mutex_t *mut)
            :Command(serverData,client1,dij,mut){}
    virtual int doCommand(vector<vector<string>> vector1,map<string, double>* symbol_table,int index);
};


#endif //FLIGHT_SLEEPCOMMAND_H
