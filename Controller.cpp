//
// Created by Tomer & eyal on 12/27/18.
//

#include "Controller.h"

#define PATH 1
#define VALID_ARGUMENTS 2
Controller::Controller() {
    mut = new pthread_mutex_t();
    pthread_mutex_init(mut, nullptr);
    data_maps = new DataMaps(mut);
    server = new DataReaderServer(data_maps->getSymbolMap(), mut);
    client = new Client();
    dijkstra = new Dijkstra(data_maps->getSymbolMap());
    interpreter = new Interpreter(data_maps->getSymbolMap(), data_maps->getComanndMap());
}

void checkMainArguments(int argc) {
    if (argc != VALID_ARGUMENTS) {
        throw runtime_error("error on number of elements to main");
    }
}

void Controller::runningProgram(int argc, char *argv[]) {
    data_maps->setDij(dijkstra);
    data_maps->setDataServer(server, client);
    data_maps->setInterpreter(interpreter);
    data_maps->createComanndMap();
    vector<vector<string>> parsered_lines;
    checkMainArguments(argc);
    string fileName = argv[PATH];

    parsered_lines = interpreter->readFromFile(fileName);
    bool did_exit = interpreter->interpLine(parsered_lines);

    if (!did_exit) {
        freeMemory();
    }
    delete interpreter;
    delete data_maps;
}

void Controller::freeMemory() {
    server->end_program();
    pthread_mutex_destroy(mut);
    delete mut;
    delete dijkstra;
    delete interpreter;
    delete client;
    delete server;
}
