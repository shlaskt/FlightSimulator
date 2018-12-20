//
// Created by tomer on 12/18/18.
//

#include "OpenDataServer.h"
// struct with the parameters to the socket
struct params_to_socket{
    int port;
    int time;
    DataReaderServer* data_server;
};

/**
 * doCommand (x,y)
 * open server on port x, listen y time per sec
 *
 * @param args x,y-> port, time
 */
void OpenDataServer::doCommand(vector<string>::iterator &itor, DataReaderServer* server) {
    struct params_to_socket *params = new params_to_socket; // struct of params to sock
    // check valid - should be 2 numbers
    int i_port, i_time;


    //replace atoi with dijkstra

    try {
        i_port=atoi((*itor).c_str()); // initialize port
        i_time=atoi((*++itor).c_str()); // initialize server
    } catch (const out_of_range& no_such_var){
        // if there is no var in this name- dijkstra throw error
        __throw_runtime_error("invalid params to OpenDataServer Command");
    }

    // initialize the struct
    params->port=i_port; // initialize port
    params->time=i_time; // initialize server
    params->data_server=server;

    CreateThread(params); // open new thread
    delete(params); // when finish- delete and return
}

/**
 * function for the thread- open socket till done reading
 * @param pVoid void* (struct of parapms)
 * @return void* (nothing)
 */
void* CreateSocket (void* pVoid){
    struct params_to_socket *params1 = (struct params_to_socket*) pVoid;
    int newsockfd = params1->data_server->open(params1->port, params1->time); // open new socket

    while (true) {
        auto x = params1->data_server->readSocket(newsockfd);
        if(x == "exit") break;
    }
    return nullptr;
}

/**
 * Create Thread that open socket
 * @param params
 */
void OpenDataServer::CreateThread(struct params_to_socket* params){
    pthread_t trid;
    pthread_create(&trid, nullptr, CreateSocket,params);
}



