//
// Created by eyal on 12/27/18.
//

#include "Controller.h"

Controller::Controller() {
    mut = new pthread_mutex_t();
    pthread_mutex_init(mut, nullptr);
    maps = new Maps(mut);
    server = new DataReaderServer(maps->getSymbolMap(),mut);
    client = new Client();
    dijkstra = new Dijkstra(maps->getSymbolMap());
    parser = new Parser(maps->getSymbolMap(),maps->getComMap());
}

void Controller::runningProgram(int argc,char *argv[]) {
    maps->setDij(dijkstra);
    maps->setServer(server,client);
    maps->setParser(parser);
    maps->initMapCom();
    LexerClass lexerClass;
    vector<vector<string>> afterLex;

    //read from the file
    //string fileName="tempppppp";
    string fileName=argv[1];


    //pthread_mutex_destroy(&mut);

    afterLex = lexerClass.readFromFile(fileName);
    int ans = parser->interpLine(afterLex);

    if(ans == 0){
        server->stopLoop();
        pthread_mutex_destroy(mut);
        delete mut;
        delete dijkstra;
        delete parser;
        delete client;
        delete server;
    }
    /*
    //delete
    pthread_mutex_destroy(mut);
    delete mut;
    delete dijkstra;
    delete parser;
    delete client1;
    delete drs;*/
    delete parser;
    delete maps;
}