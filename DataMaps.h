//
// Created by Tomer & Eyal on 16/12/18.
//

#ifndef FLIGHT_MAPS_H
#define FLIGHT_MAPS_H

#include <map>
#include <string>
#include "Commands/Command.h"
#include "Commands/Client.h"
#include "Interpreter.h"

using namespace std;


class DataMaps {
private:
    map<string, double> symbolTable;
    map<string, Command *> commandMap;
    DataReaderServer *dataServer;
    Client *client;
    Dijkstra *shunting_yard;
    Interpreter *pars;
    pthread_mutex_t *mut;
public:
    DataMaps(pthread_mutex_t *mut) {
        this->mut = mut;
    }

    map<string, double> *getSymbolMap();

    map<string, Command *> *getComMap();

    void initMapCom();

    void setServer(DataReaderServer *dataReaderServer, Client *client1);

    void setDij(Dijkstra *dijkstra);

    void setInterpreter(Interpreter *interpreter);

    ~DataMaps() {
        map<string, Command *>::iterator it = this->commandMap.begin();
        for (it; it != this->commandMap.end(); ++it) {

            delete (*it).second;
        }
    }


};


#endif //FLIGHT_MAPS_H