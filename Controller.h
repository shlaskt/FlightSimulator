//
// Created by eyal on 12/21/18.
//

#ifndef FLIGHTSIMULATOR_CONTROLLER_H
#define FLIGHTSIMULATOR_CONTROLLER_H


#include "DataManagement/CommandDataBase.h"
#include "InputManagement.h"
#include "InputReaders/StdinReader.h"
#include "InputReaders/FileReader.h"
#include "InputReaders/InputReader.h"

class Controller {
private:
    CommandDataBase *command_data_base;
    VarDataBase *var_data_base;
    DataReaderServer *data_reader_server;
    InputReader *inputReader;
    vector<Expression *> to_delete;

    ExpressionCommand *getCommandFromLine(string line);

public:
    Controller(int argc, char *argv[]);

    ~Controller();

    vector<Expression *> conditionPareser();

    void runProgram();
};


#endif //FLIGHTSIMULATOR_CONTROLLER_H
