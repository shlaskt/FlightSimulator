//
// Created by Tomer & Eyal on 16/12/18.
//

#ifndef FLIGHT_MAPS_H
#define FLIGHT_MAPS_H

#include <map>
#include <string>
#include "Command.h"
#include "Client.h"
#include "Interpreter.h"
#include "openServerCommand.h"
#include "VarCommand.h"
#include "AssignCommand.h"
#include "ConnectCommand.h"
#include "WhileCommand.h"
#include "IfCommand.h"
#include "PrintCommand.h"
#include "SleepCommand.h"
#include "ExitCommand.h"
#include "Dijkstra.h"

using namespace std;


class DataMaps {
private:
    map<string, double> symbolTable;
    map<string, Command *> commandMap;
    DataReaderServer *data_server;
    Client *client;
    Dijkstra *shunting_yard;
    Interpreter *pars;
    pthread_mutex_t *mut;
public:
    DataMaps(pthread_mutex_t *mut);
    map<string, double> *getSymbolMap();

    map<string, Command *> *getComanndMap();

    void createComanndMap();

    void setDataServer(DataReaderServer *dataReaderServer, Client *client_data);

    void setDij(Dijkstra *dijkstra);

    void setInterpreter(Interpreter *interpreter);

    ~DataMaps();
};


#endif //FLIGHT_MAPS_H
