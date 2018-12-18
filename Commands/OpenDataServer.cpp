//
// Created by tomer on 12/18/18.
//

#include "OpenDataServer.h"
#include "../Sockets/DataReaderServer.h"

/**
 * Ctor
 * @param itor
 */
OpenDataServer::OpenDataServer(
        const vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>,
                std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>,
                        std::allocator<char>>>>::iterator &itor)
        : itor(itor) {}

/**
 * doCommand
 *
 * @param args
 * @return
 */
void OpenDataServer::doCommand() {
    int port_server = atoi((*++itor).c_str()); // just for test
    int time_server = atoi((*++itor).c_str()); // just for test
    struct params {
        int port1 = port_server;
        int time1 = time_server;
    };


    pthread_create()
    thread data_server(DataReaderServer(), port_server, time_server);

    data_server.detach();
}