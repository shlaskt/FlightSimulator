//
// Created by tomer on 12/18/18.
//
#define BUF 256

#include "DataReaderServer.h"

//"openDataServer 5400 10"
void DataReaderServer::open(int port, int time_per_sec) {
    int sockfd, newsockfd, portno, clilen;
    char buffer[BUF];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    /* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = port;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    /* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    /* Now start listening for the clients, here process will
       * go in sleep mode and will wait for the incoming connection
    */

    listen(sockfd, 1);
    clilen = sizeof(cli_addr);

    /* Accept actual connection from the client */
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);

    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }

    while (true) { // check if is the wright way to read 1/tume
        /* If connection is established then start communicating */
        bzero(buffer, BUF);
        n = read(newsockfd, buffer, BUF);

        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }
        sleep(1 / time_per_sec); // sleep for the given time
        cout << buffer << endl; // for check
    }


}
