//
// Created by Tomer & Eyal on 24/12/18.
//

#ifndef FLIGHT_EXITCOMMAND_H
#define FLIGHT_EXITCOMMAND_H


#include "Command.h"
#include "../Interpreter.h"


class ExitCommand : public Command{
private:
    DataReaderServer* server;
    Client* data_client;
    Dijkstra* dijkstra;
    Interpreter* pars;
    pthread_mutex_t *mut;

public:
    virtual int doCommand(vector<vector<string>> lines, map<string, double> *symbolTable, int line);
    ExitCommand(DataReaderServer* server5,Client* client1,Interpreter* pars,Dijkstra* dijkstra,pthread_mutex_t *mut)
    :Command(server5,client1,dijkstra,mut){
        this->server = server5;
        this->data_client=client1;
        this->dijkstra = dijkstra;
        this->mut = mut;
        this->pars = pars;
    }

};

#endif //FLIGHT_EXITCOMMAND_H
