
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
#include "Client.h"
using namespace std;

class ConnectCommand: public Command {

    double checkValid(string ip, string port_s);
public:
    ConnectCommand(DataReaderServer* serverData,Client* client1,Dijkstra* dij,pthread_mutex_t *mut)
    :Command(serverData,client1,dij,mut){}
    virtual int doCommand(vector<vector<string>> vector1,map<string, double>* symbol_table,int index);
};


#endif //FLIGHT_CONNECTCOMMAND_H
