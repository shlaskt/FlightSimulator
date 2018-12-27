//
// Created by eyal on 12/27/18.
//

#ifndef FLIGHT_CONTROLLER_H
#define FLIGHT_CONTROLLER_H

#include <iostream>
#include "Commands/DataReaderServer.h"
#include "Maps.h"
#include "Commands/Client.h"
#include "InputReader/InputReader.h"
#include "InputReader/StdinReader.h"
#include "InputReader/FileReader.h"

class Controller {
private:
    pthread_mutex_t *mut;
    Maps *maps;
    DataReaderServer *server;
    Client *client;
    Dijkstra *dijkstra;
    Interpreter *interpreter;
    InputReader *reader;
public:
    Controller(int argc, char *argv[]);

    void runningProgram(int argc, char *argv[]);
};


#endif //FLIGHT_CONTROLLER_H
