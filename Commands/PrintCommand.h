//
// Created by Eyal on 20/12/18.
//

#ifndef FLIGHT_PRINTCOMMAND_H
#define FLIGHT_PRINTCOMMAND_H


#include "Command.h"

class PrintCommand : public Command{
public:
    PrintCommand(DataReaderServer* server5,Client* client1,Dijkstra* dij,pthread_mutex_t *mut)
            :Command(server5,client1,dij,mut){}
    virtual int doCommand(vector<string> vec,map<string, double> *map1);

};


#endif //FLIGHT_PRINTCOMMAND_H
