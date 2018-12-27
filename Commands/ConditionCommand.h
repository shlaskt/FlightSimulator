//
// Created by eyal on 12/27/18.
//

#ifndef FLIGHT_CONDITIONCOMMAND_H
#define FLIGHT_CONDITIONCOMMAND_H

#include <pthread.h>
#include "Command.h"

class ConditionCommand : public Command {
protected:
    vector<Command *> commands;

public:
    void setCommands(vector<Command *> com) {
        this->commands = com;
    }

    ConditionCommand(DataReaderServer *server, Client *client,
                     Dijkstra *dij, pthread_mutex_t *mut)
            : Command(server, client, dij, mut) {
        this->commands = commands;
    }

    virtual int doCommand(vector<string> vec, map<string, double> *map1) = 0;

    virtual bool returnBoolSign(string first, string second, string sign, map<string, double> *map1) = 0;
};


#endif //FLIGHT_CONDITIONCOMMAND_H
