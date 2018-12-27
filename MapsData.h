//
// Created by Eyal on 16/12/18.
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
#include "Commands/EqualCommand.h"
#include "Commands/ConnectCommand.h"
#include "Commands/WhileCommand.h"
#include "Commands/IfCommand.h"
#include "Commands/PrintCommand.h"
#include "Commands/SleepCommand.h"
#include "Commands/ExitCommand.h"

using namespace std;


class MapsData {
private:
    map<string, double> symbolTable;
    map<string, Command *> commandMap;
    DataReaderServer *dataServer;
    Client *client;
    Dijkstra *dijkstra2;
    Interpreter *pars;
    pthread_mutex_t *mut;
public:
    MapsData(pthread_mutex_t *mut) {
        this->mut = mut;
    }

    map<string, double> *getSymbolMap();

    map<string, Command *> *getComMap();

    void setDij(Dijkstra *dijkstra);

    void setInterpreter(Interpreter *interpreter);

    void initMapCom();

    void setServer(DataReaderServer *dataReaderServer, Client *client1);

    ~MapsData();


};


#endif //FLIGHT_MAPS_H
