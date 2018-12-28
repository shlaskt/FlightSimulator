

#ifndef FLIGHT_DEFINEVARCOMMAND_H
#define FLIGHT_DEFINEVARCOMMAND_H

#include "Command.h"

class DefineVarCommand: public Command{
public:
    virtual int doCommand(vector<vector<string>> vector1,map<string, double>* symbol_table,int index);
    DefineVarCommand(DataReaderServer* server5,Client* client1,Dijkstra* dij,pthread_mutex_t *mut)
            :Command(server5,client1,dij,mut){}


};

#endif //FLIGHT_DEFINEVARCOMMAND_H
