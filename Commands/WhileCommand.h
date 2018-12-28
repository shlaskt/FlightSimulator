//
// Created by Tomer & Eyal on 18/12/18.
//

#ifndef FLIGHT_WHILECOMMAND_H
#define FLIGHT_WHILECOMMAND_H

#include "Command.h"
#include "../Interpreter.h"

class WhileCommand : public Command {

private:
    Interpreter *interpreter;
public:
    WhileCommand(DataReaderServer *serverData, Client *client1, Interpreter *interpreter1, Dijkstra *dij,
                 pthread_mutex_t *mut)
            : Command(serverData, client1, dij, mut) {
        this->interpreter = interpreter1;
    }

    virtual int doCommand(vector<vector<string>> vector1, map<string, double> *symbol_table, int index);

    bool checkCondition(string first, string second, string sign, map<string, double> *symbol_table);
};

#endif //FLIGHT_WHILECOMMAND_H
