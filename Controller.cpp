//
// Created by Tomer & eyal on 12/27/18.
//

#include "Controller.h"

#define ONE 1
#define TWO 2
void Controller::InitDataMaps() {
    maps->setDij(dijkstra);
    maps->setServer(server, client);
    maps->setInterpreter(interpreter);
    maps->initCommandMap();
}

Controller::Controller() {
    mut = new pthread_mutex_t();
    pthread_mutex_init(mut, nullptr);
    maps = new DataMaps(mut);
    server = new DataReaderServer(maps->getSymbolMap(), mut);
    client = new Client();
    dijkstra = new Dijkstra(maps->getSymbolMap());
    interpreter = new Interpreter(maps->getSymbolMap(), maps->getComMap());
}
/**
 * running the program with lexer and interpreter.
 * @param argc number of element to main.
 * @param argv elements from main.
 */
void Controller::runningProgram(int argc, char *argv[]) {
    InitDataMaps();
    vector<vector<string>> afterLex;
    if (argc != TWO) throw runtime_error("error on number of arguments to main");
    string fileName = argv[ONE];

    afterLex = interpreter->readFromFile(fileName);
    bool did_exit = interpreter->interpLine(afterLex);

    if (!did_exit) {
        server->stopLoop();
        pthread_mutex_destroy(mut);
        DeleteMembers();
    }
    delete interpreter;
    delete maps;
}

/**
 * free all the members data.
 */
void Controller::DeleteMembers() {
    delete mut;
    delete dijkstra;
    delete interpreter;
    delete client;
    delete server;
}