//
// Created by Eyal on 21/12/18.
//

#ifndef FLIGHT_SLEEPCOMMAND_H
#define FLIGHT_SLEEPCOMMAND_H


#include "Command.h"
#include <unistd.h>
class SleepCommand : public Command{
public:
    SleepCommand(DataReaderServer* server5,Client* client1,Dijkstra* dij,pthread_mutex_t *mut)
            :Command(server5,client1,dij,mut){}
    virtual int doCommand(vector<vector<string>> lines,map<string, double>* map1,int index);
};


#endif //FLIGHT_SLEEPCOMMAND_H
