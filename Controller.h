//
// Created by eyal on 12/21/18.
//

#ifndef FLIGHTSIMULATOR_CONTROLLER_H
#define FLIGHTSIMULATOR_CONTROLLER_H


#include "DataManagement/CommandDataBase.h"
#include "InputReaders/StdinReader.h"
#include "InputReaders/FileReader.h"
#include "InputManagement.h"
#include "InputReaders/InputManager.h"

class Controller {
private:
    InputManager *inputManager;
    CommandDataBase *command_data_base;
    VarDataBase *var_data_base;
    Client *client;
    DataReaderServer *data_reader_server;
    vector<Expression *> to_delete;
    vector<InputReader*> input_to_delete;

    bool CheckValidityOfConditionCommand(vector<string> &vec);

    Expression *getCommandFromLine(vector<string> &parsered_line, int &index);

    vector<Expression *> conditionParser(bool find_parenthesis);

public:
    Controller(int argc, char *argv[]);

    ~Controller();

    void runProgram();
};


#endif //FLIGHTSIMULATOR_CONTROLLER_H
