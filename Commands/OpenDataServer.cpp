//
// Created by tomer on 12/18/18.
//

#include "OpenDataServer.h"

// struct with the parameters to the socket
struct params_to_socket {
    int port;
    int time;
    DataReaderServer *data_server;
};

/**
 * doCommand (x,y)
 * open server on port x, listen y time per sec
 *
 * @param args x,y-> port, time
 */
void OpenDataServer::doCommand(vector<string>::iterator &itor, DataReaderServer *server) {
    int i_port, i_time; // change to double?

    //  replace    atoi     with     dijkstra  !

    // check valid - should be 2 non-negative numbers
    try {
        i_port = atoi((*itor).c_str()); // initialize port
        i_time = atoi((*++itor).c_str()); // initialize server
    } catch (const out_of_range &no_such_var) {
        // if there is no var in this name- dijkstra throw error
        __throw_runtime_error("invalid params to OpenDataServer Command");
    } // if port or time are negative
    if (i_port < 0 || i_time < 0) __throw_runtime_error("invalid (neg) params to OpenDataServer");

    // initialize the struct
    struct params_to_socket *params = initParams(i_port, i_time, server);

    CreateThread(params); // open new thread
    delete (params); // when finish- delete and return
    ++itor; // increase iterator
}


struct params_to_socket * OpenDataServer::initParams(double i_port, double i_time, DataReaderServer* server){
    struct params_to_socket *params = new params_to_socket; // struct of params to sock
    // initialize the struct
    params->port = i_port; // initialize port
    params->time = i_time; // initialize server
    params->data_server = server;
    return params;
}

/**
 * function for the thread- open socket till done reading
 * @param pVoid void* (struct of parapms)
 * @return void* (nothing)
 */
void *CreateSocket(void *pVoid) {
    struct params_to_socket *params1 = (struct params_to_socket *) pVoid;
    int newsockfd = params1->data_server->open(params1->port, params1->time); // open new socket

    while (true) {
        auto x = params1->data_server->readSocket(newsockfd);
        if (x == "exit") break;
    }
    return nullptr;
}

/**
 * Create Thread that open socket
 * @param params
 */
void OpenDataServer::CreateThread(struct params_to_socket *params) {
    pthread_t trid;
    pthread_create(&trid, nullptr, CreateSocket, params);
}



