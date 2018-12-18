//
// Created by tomer on 12/18/18.
//

#ifndef FLIGHTSIMULATOR_OPENDATASERVER_H
#define FLIGHTSIMULATOR_OPENDATASERVER_H
#include <thread>

#include <iostream>
#include <string>
#include "Command.h"
#include "../Sockets/DataReaderServer.h"

using namespace std;

class OpenDataServer : Command {
    vector<string>::iterator itor;
public:
    struct params_to_socket{
        int port;
        int time;
        DataReaderServer server;
    };
    OpenDataServer(
            const vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::iterator &itor);

    virtual void doCommand();
};


#endif //FLIGHTSIMULATOR_OPENDATASERVER_H
