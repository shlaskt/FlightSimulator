//
// Created by tomer on 12/18/18.
//
#define BUF 1000

#include <strings.h>
#include <cstring>
#include "Client.h"
// "example- connect 127.0.0.1 5402"

int Client::open(string ip, int port) {
    const char *argv = ip.c_str(); // convert to char*
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    portno = port;

    /* Create a socket point */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(argv);

    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    /* Now connect to the server */
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }
    return sockfd;
}

/* Now ask for a message from the user, this message
   * will be read by server
*/
string Client::set(int sockfd, string path) {
    int n;
    char buffer[BUF];

    //printf("Please enter the message: ");
    bzero(buffer, BUF);
    //fgets(buffer, BUF, stdin);

    size_t path_len=path.size();

    /* Send message to the server */
//    n = write(sockfd, buffer, strlen(buffer));
    n = write(sockfd, &path, path_len);

    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    /* Now read server response */
//    bzero(buffer, BUF);
//    n = read(sockfd, buffer, BUF - 1);
//
//    if (n < 0) {
//        perror("ERROR reading from socket");
//        exit(1);
//    }
//    cout << buffer << endl;
}

