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
    virtual int doCommand(vector<vector<string>> lines, map<string, double> *symbol_table, int index);
    ExitCommand(DataReaderServer* data_server,Client* client_data,
            Interpreter* pars,Dijkstra* dijkstra,pthread_mutex_t *mut)
    :Command(data_server,client_data,dijkstra,mut){
        this->server = data_server;
        this->data_client=client_data;
        this->dijkstra = dijkstra;
        this->mut = mut;
        this->pars = pars;
    }

};

#endif //FLIGHT_EXITCOMMAND_H
