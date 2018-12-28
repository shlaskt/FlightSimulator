//
// Created by Tomer & Eyal on 13/12/18.
//

#ifndef FLIGHT_DATAREADERSERVER_H
#define FLIGHT_DATAREADERSERVER_H

#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string>
#include <map>
#include <vector>

using namespace std;

class DataReaderServer {
private:
    struct sockaddr_in m_socket;
    int sock_fd, client_sock_fd;
    double time;
    map<string, string>* path_map;
    map<string,double > path_to_var;
    map<string,double >* symbol_table;
    pthread_mutex_t *mut;
    bool finish_reading;


public:
    DataReaderServer(map<string,double >* symbol_table,pthread_mutex_t *mut){
        this->symbol_table = symbol_table;
        this->path_map = new map<string,string>;
        buildMap();
        this->mut = mut;
        this->finish_reading = false;
    }
    int openSocket(double num1, double num2);
    string readFromSock();
    void addNewPath(string var, string path);
    void accept();
    string getPath(string var);
    void buildMap();
    vector<double > split(string buffer);
    void setPathMap(vector<double> splited);
    void updateSymbolTable();
    void endRead();
    ~DataReaderServer(){
        delete this->path_map;
    }
};


#endif //FLIGHT_DATAREADERSERVER_H
