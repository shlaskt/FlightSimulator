//
// Created by tomer on 12/18/18.
//

#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>

#include <string.h>
#include <vector>

#include <sys/socket.h>
#include <iostream>
#include <string>
#ifndef FLIGHTSIMULATOR_SERVER_H
#define FLIGHTSIMULATOR_SERVER_H

using namespace std;

class DataReaderServer {
public:
    int open(int port, int time_per_sec);
    string read(int newsockfd);

    vector<double> split(string buff);
    void updateMap(vector<double> splited);

};


#endif //FLIGHTSIMULATOR_SERVER_H
