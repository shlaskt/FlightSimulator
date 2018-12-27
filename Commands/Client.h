//
// Created by Tomer & Eyal on 19/12/18.
//

#ifndef FLIGHT_DATACLIENT_H
#define FLIGHT_DATACLIENT_H

#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string>
#include <map>
#include <vector>

#include <string>


using namespace std;

class Client {

private:
    struct sockaddr_in m_socket;
    int new_sock_fd;

public:
    int openSocket(string ip, double port);
    void setData(string str_to_set);

};


#endif //FLIGHT_DATACLIENT_H
