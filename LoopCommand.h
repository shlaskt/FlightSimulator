//
// Created by reut on 18/12/18.
//

#ifndef FLIGHT_WHILECOMMAND_H
#define FLIGHT_WHILECOMMAND_H

#include "Command.h"
#include "Parser.h"

class LoopCommand: public Command {

private:
    vector<Command> commands;
    vector<int> indexForCommand;
    Parser* parser;
public:
    LoopCommand(DataReaderServer* server5,DataClient* dataClient1,Parser* parser1,Dijkstra* dij,pthread_mutex_t *mut)
    :Command(server5,dataClient1,dij,mut)
    {
        this->parser = parser1;
    }
    virtual int doCommand(vector<vector<string>> vector1,map<string, double>* map1,int index);
    bool returnBoolSign(string first,string second,string sign, map<string, double> *map1);
    void MakeCommandsVectors(vector<string>);
};

#endif //FLIGHT_WHILECOMMAND_H
