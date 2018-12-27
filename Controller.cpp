//
// Created by Tomer & eyal on 12/27/18.
//

#include "Controller.h"

Controller::Controller() {
    mut = new pthread_mutex_t();
    pthread_mutex_init(mut, nullptr);
    maps = new Maps(mut);
    server = new DataReaderServer(maps->getSymbolMap(),mut);
    client = new Client();
    dijkstra = new Dijkstra(maps->getSymbolMap());
    interpreter = new Interpreter(maps->getSymbolMap(),maps->getComMap());
}

void Controller::runningProgram(int argc,char *argv[]) {
    maps->setDij(dijkstra);
    maps->setServer(server,client);
    maps->setInterpreter(interpreter);
    maps->initMapCom();
    vector<vector<string>> afterLex;

    //read from the file
    //string fileName="tempppppp";
    string fileName=argv[1];


    //pthread_mutex_destroy(&mut);

    afterLex = interpreter->readFromFile(fileName);
    int ans = interpreter->interpLine(afterLex);

    if(ans == 0){
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
    delete interpreter;
    delete maps;
}