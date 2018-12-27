
#include "DataReaderServer.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <algorithm>

using namespace std;

/**
 * open socket to read from the simulator
 * @param port
 * @param time
 * @return
 */
int DataReaderServer::openSocket(double port, double time) {
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (sock_fd < 0) {
        perror("ERROR opening m_socket");
        exit(1);
    }

    /* Initialize m_socket structure */
    bzero((char *) &this->m_socket, sizeof(this->m_socket));

    this->m_socket.sin_family = AF_INET;
    this->m_socket.sin_addr.s_addr = INADDR_ANY;
    this->m_socket.sin_port = htons(port);

    /* Now bind the host address using bind() call.*/
    if (bind(sock_fd, (struct sockaddr *) &this->m_socket, sizeof(this->m_socket)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    /* Now start listening for the clients, here process will
       * go in sleep mode and will wait for the incoming connection
    */

    listen(sock_fd, 1);
    this->time = time;
    this->stop = false;

    accept();
    return 0;
}

/**
 * try to connect
 */
void DataReaderServer::accept() {
    std::cout << "Waiting for connection..." << endl;
    sockaddr_in client_sock;
    int client;
    client_sock_fd = ::accept(sock_fd, (struct sockaddr *) &client_sock, (socklen_t *) &client);
    if (client_sock_fd < 0) {
        perror("ERROR on connection");
        exit(1);
    }
}

/**
 * read from the socket and update the map
 * @return
 */
string DataReaderServer::readFromSock() {
    //read and update data.
    while (!stop) {
        char buffer[1000];
        ssize_t bytes_read;
        bytes_read = read(this->client_sock_fd, buffer, 999);
        if (bytes_read < 0) {
            __throw_bad_exception();
        } else {
            buffer[bytes_read] = 0;
            cout << buffer;
        }

        vector<double> buffSplit = this->split(buffer);
        this->setPathMap(buffSplit);
        updateSymbolTable();
    }
    return "exit";

}

/**
 * add path
 * for paths that not in the xml
 * @param var
 * @param path
 */
void DataReaderServer::addNewPath(string var, string path) {
    (this->path_map)->insert(pair<string, string>(var, path));
    //this->path_map[var]=path;
}

/**
 * get path
 * @param var
 * @return
 */
string DataReaderServer::getPath(string var) {
    if (this->path_map->count(var) == 1) {
        return this->path_map->at(var);
    }
    return ""; // like null
}

/**
 * initialize the map
 */
void DataReaderServer::buildMap() {
    this->path_to_var.insert(pair<string, double>("/instrumentation/airspeed-indicator/indicated-speed-kt", 0));
    this->path_to_var.insert(pair<string, double>("/instrumentation/altimeter/indicated-altitude-ft", 0));
    this->path_to_var.insert(pair<string, double>("/instrumentation/altimeter/pressure-alt-ft", 0));
    this->path_to_var.insert(pair<string, double>("/instrumentation/attitude-indicator/indicated-pitch-deg", 0));
    this->path_to_var.insert(pair<string, double>("/instrumentation/attitude-indicator/indicated-roll-deg", 0));
    this->path_to_var.insert(pair<string, double>("/instrumentation/attitude-indicator/internal-pitch-deg", 0));
    this->path_to_var.insert(pair<string, double>("/instrumentation/attitude-indicator/internal-roll-deg", 0));
    this->path_to_var.insert(pair<string, double>("/instrumentation/encoder/indicated-altitude-ft", 0));
    this->path_to_var.insert(pair<string, double>("/instrumentation/encoder/pressure-alt-ft", 0));
    this->path_to_var.insert(pair<string, double>("/instrumentation/gps/indicated-altitude-ft", 0));
    this->path_to_var.insert(pair<string, double>("/instrumentation/gps/indicated-ground-speed-kt", 0));
    this->path_to_var.insert(pair<string, double>("/instrumentation/gps/indicated-vertical-speed", 0));
    this->path_to_var.insert(pair<string, double>("/instrumentation/heading-indicator/indicated-heading-deg", 0));
    this->path_to_var.insert(pair<string, double>("/instrumentation/magnetic-compass/indicated-heading-deg", 0));
    this->path_to_var.insert(pair<string, double>("/instrumentation/slip-skid-ball/indicated-slip-skid", 0));
    this->path_to_var.insert(pair<string, double>("/instrumentation/turn-indicator/indicated-turn-rate", 0));
    this->path_to_var.insert(pair<string, double>("/instrumentation/vertical-speed-indicator/indicated-speed-fpm", 0));
    this->path_to_var.insert(pair<string, double>("/controls/flight/aileron", 0));
    this->path_to_var.insert(pair<string, double>("/controls/flight/elevator", 0));
    this->path_to_var.insert(pair<string, double>("/controls/flight/rudder", 0));
    this->path_to_var.insert(pair<string, double>("/controls/flight/flaps", 0));
    this->path_to_var.insert(pair<string, double>("/controls/engines/engine/throttle", 0));
    this->path_to_var.insert(pair<string, double>("/engines/engine/rpm", 0));
}

/**
 * split the line from the simulator to vector
 * by params from the xml
 * @param buffer
 * @return
 */
vector<double> DataReaderServer::split(string buffer) {
    vector<double> info;
    string vv = buffer;
    string temp = buffer;
    int co = 0;
    int count1 = 0;
    co = temp.find_first_of("\n");
    if (co != string::npos) {

        temp = temp.substr(co + 1, temp.size() - 1);
        count1 = 1;
    }
    co = temp.find_first_of("\n");
    if (co != string::npos) {

        count1 = 2;
    }
    size_t pos = 0;
    size_t found;
    string delimiter = ",";
    if (count1 > 1) {

        found = buffer.find_first_of("\n");
        buffer = buffer.substr(found + 1, buffer.size() - 1);
        found = buffer.find_first_of("\n");
        buffer = buffer.substr(0, found);

    }
    if (count1 == 1) {
        found = buffer.find_first_of("\n");
        buffer = buffer.substr(0, found);
    }
    int y = 0;
    while ((pos = buffer.find(delimiter)) != string::npos) {

        if (pos != 0) { info.push_back(stod(buffer.substr(0, pos))); }
        buffer.erase(0, pos + delimiter.length());
        y++;
    }
    string gg = buffer;
    info.push_back(stod(buffer.substr(0, pos)));
    return info;
}

/**
 * set the path map
 * @param splited
 */
void DataReaderServer::setPathMap(vector<double> splited) {

    this->path_to_var.at("/instrumentation/airspeed-indicator/indicated-speed-kt") = splited[0];
    this->path_to_var.at("/instrumentation/altimeter/indicated-altitude-ft") = splited[1];
    this->path_to_var.at("/instrumentation/altimeter/pressure-alt-ft") = splited[2];
    this->path_to_var.at("/instrumentation/attitude-indicator/indicated-pitch-deg") = splited[3];
    this->path_to_var.at("/instrumentation/attitude-indicator/indicated-roll-deg") = splited[4];
    this->path_to_var.at("/instrumentation/attitude-indicator/internal-pitch-deg") = splited[5];
    this->path_to_var.at("/instrumentation/attitude-indicator/internal-roll-deg") = splited[6];
    this->path_to_var.at("/instrumentation/encoder/indicated-altitude-ft") = splited[7];
    this->path_to_var.at("/instrumentation/encoder/pressure-alt-ft") = splited[8];
    this->path_to_var.at("/instrumentation/gps/indicated-altitude-ft") = splited[9];
    this->path_to_var.at("/instrumentation/gps/indicated-ground-speed-kt") = splited[10];
    this->path_to_var.at("/instrumentation/gps/indicated-vertical-speed") = splited[11];
    this->path_to_var.at("/instrumentation/heading-indicator/indicated-heading-deg") = splited[12];
    this->path_to_var.at("/instrumentation/magnetic-compass/indicated-heading-deg") = splited[13];
    this->path_to_var.at("/instrumentation/slip-skid-ball/indicated-slip-skid") = splited[14];
    this->path_to_var.at("/instrumentation/turn-indicator/indicated-turn-rate") = splited[15];
    this->path_to_var.at("/instrumentation/vertical-speed-indicator/indicated-speed-fpm") = splited[16];
    this->path_to_var.at("/controls/flight/aileron") = splited[17];
    this->path_to_var.at("/controls/flight/elevator") = splited[18];
    this->path_to_var.at("/controls/flight/rudder") = splited[19];
    this->path_to_var.at("/controls/flight/flaps") = splited[20];
    this->path_to_var.at("/controls/engines/engine/throttle") = splited[21];
    this->path_to_var.at("/engines/engine/rpm") = splited[22];

}

/**
 * update the map
 */
void DataReaderServer::updateSymbolTable() {
    // lock with mutex
    pthread_mutex_lock(this->mut);
    // update map
    map<string, string>::iterator it = (this->path_map)->begin();
    for (it; it != this->path_map->end(); ++it) {
        string path = (*it).second;
        string varName = (*it).first;
        if ((this->path_to_var).count(path) == 1) {
            double val = (this->path_to_var).at(path);
            this->symbol_table->at(varName) = val;
        }
    }
    // unlock
    pthread_mutex_unlock(this->mut);
}

/**
 * stop the reading from the simulator
 */
void DataReaderServer::stopLoop() {
    this->stop = true;
}

