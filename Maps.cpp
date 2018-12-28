

#include "Maps.h"
#include "Commands/openServerCommand.h"
#include "Commands/DefineVarCommand.h"
#include "Commands/EqualCommand.h"
#include "Commands/ConnectCommand.h"
#include "Commands/WhileCommand.h"
#include "Commands/IfCommand.h"
#include "Commands/PrintCommand.h"
#include "Commands/SleepCommand.h"
#include "Commands/ExitCommand.h"

map<string,double >* Maps::getSymbolMap() { return &(this->symbolTable);}



void Maps:: initMapCom(){
    Command* openData = new openServerCommand(this->dataServer,this->client,this->shunting_yard,this->mut);
    this->commandMap.insert(pair<string, Command*>("openDataServer",openData));

    Command* varCommand = new DefineVarCommand(this->dataServer,this->client,this->shunting_yard,this->mut);
    this->commandMap.insert(pair<string, Command*>("var",varCommand));

    Command* equalCommand = new EqualCommand(this->dataServer,this->client,this->shunting_yard,this->mut);
    this->commandMap.insert(pair<string, Command*>("equal",equalCommand));

    Command* connectCommand = new ConnectCommand(this->dataServer,this->client,this->shunting_yard,this->mut);
    this->commandMap.insert(pair<string, Command*>("connect",connectCommand));

    Command* whileCommand = new WhileCommand(this->dataServer,this->client,this->pars,this->shunting_yard,this->mut);
    this->commandMap.insert(pair<string, Command*>("while",whileCommand));

    Command* ifCommand = new IfCommand(this->dataServer,this->client,this->pars,this->shunting_yard,this->mut);
    this->commandMap.insert(pair<string, Command*>("if",ifCommand));

    Command* printCommand = new PrintCommand(this->dataServer,this->client,this->shunting_yard,this->mut);
    this->commandMap.insert(pair<string, Command*>("print",printCommand));

    Command* sleepCommand = new SleepCommand(this->dataServer,this->client,this->shunting_yard,this->mut);
    this->commandMap.insert(pair<string, Command*>("sleep",sleepCommand));

    Command* exitCommand = new ExitCommand(this->dataServer,this->client,this->pars,this->shunting_yard,this->mut);
    this->commandMap.insert(pair<string, Command*>("exit",exitCommand));

}

void Maps::setServer(DataReaderServer* dataReaderServer,Client* client1) {
    this->dataServer = dataReaderServer;
    this->client = client1;

}

void Maps::setDij(Dijkstra* dijkstra) {

    this->shunting_yard = dijkstra;
}

map<string, Command *> *Maps::getComMap() {
    return &(this->commandMap);
}

void Maps::setInterpreter(Interpreter* p) {

    this->pars=p;
}


