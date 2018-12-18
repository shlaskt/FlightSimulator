//
// Created by tomer on 12/18/18.
//
#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <iostream>

#include <string>

#ifndef FLIGHTSIMULATOR_CLIENT_H
#define FLIGHTSIMULATOR_CLIENT_H

using namespace std;

class Client {
public:
    void operator()(string ip, int port);

};


#endif //FLIGHTSIMULATOR_CLIENT_H
