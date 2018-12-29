//
// Created by Tomer & Eyal on 20/12/18.
//

#ifndef FLIGHT_IFCOMMAND_H
#define FLIGHT_IFCOMMAND_H

#include "Command.h"
#include "../Interpreter.h"

class IfCommand : public Command{
private:
    Interpreter* interpreter;
public:
    IfCommand(DataReaderServer* server5,Client* client1,Interpreter* interpreter1,Dijkstra* dij,pthread_mutex_t *mut)
    :Command(server5,client1,dij,mut){
        this->interpreter = interpreter1;
    }
    virtual int doCommand(vector<vector<string>> lines,map<string, double>* symbolTable,int line);
    bool checkCondition(string expression_1, string expression_2, string condition, map<string, double> *symbolTable);
};


#endif //FLIGHT_IFCOMMAND_H
