

#ifndef FLIGHT_EQUALCOMMAND_H
#define FLIGHT_EQUALCOMMAND_H

#include "Command.h"
#include <pthread.h>

class EqualCommand :public Command{

public:
    virtual int doCommand(vector<vector<string>> vector1, map<string, double> *symbol_table, int index);
    EqualCommand(DataReaderServer* serverData,Client* client1,Dijkstra* dij,pthread_mutex_t *mut)
            :Command(serverData,client1,dij,mut){}


};


#endif //FLIGHT_EQUALCOMMAND_H
