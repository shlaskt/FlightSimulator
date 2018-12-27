//
// Created by Tomer & Eyal on 18/12/18.
//

#ifndef FLIGHT_WHILECOMMAND_H
#define FLIGHT_WHILECOMMAND_H

#include "Command.h"
#include "../Interpreter.h"

class LoopCommand: public Command {

private:
    vector<Command> commands;
    vector<int> indexForCommand;
    Interpreter* interpreter;
public:
    LoopCommand(DataReaderServer* server5,Client* client1,Interpreter* interpreter1,Dijkstra* dij,pthread_mutex_t *mut)
    :Command(server5,client1,dij,mut)
    {
        this->interpreter = interpreter1;
    }
    virtual int doCommand(vector<vector<string>> vector1,map<string, double>* map1,int index);
    bool returnBoolSign(string first,string second,string sign, map<string, double> *map1);
    void MakeCommandsVectors(vector<string>);
};

#endif //FLIGHT_WHILECOMMAND_H
