//
// Created by Tomer & Eyal on 20/12/18.
//

#ifndef FLIGHT_PRINTCOMMAND_H
#define FLIGHT_PRINTCOMMAND_H


#include "Command.h"

class PrintCommand : public Command{
public:
    PrintCommand(DataReaderServer* data_server,Client* client_data,Dijkstra* dij,pthread_mutex_t *mut)
            :Command(data_server,client_data,dij,mut){}
    virtual int doCommand(vector<vector<string>> lines,map<string, double>* symbol_table,int index);

};


#endif //FLIGHT_PRINTCOMMAND_H
