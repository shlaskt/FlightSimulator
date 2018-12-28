

#ifndef FLIGHT_EQUALCOMMAND_H
#define FLIGHT_EQUALCOMMAND_H

#include "Command.h"
#include <pthread.h>
#define SET "set "
#define SPACE ' '
#define RN "\r\n"

class AssignCommand :public Command{

public:
    virtual int doCommand(vector<vector<string>> vector1, map<string, double> *map1, int index);
    AssignCommand(DataReaderServer* server5,Client* client1,Dijkstra* dij,pthread_mutex_t *mut)
            :Command(server5,client1,dij,mut){}


};


#endif //FLIGHT_EQUALCOMMAND_H
