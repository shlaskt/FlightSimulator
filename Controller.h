//
// Created by eyal on 12/21/18.
//

#ifndef FLIGHTSIMULATOR_CONTROLLER_H
#define FLIGHTSIMULATOR_CONTROLLER_H


#include "DataManagement/CommandDataBase.h"
#include "InputReaders/StdinReader.h"
#include "InputReaders/FileReader.h"
#include "InputManagement.h"

class Controller {
private:
    CommandDataBase *command_data_base;
    VarDataBase *var_data_base;
    DataReaderServer *data_reader_server;
    InputReader *inputReader;
    vector<Expression *> to_delete;
    vector<vector<string>> lines_vector;
    vector<vector<string>::iterator> lines_iterators;

    bool CheckValidityOfConditionCommand(vector<string> &vec);

    Expression *getCommandFromLine(vector<string> &parsered_line, vector<string>::iterator &it_p);

    list<Expression *> conditionParser(bool find_parenthesis);

public:
    Controller(int argc, char *argv[]);

    ~Controller();

    void runProgram();
};


#endif //FLIGHTSIMULATOR_CONTROLLER_H
