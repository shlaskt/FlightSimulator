//
// Created by eyal on 12/27/18.
//

#include "Controller.h"

Controller::Controller() {
    mut = new pthread_mutex_t();
    pthread_mutex_init(mut, nullptr);
    dataMaps = new MapsData(mut);
    server = new DataReaderServer(dataMaps->getSymbolMap(), mut);
    client = new Client();
    dijkstra = new Dijkstra(dataMaps->getSymbolMap());
    interpreter = new Interpreter(dataMaps->getSymbolMap(), dataMaps->getComMap());
}

InputReader *CreateReader(int argc, char *argv[]) {
    switch (argc) {
        case 1: {
            throw runtime_error("didnt get file path");
        }
        case 2: {
            string file_path = argv[1];
            return new FileReader(file_path);
        }
        default: {
            throw runtime_error("too many arguments to main");
        }
    }
}

void Controller::runningProgram(int argc, char *argv[]) {
    dataMaps->setDij(dijkstra);
    dataMaps->setServer(server, client);
    dataMaps->setInterpreter(interpreter);
    dataMaps->initMapCom();
    InputReader *inputReader;
    switch (argc) {
        case 1: {
            throw runtime_error("didnt get file path");
        }
        case 2: {
            string file_path = argv[1];
            inputReader = new FileReader(file_path);
            break;
        }
        default: {
            throw runtime_error("too many arguments to main");
        }
    }

    vector<vector<string>> afterLex;

    afterLex = interpreter->readFromFile(inputReader);
    bool was_exit = interpreter->interpreteFile(afterLex);

    if (!was_exit) {
        server->stopLoop();
        pthread_mutex_destroy(mut);
        delete mut;
        delete dijkstra;
        delete interpreter;
        delete client;
        delete server;
    }
    delete inputReader;
    delete interpreter;
    delete dataMaps;
}