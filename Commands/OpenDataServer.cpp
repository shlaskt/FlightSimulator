//
// Created by tomer on 12/18/18.
//

#include "OpenDataServer.h"
#include "../Sockets/DataReaderServer.h"
// struct with the parameters to the socket
struct params_to_socket{
    int port;
    int time;
    DataReaderServer* data_server;
};

/**
 * doCommand
 *
 * @param args
 * @return
 */
void OpenDataServer::doCommand(vector<string>::iterator &itor, DataReaderServer* server) {
    struct params_to_socket *params = new params_to_socket; // struct of params to sock
    // initialize the struct
    params->port=atoi((*++itor).c_str()); // initialize port
    params->time=atoi((*++itor).c_str()); // initialize server
    params->data_server=server;
    // open new thread
    CreateThread(params);
    // when finish- delete and return
    delete(params);
}

void* CreateSocket (void* pVoid){
    struct params_to_socket *params1 = (struct params_to_socket*) pVoid;
    int newsockfd = params1->data_server->open(params1->port, params1->time); // open new socket

    while (true) {
        auto x = params1->data_server->read(newsockfd);
        if(x == "exit") break;
    }
    return nullptr;
}

void OpenDataServer::CreateThread(struct params_to_socket* params){
    pthread_t trid;
    pthread_create(&trid, nullptr, CreateSocket,params);

}

