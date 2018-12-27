//
// Created by eyal on 12/27/18.
//

#ifndef FLIGHT_CONTROLLER_H
#define FLIGHT_CONTROLLER_H

#include <iostream>
#include "Commands/DataReaderServer.h"
#include "Maps.h"
#include "Commands/Client.h"
#include "Interpreter.h"
#include "LexerClass.h"

class Controller {
private:
    pthread_mutex_t *mut;
    Maps *maps;
    DataReaderServer *server;
    Client *client;
    Dijkstra *dijkstra;
    Interpreter *interpreter;
public:
    Controller();

    void runningProgram(int argc, char *argv[]);
};


#endif //FLIGHT_CONTROLLER_H
