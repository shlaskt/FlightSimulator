//
// Created by Tomer & Eyal on 19/12/18.
//

#include <strings.h>
#include "Client.h"
#include <string>

/**
 * create new Socket
 * @param ip the ip
 * @param port the port
 * @return 0 if succed
 */
int Client::openSocket(string ip, double port) {
    struct sockaddr_in serv_addr;
    struct hostent *server;
    /* Create a socket point */
    this->new_sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    //args->defineSocketClient(this->sock_fd);
    if (this->new_sock_fd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    /* Initialize m_socket structure */
    bzero((char *) &this->m_socket, sizeof(this->m_socket));

    server = gethostbyname(ip.c_str());

    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(port);

    /* Now connect to the server */
    if (connect(this->new_sock_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    return 0;
}

/**
 * set data drom the files/user to the simulator
 * @param str_to_set
 */
void Client::setData(string str_to_set) {

    /* Now ask for a message from the user, this message
      * will be read by server
   */
    int n;
    char buffer[1024];
    bzero(buffer, 1024);

    /* Send message to the server */
    size_t lenPath = str_to_set.size();
    const char *neaString = str_to_set.c_str();
    n = write(this->new_sock_fd, neaString, lenPath);

    if (n < 0) {
        throw runtime_error("unable to write to socket");
    }

}


