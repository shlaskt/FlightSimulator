//
// Created by eyal on 12/18/18.
//

#ifndef FLIGHTSIMULATOR_EXPRESSIONCOMMAND_H
#define FLIGHTSIMULATOR_EXPRESSIONCOMMAND_H


#include "../Commands/Command.h"
#include "Expression.h"
#include "../Sockets/DataReaderServer.h"
#include "../Sockets/Client.h"
#include <vector>

class ExpressionCommand : public Expression {
private:
    Command *command;
    vector<string> line;
    int index;
    DataReaderServer *reader;
    Client *client;
    VarDataBase *varDataBase;

public:
    ExpressionCommand(Command *command, const vector<string> &line, int index, DataReaderServer *reader, Client *client,
                      VarDataBase *varDataBase);

    double calculate();

};


#endif //FLIGHTSIMULATOR_EXPRESSIONCOMMAND_H
