//
// Created by tomer on 12/18/18.
//
#define BUF 1000

#include "DataReaderServer.h"

/**
 * Ctor
 * @param varDataBase
 */
DataReaderServer::DataReaderServer(VarDataBase *varDataBase) : varDataBase(varDataBase) {}

/**
 * split to vector
 * @param buff
 * @return
 */
vector<double> DataReaderServer::split(string buff) {
    vector<double> info;
    size_t pos = 0;
    string delimiter = " ";
    while ((pos = buff.find(delimiter)) != string::npos) {
        info.push_back(stod(buff.substr(0, pos)));
        buff.erase(0, pos + delimiter.length());
    }
    info.push_back(stod(buff.substr(0, pos)));
    return info;
}

//"openDataServer 5400 10"
int DataReaderServer::open(int port, int time_per_sec) {
    int sockfd, newsockfd, portno, clilen;
    struct sockaddr_in serv_addr, cli_addr;

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

    cout << "waiting for connection..." << endl;

    //clilen = sizeof(cli_addr);

    /* Accept actual connection from the client */
    newsockfd = ::accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);

    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }
    cout << "connected!" << endl;

    return newsockfd; //return the new sockfd

}
// check if is the wright way to read 1/tume
/* If connection is established then start communicating */
string DataReaderServer::readSocket(int newsockfd) {
    while (true) {
        char buffer[BUF];
        bzero(buffer, BUF);
        ssize_t n = read(newsockfd, buffer, BUF - 1);

        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        } else if (n == 0) {
            // ?
            int y = 0;
        } else {
            buffer[n] = NULL; // warning
            //sleep(1 / time_per_sec); // sleep for the given time
            cout << buffer << endl; // for check
        }
        vector<double> split_buff = split(buffer);
        this->updatePathMap(split_buff); // update the path map
        varDataBase->updateSymbolTable(); // update the symbol table
    }
    return ""; //until it will return "exit"

}

/**
 * update the map of vars
 * every path to the spesific place in the vector
 * @param splited vector
 */
void DataReaderServer::updatePathMap(vector<double> splited) {
    this->varDataBase->assignPathValue("/instrumentation/airspeed-indicator/indicated-speed-kt", splited[0]);
    this->varDataBase->assignPathValue("/instrumentation/altimeter/indicated-altitude-ft", splited[1]);
    this->varDataBase->assignPathValue("/instrumentation/altimeter/pressure-alt-ft", splited[2]);
    this->varDataBase->assignPathValue("/instrumentation/attitude-indicator/indicated-pitch-deg", splited[3]);
    this->varDataBase->assignPathValue("/instrumentation/attitude-indicator/indicated-roll-deg", splited[4]);
    this->varDataBase->assignPathValue("/instrumentation/attitude-indicator/internal-pitch-deg", splited[5]);
    this->varDataBase->assignPathValue("/instrumentation/attitude-indicator/internal-roll-deg", splited[6]);
    this->varDataBase->assignPathValue("/instrumentation/encoder/indicated-altitude-ft", splited[7]);
    this->varDataBase->assignPathValue("/instrumentation/encoder/pressure-alt-ft", splited[8]);
    this->varDataBase->assignPathValue("/instrumentation/gps/indicated-altitude-ft", splited[9]);
    this->varDataBase->assignPathValue("/instrumentation/gps/indicated-ground-speed-kt", splited[10]);
    this->varDataBase->assignPathValue("/instrumentation/gps/indicated-vertical-speed", splited[11]);
    this->varDataBase->assignPathValue("/instrumentation/heading-indicator/indicated-heading-deg", splited[12]);
    this->varDataBase->assignPathValue("/instrumentation/magnetic-compass/indicated-heading-deg", splited[13]);
    this->varDataBase->assignPathValue("/instrumentation/slip-skid-ball/indicated-slip-skid", splited[14]);
    this->varDataBase->assignPathValue("/instrumentation/turn-indicator/indicated-turn-rate", splited[15]);
    this->varDataBase->assignPathValue("/instrumentation/vertical-speed-indicator/indicated-speed-fpm", splited[16]);
    this->varDataBase->assignPathValue("/controls/flight/aileron", splited[17]);
    this->varDataBase->assignPathValue("/controls/flight/elevator", splited[18]);
    this->varDataBase->assignPathValue("/controls/flight/rudder", splited[19]);
    this->varDataBase->assignPathValue("/controls/flight/flaps", splited[20]);
    this->varDataBase->assignPathValue("/controls/engines/engine/throttle", splited[21]);
    this->varDataBase->assignPathValue("/engines/engine/rpm", splited[22]);
}



