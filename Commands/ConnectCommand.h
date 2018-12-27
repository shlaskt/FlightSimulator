
#ifndef FLIGHT_CONNECTCOMMAND_H
#define FLIGHT_CONNECTCOMMAND_H

#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string>
#include <map>
#include "Command.h"
#include "DataClient.h"
using namespace std;

class ConnectCommand: public Command {

public:
    ConnectCommand(DataReaderServer* server5,DataClient* dataClient1,Dijkstra* dij,pthread_mutex_t *mut)
    :Command(server5,dataClient1,dij,mut){}
    virtual int doCommand(vector<vector<string>> vector1,map<string, double>* map1,int index);


};


#endif //FLIGHT_CONNECTCOMMAND_H
