#include "openServerCommand.h"
#include <pthread.h>

struct SocketData {
    double port;
    double timeRead;
    DataReaderServer *server_data;
};

int openServerCommand::doCommand(vector<vector<string>> lines, map<string, double> *symbol_table, int index) {
    int indexSeparate = 0;
    int flag = 0;
    //if there are just 2 parameters
    if (lines[index].size() == 3) {
        this->port = this->shunting_yard->dijkstratoi(lines[index][1]);
        this->time = this->shunting_yard->dijkstratoi(lines[index][2]);
        //its complicate expression
    } else {
        //if seperate by ","
        for (int t = 0; t < lines[index].size(); t++) {
            if (lines[index][t] == ",") {
                indexSeparate = t;
                flag = 1;
                break;
            }
        }
        //if seperate by " "
        if (flag == 0) {
            for (int t = 1; t < lines[index].size() - 1; t++) {
                if ((lines[index][t] != "/") && (lines[index][t] != "*")
                    && (lines[index][t] != "+") && (lines[index][t] != "-")
                    && (lines[index][t + 1] != "/") && (lines[index][t + 1] != "*")
                    && (lines[index][t + 1] != "+") && (lines[index][t + 1] != "-")) {
                    indexSeparate = t + 1;
                    flag = 2;
                    break;
                }

            }
        }

        //if the it separate by comma / two num separate by " " -sent to expression
        string portString = "";
        string timeString = "";
        for (int i = 1; i < indexSeparate; ++i) {
            portString = portString + lines[index][i] + " ";
        }
        int i;
        //if its ","
        if (flag == 1) {
            i = indexSeparate + 1;
        } else if (flag == 2) {
            i = indexSeparate;
        }
        for (i; i < lines[index].size(); ++i) {
            timeString = timeString + lines[index][i] + " ";
        }
        double portVal = this->shunting_yard->dijkstratoi(portString);
        double time = this->shunting_yard->dijkstratoi(timeString);
        this->port = portVal;
        this->time = time;
    }
    //open the thread
    struct SocketData *params = new SocketData;
    params->port = this->port;
    params->timeRead = this->time;
    params->server_data = this->server;
    this->OpenThread(params);
    delete (params);
    return 3;
}

void *OpenThreadFunc(void *args) {
    struct SocketData *params = (struct SocketData *) args;
    while (true) {

        auto x = params->server_data->readFromSock();
        if (x == "exit") break;
    }

    return nullptr;
}

void *openServerCommand::OpenThread(void *pVoid) {
    pthread_t trid;
    struct SocketData *params = (struct SocketData *) pVoid;
    params->server_data->openSocket(params->port, params->timeRead);
    pthread_create(&trid, nullptr, OpenThreadFunc, params);
    return 0;
}


