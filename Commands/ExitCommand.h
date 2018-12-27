//
// Created by Eyal on 24/12/18.
//

#ifndef FLIGHT_EXITCOMMAND_H
#define FLIGHT_EXITCOMMAND_H


#include "Command.h"
#include "../Interpreter.h"


class ExitCommand : public Command{
private:
    DataReaderServer* server;
    Client* client1;
    Dijkstra* dij;
    pthread_mutex_t *mut;
    //pthread_mutex_t *mut;

public:
    virtual int doCommand(vector<vector<string>> vector1, map<string, double> *map1, int index);
    ExitCommand(DataReaderServer* server5,Client* client1,Interpreter* pars,Dijkstra* dij,pthread_mutex_t *mut)
    :Command(server5,client1,dij,mut){
        this->server = server5;
        this->client1=client1;
        this->dij = dij;
        this->mut = mut;
    }
};

#endif //FLIGHT_EXITCOMMAND_H
