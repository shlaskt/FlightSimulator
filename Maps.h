//
// Created by reut on 16/12/18.
//

#ifndef FLIGHT_MAPS_H
#define FLIGHT_MAPS_H

#include <map>
#include <string>
#include "Command.h"
#include "DataClient.h"
#include "Parser.h"
using namespace std;


class Maps {
private:
    map<string,double > symbolTable;
    map<string, Command*> commandMap;
    DataReaderServer* server1 ;
    DataClient* dataClient;
    Dijkstra* dijkstra2;
    Parser* pars;
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
    void setServer(DataReaderServer* dataReaderServer,DataClient* dataClient1 );
    void setDij(Dijkstra* dijkstra);
    void setParser(Parser* parser);
    ~Maps(){
        map<string,Command*>::iterator it = this->commandMap.begin();
        for(it;it!=this->commandMap.end();++it){

            delete (*it).second;
        }
    }


};


#endif //FLIGHT_MAPS_H
