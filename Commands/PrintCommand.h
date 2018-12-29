//
// Created by Tomer & Eyal on 20/12/18.
//

#ifndef FLIGHT_PRINTCOMMAND_H
#define FLIGHT_PRINTCOMMAND_H


#include "Command.h"

using namespace std;
class PrintCommand : public Command{
public:
    PrintCommand(DataReaderServer* server5,Client* client1,Dijkstra* dij,pthread_mutex_t *mut)
            :Command(server5,client1,dij,mut){}
    virtual int doCommand(vector<vector<string>> lines,map<string, double>* symbolTable,int line);

};


#endif //FLIGHT_PRINTCOMMAND_H
