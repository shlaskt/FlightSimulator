//
// Created by Eyal on 20/12/18.
//

#ifndef FLIGHT_IFCOMMAND_H
#define FLIGHT_IFCOMMAND_H

#include "ConditionCommand.h"

class IfCommand : public ConditionCommand {
public:
    IfCommand(DataReaderServer *server, Client *client,
              Dijkstra *dij, pthread_mutex_t *mut);

    virtual int doCommand(vector<string> vec, map<string, double> *map1);

    virtual bool returnBoolSign(string first, string second, string sign, map<string, double> *map1);


};


#endif //FLIGHT_IFCOMMAND_H
