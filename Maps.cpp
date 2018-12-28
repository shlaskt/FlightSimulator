

#include "Maps.h"
#include "Commands/openServerCommand.h"
#include "Commands/VarCommand.h"
#include "Commands/AssignCommand.h"
#include "Commands/ConnectCommand.h"
#include "Commands/WhileCommand.h"
#include "Commands/IfCommand.h"
#include "Commands/PrintCommand.h"
#include "Commands/SleepCommand.h"
#include "Commands/ExitCommand.h"

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
    Command* openData = new openServerCommand(this->server1,this->client,this->dijkstra2,this->mut);
    this->commandMap.insert(pair<string, Command*>("openDataServer",openData));

    Command* varCommand = new VarCommand(this->server1,this->client,this->dijkstra2,this->mut);
    this->commandMap.insert(pair<string, Command*>("var",varCommand));

    Command* equalCommand = new AssignCommand(this->server1,this->client,this->dijkstra2,this->mut);
    this->commandMap.insert(pair<string, Command*>("equal",equalCommand));

    Command* connectCommand = new ConnectCommand(this->server1,this->client,this->dijkstra2,this->mut);
    this->commandMap.insert(pair<string, Command*>("connect",connectCommand));

    Command* loopCommand = new WhileCommand(this->server1,this->client,this->pars,this->dijkstra2,this->mut);
    this->commandMap.insert(pair<string, Command*>("while",loopCommand));

    Command* ifCommand = new IfCommand(this->server1,this->client,this->pars,this->dijkstra2,this->mut);
    this->commandMap.insert(pair<string, Command*>("if",ifCommand));

    Command* printCommand = new PrintCommand(this->server1,this->client,this->dijkstra2,this->mut);
    this->commandMap.insert(pair<string, Command*>("print",printCommand));

    Command* sleepCommand = new SleepCommand(this->server1,this->client,this->dijkstra2,this->mut);
    this->commandMap.insert(pair<string, Command*>("sleep",sleepCommand));

    Command* exitCommand = new ExitCommand(this->server1,this->client,this->pars,this->dijkstra2,this->mut);
    this->commandMap.insert(pair<string, Command*>("exit",exitCommand));

}

void Maps::setServer(DataReaderServer* dataReaderServer,Client* client1) {
    this->server1 = dataReaderServer;
    this->client = client1;

}

void Maps::setDij(Dijkstra* dijkstra) {

    this->dijkstra2 = dijkstra;
}

map<string, Command *> *Maps::getComMap() {
    return &(this->commandMap);
}

void Maps::setInterpreter(Interpreter* p) {

    this->pars=p;
}


