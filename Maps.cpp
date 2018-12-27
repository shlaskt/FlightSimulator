

#include "Maps.h"
#include "openServerCommand.h"
#include "DefineVarCommand.h"
#include "EqualCommand.h"
#include "ConnectCommand.h"
#include "LoopCommand.h"
#include "IfCommand.h"
#include "PrintCommand.h"
#include "SleepCommand.h"
#include "ExitCommand.h"

void Maps::setSymbel(string var, double value){
    this->symbolTable.at(var)=value;
}

double Maps:: getSymbol(string var){
    return this->symbolTable.at(var);
}
Command* Maps:: getCommand(string comamnd){
    return this->commandMap.at(comamnd);
}
map<string,double >* Maps::getSymbolMap() { return &(this->symbolTable);}



void Maps:: initMapCom(){
    Command* openData = new openServerCommand(this->server1,this->dataClient,this->dijkstra2,this->mut);
    this->commandMap.insert(pair<string, Command*>("openDataServer",openData));

    Command* varCommand = new DefineVarCommand(this->server1,this->dataClient,this->dijkstra2,this->mut);
    this->commandMap.insert(pair<string, Command*>("var",varCommand));

    Command* equalCommand = new EqualCommand(this->server1,this->dataClient,this->dijkstra2,this->mut);
    this->commandMap.insert(pair<string, Command*>("equal",equalCommand));

    Command* connectCommand = new ConnectCommand(this->server1,this->dataClient,this->dijkstra2,this->mut);
    this->commandMap.insert(pair<string, Command*>("connect",connectCommand));

    Command* loopCommand = new LoopCommand(this->server1,this->dataClient,this->pars,this->dijkstra2,this->mut);
    this->commandMap.insert(pair<string, Command*>("while",loopCommand));

    Command* ifCommand = new IfCommand(this->server1,this->dataClient,this->pars,this->dijkstra2,this->mut);
    this->commandMap.insert(pair<string, Command*>("if",ifCommand));

    Command* printCommand = new PrintCommand(this->server1,this->dataClient,this->dijkstra2,this->mut);
    this->commandMap.insert(pair<string, Command*>("print",printCommand));

    Command* sleepCommand = new SleepCommand(this->server1,this->dataClient,this->dijkstra2,this->mut);
    this->commandMap.insert(pair<string, Command*>("sleep",sleepCommand));

    Command* exitCommand = new ExitCommand(this->server1,this->dataClient,this->pars,this->dijkstra2,this->mut);
    this->commandMap.insert(pair<string, Command*>("exit",exitCommand));

}

void Maps::setServer(DataReaderServer* dataReaderServer,DataClient* dataClient1) {
    this->server1 = dataReaderServer;
    this->dataClient = dataClient1;

}

void Maps::setDij(Dijkstra* dijkstra) {

    this->dijkstra2 = dijkstra;
}

map<string, Command *> *Maps::getComMap() {
    return &(this->commandMap);
}

void Maps::setParser(Parser* p) {

    this->pars=p;
}


