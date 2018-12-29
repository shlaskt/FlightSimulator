

#ifndef FLIGHT_ASSIGNCOMMAND_H
#define FLIGHT_ASSIGNCOMMAND_H

#include "Command.h"
#include <pthread.h>
#define SET "set "
#define SPACE ' '
#define RN "\r\n"

class AssignCommand :public Command{

public:
    virtual int doCommand(vector<vector<string>> lines, map<string, double> *symbolTable, int line);
    AssignCommand(DataReaderServer* server5,Client* client1,Dijkstra* dij,pthread_mutex_t *mut)
            :Command(server5,client1,dij,mut){}


};


#endif //FLIGHT_ASSIGNCOMMAND_H
