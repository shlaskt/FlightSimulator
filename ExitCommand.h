//
// Created by reut on 24/12/18.
//

#ifndef FLIGHT_EXITCOMMAND_H
#define FLIGHT_EXITCOMMAND_H


#include "Command.h"
#include "Parser.h"


class ExitCommand : public Command{
private:
    DataReaderServer* server;
    DataClient* dataClient1;
    Dijkstra* dij;
    Parser* pars;
    pthread_mutex_t *mut;
    //pthread_mutex_t *mut;

public:
    virtual int doCommand(vector<vector<string>> vector1, map<string, double> *map1, int index);
    ExitCommand(DataReaderServer* server5,DataClient* dataClient1,Parser* pars,Dijkstra* dij,pthread_mutex_t *mut)
    :Command(server5,dataClient1,dij,mut){
        this->server = server5;
        this->dataClient1=dataClient1;
        this->dij = dij;
        this->mut = mut;
        this->pars = pars;
    }

};

#endif //FLIGHT_EXITCOMMAND_H
