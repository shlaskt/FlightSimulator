//
// Created by eyal on 12/27/18.
//

#include "Controller.h"

Controller::Controller(int argc, char *argv[]) {
    switch (argc) {
        case 0:
            throw runtime_error("erorr in main arguments");
        case 1:
            reader = new StdinReader();
            break;
        default:
            reader = new FileReader(argv[1]);
    }
    mut = new pthread_mutex_t();
    pthread_mutex_init(mut, nullptr);
    maps = new Maps(mut);
    server = new DataReaderServer(maps->getSymbolMap(), mut);
    client = new Client();
    dijkstra = new Dijkstra(maps->getSymbolMap());
    interpreter = new Interpreter(maps->getSymbolMap(), maps->getComMap(), maps->getConditionMap(), reader);
    // TODO:
    // add to interpreter condition map!_=|^
}

void Controller::runningProgram(int argc, char *argv[]) {
    maps->setDij(dijkstra);
    maps->setServer(server, client);
    maps->setInterpreter(interpreter);
    maps->initMapCom();
    vector<string> parsered_line;
//    vector<vector<string>> afterLex;
    string line;
    //read from the file
    //string fileName="tempppppp";
    string fileName = argv[1];
    Command *command;
    //pthread_mutex_destroy(&mut);
    line = reader->readLine();
    do {
        parsered_line = interpreter->lexer(line);
//        afterLex = interpreter->readFromFile(fileName);
        command = interpreter->interprateLine(parsered_line);
        command->doCommand(parsered_line, maps->getSymbolMap());
        line = reader->readLine();
    } while (line != "");

    if (maps->getComMap()->at("exit") == command) {
        server->stopLoop();
        pthread_mutex_destroy(mut);
        delete mut;
        delete dijkstra;
        delete interpreter;
        delete client;
        delete server;
    }
    /*
    //delete
    pthread_mutex_destroy(mut);
    delete mut;
    delete dijkstra;
    delete interpreter;
    delete client1;
    delete drs;*/
    delete reader;
    delete interpreter;
    delete maps;
}