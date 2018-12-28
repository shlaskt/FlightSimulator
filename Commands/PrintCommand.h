//
// Created by Tomer & Eyal on 20/12/18.
//

#ifndef FLIGHT_PRINTCOMMAND_H
#define FLIGHT_PRINTCOMMAND_H


#include "Command.h"

class PrintCommand : public Command{
public:
    PrintCommand(DataReaderServer* serverData,Client* client1,Dijkstra* dij,pthread_mutex_t *mut)
            :Command(serverData,client1,dij,mut){}
    virtual int doCommand(vector<vector<string>> vector1,map<string, double>* symbol_table,int index);

};


#endif //FLIGHT_PRINTCOMMAND_H
