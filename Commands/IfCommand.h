//
// Created by Eyal on 20/12/18.
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
    :Command(server5,client1,dij,mut)
    {
        this->interpreter = interpreter1;
    }
    virtual int doCommand(vector<vector<string>> vector1,map<string, double>* map1,int index);
    bool returnBoolSign(string first,string second,string sign, map<string, double> *map1);


};


#endif //FLIGHT_IFCOMMAND_H
