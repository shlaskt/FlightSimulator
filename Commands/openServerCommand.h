

#ifndef FLIGHT_OPENSERVERCOMMAND_H
#define FLIGHT_OPENSERVERCOMMAND_H

#include "Command.h"

class openServerCommand: public Command{
private:
    double port;
    double time;

public:
   //int doCommand(list<string>);
   virtual int doCommand(vector<vector<string>> lines,map<string, double>* symbol_table,int index);

    //void* OpenThreadFunc(void* args);
    void* OpenThread(void* pVoid);
    openServerCommand(DataReaderServer* data_server,Client* client_data,Dijkstra* dij,pthread_mutex_t *mut)
            :Command(data_server,client_data,dij,mut){}

};
#endif //FLIGHT_OPENSERVERCOMMAND_H
