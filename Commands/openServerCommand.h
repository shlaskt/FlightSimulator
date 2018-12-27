

#ifndef FLIGHT_OPENSERVERCOMMAND_H
#define FLIGHT_OPENSERVERCOMMAND_H

#include "Command.h"

class openServerCommand: public Command{
private:
    double port;
    double time;

public:
   //int doCommand(list<string>);
   virtual int doCommand(vector<string> vec,map<string, double> *map1);

    //void* OpenThreadFunc(void* args);
    void* OpenThread(void* pVoid);
    openServerCommand(DataReaderServer* server5,Client* client1,Dijkstra* dij,pthread_mutex_t *mut)
            :Command(server5,client1,dij,mut){}

};
#endif //FLIGHT_OPENSERVERCOMMAND_H
