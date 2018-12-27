#include "openServerCommand.h"
#include <pthread.h>

struct SocketData {
    double port;
    double timeRead;
    DataReaderServer *params_data_server;

};

int openServerCommand::doCommand(vector<vector<string>> vector1, map<string, double> *map1, int index) {

    //this->port = stoi(list1[1+index]);
    //this->time = stoi(list1[2+index]);
    int indexSeparate = 0;
    int flag = 0;
    //if there are just 2 parameters
    if (vector1[index].size() == 3) {
        this->port = this->dijkstra1->toVl(vector1[index][1]);
        this->time = this->dijkstra1->toVl(vector1[index][2]);
        //its complicate expression
    } else {


        //if seperate by ","
        for (int t = 0; t < vector1[index].size(); t++) {
            if (vector1[index][t] == ",") {
                indexSeparate = t;
                flag = 1;
                break;
            }
        }
        //if seperate by " "
        if (flag == 0) {
            for (int t = 1; t < vector1[index].size() - 1; t++) {
                if ((vector1[index][t] != "/") && (vector1[index][t] != "*")
                    && (vector1[index][t] != "+") && (vector1[index][t] != "-")
                    && (vector1[index][t + 1] != "/") && (vector1[index][t + 1] != "*")
                    && (vector1[index][t + 1] != "+") && (vector1[index][t + 1] != "-")) {
                    indexSeparate = t + 1;
                    flag = 2;
                    break;
                }

            }
        }

        //if the it separate by comma / two num separate by " " -sent to expression
        string portString = "";
        string timeString = "";
        for (int i = 1; i < indexSeparate; i++) {
            portString = portString + vector1[index][i] + " ";
        }
        int i;
        //if its ","
        if (flag == 1) {
            i = indexSeparate + 1;
        } else if (flag == 2) {
            i = indexSeparate;
        }
        for (i; i < vector1[index].size(); i++) {
            timeString = timeString + vector1[index][i] + " ";
        }
        double portVal = this->dijkstra1->toVl(portString);
        double time = this->dijkstra1->toVl(timeString);
        this->port = portVal;
        this->time = time;


    }

    //open the thread
    struct SocketData *params = new SocketData;
    params->port = this->port;
    params->timeRead = this->time;
    params->params_data_server = this->dataServer;
    this->OpenThread(params);
    delete (params);
    return 3;


}

void *OpenThreadFunc(void *args) {
    struct SocketData *params = (struct SocketData *) args;
    while (true) {

        auto x = params->params_data_server->readFromSock();
        if (x == "exit") break;
    }

    return nullptr;
}

void *openServerCommand::OpenThread(void *pVoid) {

    struct SocketData *params = (struct SocketData *) pVoid;
    pthread_t trid;
    params->params_data_server->createSock(params->port, params->timeRead);
    pthread_create(&trid, nullptr, OpenThreadFunc, params);
    return 0;
}


