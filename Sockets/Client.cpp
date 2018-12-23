//
// Created by tomer on 12/18/18.
//
#define BUF 1000


#include "Client.h"
// example- "connect 127.0.0.1 5402"

int Client::open(string ip, int port) {
    const char *argv = ip.c_str(); // convert to char*
    struct sockaddr_in serv_addr;
    struct hostent *server;

    /* Create a socket point */
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (sock_fd < 0) {
        __throw_runtime_error("ERROR opening socket - sockfd<0");
    }

    server = gethostbyname(ip.c_str());

    if (server == NULL) {
        __throw_runtime_error("ERROR opening socket - no such host");
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(port);

    /* Now connect to the server */
    while (true) {
        int c = connect(sock_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
        if (c == 0) {
            break;
            perror("ERROR connecting");
            exit(1);
        }
    }
    cout << "connect" << endl;

    return 0;
}


/* Now ask for a message from the user, this message
   * will be read by server
*/
string Client::set(string path) {
    const char *c_path = path.c_str();
    int n;
    char buffer[BUF];

    //printf("Please enter the message: ");
    bzero(buffer, BUF);
    //fgets(buffer, BUF, stdin);

    size_t path_len = strlen(c_path);

    /* Send message to the server */
//    n = write(sockfd, buffer, strlen(buffer));

    // "set path val \r\n strlen(buffer)"
    n = write(sock_fd, c_path, path_len);

    if (n < 0) {
        __throw_runtime_error("ERROR writing to socket - n<0");
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

