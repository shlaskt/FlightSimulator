

#ifndef FLIGHT_EQUALCOMMAND_H
#define FLIGHT_EQUALCOMMAND_H

#include "Command.h"
#include <pthread.h>

class EqualCommand :public Command{

public:
    virtual int doCommand(vector<vector<string>> vector1, map<string, double> *map1, int index);
    EqualCommand(DataReaderServer* server5,DataClient* dataClient1,Dijkstra* dij,pthread_mutex_t *mut)
            :Command(server5,dataClient1,dij,mut){}


};


#endif //FLIGHT_EQUALCOMMAND_H
