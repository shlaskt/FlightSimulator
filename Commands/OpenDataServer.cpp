//
// Created by tomer on 12/18/18.
//

#include "OpenDataServer.h"

//#define PORT 4510
extern bool is_server_opened;
// struct with the parameters to the socket
struct params_to_socket {
    int port;
    int time;
    DataReaderServer *data_server;
    int new_sock_fd;
};

/**
 * doCommand (x,y)
 * open server on port x, listen y time per sec
 *
 * @param args x,y-> port, time
 */
int OpenDataServer::doCommand(vector<string> line, int i, DataReaderServer *server,
                              Client *client, VarDataBase *var_data_base) {
    Dijkstra shunting_yard(var_data_base->getSymbolTable());
    double i_port, i_time;
    // check valid - should be 2 non-negative numbers
    try {
        i_port = shunting_yard(line[i]); // initialize port
        i_time = shunting_yard(line[++i]); // initialize server
    } catch (const out_of_range &no_such_var) {
        // if there is no var in this name- dijkstra throw error
        __throw_runtime_error("invalid params to OpenDataServer Command");
    } // if port or time are negative
    if (i_port < 0 || i_time < 0) __throw_runtime_error("invalid (neg) params to OpenDataServer");

    // initialize the struct
    struct params_to_socket *params = initParams(i_port, i_time, server);

    CreateThread(params); // open new thread
    return ++i; // increase index
}


struct params_to_socket *OpenDataServer::initParams(double i_port, double i_time, DataReaderServer *server) {
    struct params_to_socket *params = new params_to_socket; // struct of params to sock
    // initialize the struct
    params->port = (int) i_port; // initialize port - casting to int
    params->time = (int) i_time; // initialize server - casting to int
    params->data_server = server;
    return params;
}

/**
 * function for the thread- open socket till done reading
 * @param pVoid void* (struct of parapms)
 * @return void* (nothing)
 */
void *CreateSocket(void *pVoid) {
//    while(!is_server_opened){
//        this_thread::sleep_for(std::chrono::milliseconds((unsigned int) 5000));
//    }
    struct params_to_socket *params1 = (struct params_to_socket *) pVoid;
    while (true) {
        auto x = params1->data_server->readSocket(params1->new_sock_fd);
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
//#ifdef PORT
//    params->port = PORT;
//#endif
    int newsockfd = params->data_server->open(params->port, params->time); // open new socket
    params->new_sock_fd = newsockfd;
    pthread_create(&trid, nullptr, CreateSocket, params);
}



