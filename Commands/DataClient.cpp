//
// Created by reut on 19/12/18.
//

#include <strings.h>
#include "DataClient.h"
#include <string>
using namespace std;
int DataClient::createSock(string ip, double port) {
    struct sockaddr_in serv_addr;
    struct hostent *server;
    /* Create a socket point */
    this->sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    //args->defineSocketClient(this->sock_fd);
    if (this->sock_fd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    /* Initialize m_socket structure */
    bzero((char *) &this->m_socket, sizeof(this->m_socket));

    server = gethostbyname(ip.c_str());

    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(port);

    /* Now connect to the server */
    if (connect(this->sock_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    return 0;
}

void DataClient::setData(string path) {

    /* Now ask for a message from the user, this message
      * will be read by server
   */
    int n;
    char buffer[1024];
    //printf("Please enter the message: ");
    bzero(buffer,1024);
    //fgets(buffer,255,stdin);

    /* Send message to the server */
    size_t lenPath = path.size();
    /*for(int i= 0;i<lenPath;i++){
        buffer[i]=path[i];
    }*/
    const char * neaString=path.c_str();
    n = write(this->sock_fd,neaString,lenPath);


    if (n < 0) {
        __throw_bad_exception();
    }

    /* Now read server response */
    //bzero(buffer,256);
    //n = read(this->sock_fd, buffer, 1023);

    /*if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }*/

    //printf("%s\n",buffer);

}


