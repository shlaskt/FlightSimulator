//
// Created by Tomer & Eyal on 21/12/18.
//

#ifndef FLIGHT_SLEEPCOMMAND_H
#define FLIGHT_SLEEPCOMMAND_H


#include "Command.h"
#include <unistd.h>
class SleepCommand : public Command{
public:
    SleepCommand(DataReaderServer* data_server,Client* client_data,Dijkstra* dij,pthread_mutex_t *mut)
            :Command(data_server,client_data,dij,mut){}
    virtual int doCommand(vector<vector<string>> lines,map<string, double>* symbol_table,int index);
};


#endif //FLIGHT_SLEEPCOMMAND_H
