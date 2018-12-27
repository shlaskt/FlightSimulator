//
// Created by Eyal on 18/12/18.
//

#ifndef FLIGHT_WHILECOMMAND_H
#define FLIGHT_WHILECOMMAND_H

#include "ConditionCommand.h"

class WhileCommand : public ConditionCommand {
public:
    WhileCommand(DataReaderServer *server, Client *client,
                 Dijkstra *dij, pthread_mutex_t *mut);

    virtual int doCommand(vector<string> vec, map<string, double> *map1);

    virtual bool returnBoolSign(string first, string second, string sign, map<string, double> *map1);
};

#endif //FLIGHT_WHILECOMMAND_H
