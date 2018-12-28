

#ifndef FLIGHT_DEFINEVARCOMMAND_H
#define FLIGHT_DEFINEVARCOMMAND_H

#include "Command.h"

class VarCommand: public Command{
    void checkValidVarName(string var);
public:
    virtual int doCommand(vector<vector<string>> lines,map<string, double>* symbol_table,int index);
    VarCommand(DataReaderServer* data_server,Client* client_data,Dijkstra* dij,pthread_mutex_t *mut)
            :Command(data_server,client_data,dij,mut){}
};

#endif //FLIGHT_DEFINEVARCOMMAND_H
