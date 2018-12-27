//
// Created by reut on 20/12/18.
//

#ifndef FLIGHT_IFCOMMAND_H
#define FLIGHT_IFCOMMAND_H

#include "Command.h"
#include "Parser.h"

class IfCommand : public Command{
private:
    Parser* parser;
public:
    IfCommand(DataReaderServer* server5,DataClient* dataClient1,Parser* parser1,Dijkstra* dij,pthread_mutex_t *mut)
    :Command(server5,dataClient1,dij,mut)
    {
        this->parser = parser1;
    }
    virtual int doCommand(vector<vector<string>> vector1,map<string, double>* map1,int index);
    bool returnBoolSign(string first,string second,string sign, map<string, double> *map1);


};


#endif //FLIGHT_IFCOMMAND_H
