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
#include "Commands/openServerCommand.h"
#include "Commands/VarCommand.h"
#include "Commands/AssignCommand.h"
#include "Commands/ConnectCommand.h"
#include "Commands/WhileCommand.h"
#include "Commands/IfCommand.h"
#include "Commands/PrintCommand.h"
#include "Commands/SleepCommand.h"
#include "Commands/ExitCommand.h"

using namespace std;


class DataMaps {
private:
    map<string, Command *> commandMap;
    map<string, double> symbolTable;
    Client *client;
    Dijkstra *shunting_yard;
    Interpreter *pars;
    DataReaderServer *data_server;
    pthread_mutex_t *mut;
public:
    DataMaps(pthread_mutex_t *mut) {
        this->mut = mut;
    }

    void initCommandMap();

    map<string, double> *getSymbolMap();

    map<string, Command *> *getComMap();

    void setServer(DataReaderServer *dataReaderServer, Client *client_data);

    void setDij(Dijkstra *dijkstra);

    void setInterpreter(Interpreter *interpreter);

    ~DataMaps();

};


#endif //FLIGHT_MAPS_H
