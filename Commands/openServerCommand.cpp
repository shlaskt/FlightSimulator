#include "openServerCommand.h"
#include <pthread.h>

/*
 * struct for the parameters to the thread func (can get just 1 arg)
 */
struct data_to_socket {
    double d_port;
    double d_time;
    DataReaderServer *d_server;
};

/**
 * doCommand (x,y)
 * open server on port x, listen y time per sec
 * use thread for read without stuck the program
 * @param lines
 * @param symbolTable
 * @param line
 * @return index
 */
int openServerCommand::doCommand(vector<vector<string>> lines, map<string, double> *symbolTable, int line) {
    // get the port and the time from the command
    getPortAndTime(lines, line);
    // create struct of parameters and init it
    struct data_to_socket *params = initParams();
    //open the thread
    this->createThread(params);
    // delete and return curr index
    delete (params);
    return 3;
}

/**
 * get the port and timr and set them in the members
 * check if valid
 * @param lines
 * @param line
 */
void openServerCommand::getPortAndTime(vector<vector<string>> lines, int line) {
    int separate = 0;
    int flag = 0;
    // if it is simple expression (like openDataServer n1, n2)
    if (lines[line].size() == 3) {
        try {
            // initialize port
            this->port = this->shunting_yard->dijkstratoi(lines[line][1]);
            // initialize time
            this->time = this->shunting_yard->dijkstratoi(lines[line][2]);
        } catch (const out_of_range &no_such_var) {
            // if there is no var in this name- dijkstra throw error
            __throw_runtime_error("invalid params to openServerCommand Command");
        } // if port or time are negative
        if (port < 0 || time < 0) __throw_runtime_error("invalid (neg) params to openServerCommand");

    } else { //its complicate expression
        //if seperate by "," (like openDataServer n1, -n2)
        for (int j = 0; j < lines[line].size(); j++) {
            if (lines[line][j] == ",") {
                separate = j;
                flag = 1;
                break;
            }
        }
        //if seperate by " "
        if (flag == 0) {
            for (int j = 1; j < lines[line].size() - 1; j++) {
                if ((lines[line][j] != "/") && (lines[line][j] != "*")
                    && (lines[line][j] != "+") && (lines[line][j] != "-")
                    && (lines[line][j + 1] != "/") && (lines[line][j + 1] != "*")
                    && (lines[line][j + 1] != "+") && (lines[line][j + 1] != "-")) {
                    separate = j + 1;
                    flag = 2;
                    break;
                }
            }
        }

        // if comma / two num separate by " " -sent to expression
        string s_port = "";
        string s_time = "";
        for (int i = 1; i < separate; i++) {
            s_port += lines[line][i] + " ";
        }
        int i;
        //if its ","
        if (flag == 1) {
            i = separate + 1;
        } else if (flag == 2) {
            i = separate;
        }
        for (i; i < lines[line].size(); i++) {
            s_time += lines[line][i] + " ";
        }
        try {
            // initialize port
            this->port = this->shunting_yard->dijkstratoi(s_port);
            // initialize time
            this->time = this->shunting_yard->dijkstratoi(s_time);
        } catch (const out_of_range &no_such_var) {
            // if there is no var in this name- dijkstra throw error
            __throw_runtime_error("invalid params to openServerCommand Command");
        } // if port or time are negative
        if (port < 0 || time < 0) __throw_runtime_error("invalid (neg) params to openServerCommand");
    }
}


/**
 * initialize struct of params
 * @return
 */
struct data_to_socket *openServerCommand::initParams() {
    // create struct
    struct data_to_socket *params = new data_to_socket;
    // init it
    params->d_port = this->port;
    params->d_time = this->time;
    params->d_server = this->server;
    return params;
}

/**
 * read from socket
 * void * func for the thread
 * @param args
 * @return
 */
void *readFromSocket(void *args) {
    // down casting from void*
    struct data_to_socket *params = (struct data_to_socket *) args;
    // read from sockest untill you got exit (we control it in the exit command)
    while (true) {
        auto x = params->d_server->readFromSock();
        if (x == "exit") break;
    }
    return nullptr;
}

/**
 * create thread to read from the simulator
 * @param pVoid
 * @return
 */
void *openServerCommand::createThread(void *pVoid) {
    // down casting from void*
    struct data_to_socket *params = (struct data_to_socket *) pVoid;
    pthread_t trid;
    params->d_server->openSocket(params->d_port, params->d_time);
    pthread_create(&trid, nullptr, readFromSocket, params);
    return 0;
}




