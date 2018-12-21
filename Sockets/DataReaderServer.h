//
// Created by tomer on 12/18/18.
//




#ifndef FLIGHTSIMULATOR_SERVER_H
#define FLIGHTSIMULATOR_SERVER_H
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
#include "../DataManagement/VarDataBase.h"
using namespace std;

class DataReaderServer {
private:
    VarDataBase varDataBase;
public:
    DataReaderServer(VarDataBase &varDataBase);

    int open(int port, int time_per_sec);
    string readSocket(int newsockfd);

    vector<double> split(string buff);
    void updatePathMap(vector<double> splited);

};

#endif //FLIGHTSIMULATOR_SERVER_H
