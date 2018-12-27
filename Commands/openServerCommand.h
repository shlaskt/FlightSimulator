

#ifndef FLIGHT_OPENSERVERCOMMAND_H
#define FLIGHT_OPENSERVERCOMMAND_H

#include "Command.h"

class openServerCommand: public Command{
private:
    double port;
    double time;

public:
   //int doCommand(list<string>);
   virtual int doCommand(vector<vector<string>> vector1,map<string, double>* map1,int index);

    //void* OpenThreadFunc(void* args);
    void* OpenThread(void* pVoid);
    openServerCommand(DataReaderServer* server5,DataClient* dataClient1,Dijkstra* dij,pthread_mutex_t *mut)
            :Command(server5,dataClient1,dij,mut){}

};
#endif //FLIGHT_OPENSERVERCOMMAND_H
