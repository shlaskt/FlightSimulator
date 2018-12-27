//
// Created by reut on 19/12/18.
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

class DataClient {

private:
    struct sockaddr_in m_socket;
    int sock_fd, client_sock_fd;

public:
    int createSock(string ip, double port);
    void setData(string info);

};


#endif //FLIGHT_DATACLIENT_H
