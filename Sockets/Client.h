//
// Created by tomer on 12/18/18.
//


#ifndef FLIGHTSIMULATOR_CLIENT_H
#define FLIGHTSIMULATOR_CLIENT_H
#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <iostream>

#include <string>
#include <strings.h>
#include <cstring>
using namespace std;

class Client {
    int sock_fd;
public:
    int open(string ip, int port);
    string set(string);

};


#endif //FLIGHTSIMULATOR_CLIENT_H
