

#ifndef FLIGHT_EQUALCOMMAND_H
#define FLIGHT_EQUALCOMMAND_H

#include "Command.h"
#include <pthread.h>

class EqualCommand :public Command{

public:
    virtual int doCommand(vector<string> vec, map<string, double> *map1);
    EqualCommand(DataReaderServer* server5,Client* client1,Dijkstra* dij,pthread_mutex_t *mut)
            :Command(server5,client1,dij,mut){}


};


#endif //FLIGHT_EQUALCOMMAND_H
