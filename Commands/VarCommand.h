

#ifndef FLIGHT_VARCOMMAND_H
#define FLIGHT_VARCOMMAND_H

#include "Command.h"

class VarCommand: public Command{
    void checkValidVarName(string var);
public:
    virtual int doCommand(vector<vector<string>> lines,map<string, double>* symbolTable,int line);
    VarCommand(DataReaderServer* server5,Client* client1,Dijkstra* dij,pthread_mutex_t *mut)
            :Command(server5,client1,dij,mut){}
};

#endif //FLIGHT_VARCOMMAND_H
