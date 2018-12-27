//
// Created by Eyal on 16/12/18.
//

#ifndef FLIGHT_MAPS_H
#define FLIGHT_MAPS_H

#include <map>
#include <string>
#include "Commands/Command.h"
#include "Commands/Client.h"
#include "Interpreter.h"
using namespace std;


class Maps {
private:
    map<string,double > symbolTable;
    map<string, Command*> commandMap;
    DataReaderServer* server1 ;
    Client* client;
    Dijkstra* dijkstra2;
    Interpreter* pars;
    pthread_mutex_t *mut;
public:
    Maps(pthread_mutex_t *mut){
        this->mut = mut;
    }
    void setSymbel(string var, double value);
    double getSymbol(string var);
    Command* getCommand(string comamnd);
    map<string,double >* getSymbolMap();
    map<string,Command* >* getComMap();
    void initMapCom();
    void setServer(DataReaderServer* dataReaderServer,Client* client1 );
    void setDij(Dijkstra* dijkstra);
    void setInterpreter(Interpreter* interpreter);
    ~Maps(){
        map<string,Command*>::iterator it = this->commandMap.begin();
        for(it;it!=this->commandMap.end();++it){

            delete (*it).second;
        }
    }


};


#endif //FLIGHT_MAPS_H
