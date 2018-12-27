
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

int DataReaderServer:: createSock(double port, double time){
    double portno;
    //struct sockaddr_in serv_addr, cli_addr;


    /* First call to m_socket() function */
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (sock_fd < 0) {
        perror("ERROR opening m_socket");
        exit(1);
    }

    /* Initialize m_socket structure */
    bzero((char *) &this->m_socket, sizeof(this->m_socket));
    portno = port;

    this->m_socket.sin_family = AF_INET;
    this->m_socket.sin_addr.s_addr = INADDR_ANY;
    this->m_socket.sin_port = htons(portno);

    /* Now bind the host address using bind() call.*/
    if (bind(sock_fd, (struct sockaddr *) &this->m_socket, sizeof(this->m_socket)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    /* Now start listening for the clients, here process will
       * go in sleep mode and will wait for the incoming connection
    */

    listen(sock_fd,1);
    this->time=time;
    this->continueLoop = true;

    accept();
    return 0;
}


void DataReaderServer::accept()
{
    std::cout << "Waiting for connection..." << endl;
    sockaddr_in client_sock;
    int clilen;
    client_sock_fd = ::accept(sock_fd, (struct sockaddr*) &client_sock, (socklen_t *)&clilen);
    if (client_sock_fd < 0) {
        perror("unable to connect server.\n");
        exit(1);
    }
    std::cout << "connected" << std::endl;

}

string DataReaderServer::readFromSock(){
    //read and update data.
    while (this->continueLoop){
        char buffer[1000];
        ssize_t bytes_read;
        bytes_read = read(this->client_sock_fd, buffer, 999);
        if (bytes_read < 0) {
            __throw_bad_exception();
        }   else if (bytes_read == 0)   {

            int y = 0;
        } else  {
            buffer[bytes_read] = 0;
//            cout << buffer;
        }

        vector<double> buffSplit = this->split(buffer);
        this->setMapPath(buffSplit);
        updateMap();
    }
    return "exit";

}

void DataReaderServer::addPath(string var,string path){
    (this->mapPath)->insert(pair<string,string>(var,path));
    //this->mapPath[var]=path;
}

string DataReaderServer::getPath(string var) {
    if(this->mapPath->count(var)==1){
        return this->mapPath->at(var);
    }
    //case didnt find.
    return "";
}

void DataReaderServer::buildMap() {
    this->pathRead.insert(pair<string,double>("/instrumentation/airspeed-indicator/indicated-speed-kt",0));
    this->pathRead.insert(pair<string,double>("/instrumentation/altimeter/indicated-altitude-ft",0));
    this->pathRead.insert(pair<string,double>("/instrumentation/altimeter/pressure-alt-ft",0));
    this->pathRead.insert(pair<string,double>("/instrumentation/attitude-indicator/indicated-pitch-deg",0));
    this->pathRead.insert(pair<string,double>("/instrumentation/attitude-indicator/indicated-roll-deg",0));
    this->pathRead.insert(pair<string,double>("/instrumentation/attitude-indicator/internal-pitch-deg",0));
    this->pathRead.insert(pair<string,double>("/instrumentation/attitude-indicator/internal-roll-deg",0));
    this->pathRead.insert(pair<string,double>("/instrumentation/encoder/indicated-altitude-ft",0));
    this->pathRead.insert(pair<string,double>("/instrumentation/encoder/pressure-alt-ft",0));
    this->pathRead.insert(pair<string,double>("/instrumentation/gps/indicated-altitude-ft",0));
    this->pathRead.insert(pair<string,double>("/instrumentation/gps/indicated-ground-speed-kt",0));
    this->pathRead.insert(pair<string,double>("/instrumentation/gps/indicated-vertical-speed",0));
    this->pathRead.insert(pair<string,double>("/instrumentation/heading-indicator/indicated-heading-deg",0));
    this->pathRead.insert(pair<string,double>("/instrumentation/magnetic-compass/indicated-heading-deg",0));
    this->pathRead.insert(pair<string,double>("/instrumentation/slip-skid-ball/indicated-slip-skid",0));
    this->pathRead.insert(pair<string,double>("/instrumentation/turn-indicator/indicated-turn-rate",0));
    this->pathRead.insert(pair<string,double>("/instrumentation/vertical-speed-indicator/indicated-speed-fpm",0));
    this->pathRead.insert(pair<string,double>("/controls/flight/aileron",0));
    this->pathRead.insert(pair<string,double>("/controls/flight/elevator",0));
    this->pathRead.insert(pair<string,double>("/controls/flight/rudder",0));
    this->pathRead.insert(pair<string,double>("/controls/flight/flaps",0));
    this->pathRead.insert(pair<string,double>("/controls/engines/engine/throttle",0));
    this->pathRead.insert(pair<string,double>("/engines/engine/rpm",0));
}

vector<double> DataReaderServer::split(string buff) {
    vector<double> info;

    string vv = buff;
    int size = buff.size();
    string temp = buff;
    int co=0;
    int count1 = 0;
    co = temp.find_first_of("\n");
    if(co!=string::npos){

        temp = temp.substr(co+1,temp.size()-1);
        count1= 1;

    }
    co = temp.find_first_of("\n");
    if(co!=string::npos){

        count1=2;
    }


    size_t pos = 0;
    size_t found;
    string delimiter = ",";
    if(count1>1){

        found = buff.find_first_of("\n");
        buff = buff.substr(found+1, buff.size()-1);
        found = buff.find_first_of("\n");
        buff = buff.substr(0, found);

    }
    if(count1==1){
        found = buff.find_first_of("\n");
        buff = buff.substr(0, found);
    }



    int y = 0;
    while ((pos = buff.find(delimiter)) != string::npos) {

        if(pos!=0){info.push_back(stod(buff.substr(0, pos)));}
        //info.push_back(stod(buff.substr(0, pos)));
        buff.erase(0, pos + delimiter.length());
        y++;
    }
    string gg = buff;

    info.push_back(stod(buff.substr(0, pos)));
    return info;
}


void DataReaderServer::setMapPath(vector<double> path_values) {

    this->pathRead.at("/instrumentation/airspeed-indicator/indicated-speed-kt")=path_values[0];
    this->pathRead.at("/instrumentation/altimeter/indicated-altitude-ft")=path_values[1];
    this->pathRead.at("/instrumentation/altimeter/pressure-alt-ft")=path_values[2];
    this->pathRead.at("/instrumentation/attitude-indicator/indicated-pitch-deg")=path_values[3];
    this->pathRead.at("/instrumentation/attitude-indicator/indicated-roll-deg")=path_values[4];
    this->pathRead.at("/instrumentation/attitude-indicator/internal-pitch-deg")=path_values[5];
    this->pathRead.at("/instrumentation/attitude-indicator/internal-roll-deg")=path_values[6];
    this->pathRead.at("/instrumentation/encoder/indicated-altitude-ft")=path_values[7];
    this->pathRead.at("/instrumentation/encoder/pressure-alt-ft")=path_values[8];
    this->pathRead.at("/instrumentation/gps/indicated-altitude-ft")=path_values[9];
    this->pathRead.at("/instrumentation/gps/indicated-ground-speed-kt")=path_values[10];
    this->pathRead.at("/instrumentation/gps/indicated-vertical-speed")=path_values[11];
    this->pathRead.at("/instrumentation/heading-indicator/indicated-heading-deg")=path_values[12];
    this->pathRead.at("/instrumentation/magnetic-compass/indicated-heading-deg")=path_values[13];
    this->pathRead.at("/instrumentation/slip-skid-ball/indicated-slip-skid")=path_values[14];
    this->pathRead.at("/instrumentation/turn-indicator/indicated-turn-rate")=path_values[15];
    this->pathRead.at("/instrumentation/vertical-speed-indicator/indicated-speed-fpm")=path_values[16];
    this->pathRead.at("/controls/flight/aileron")=path_values[17];
    this->pathRead.at("/controls/flight/elevator")=path_values[18];
    this->pathRead.at("/controls/flight/rudder")=path_values[19];
    this->pathRead.at("/controls/flight/flaps")=path_values[20];
    this->pathRead.at("/controls/engines/engine/throttle")=path_values[21];
    this->pathRead.at("/engines/engine/rpm")=path_values[22];

}

void DataReaderServer::updateMap() {

    pthread_mutex_lock(this->mut);
    map<string,string>::iterator it=(this->mapPath)->begin();
    for(it; it!=this->mapPath->end();++it){
       string path = (*it).second;
       string varName = (*it).first;
       if((this->pathRead).count(path)==1){
           double val = (this->pathRead).at(path);
           this->realMap->at(varName) = val;
       }

    }
    pthread_mutex_unlock(this->mut);
}
