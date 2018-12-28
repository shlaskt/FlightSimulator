

#include "DataMaps.h"

map<string, double> *DataMaps::getSymbolMap() { return &(this->symbolTable); }

void DataMaps::initCommandMap() {
    Command *openData = new openServerCommand(this->data_server, this->client, this->shunting_yard, this->mut);
    this->commandMap.insert(pair<string, Command *>("openDataServer", openData));

    Command *connectCommand = new ConnectCommand(this->data_server, this->client, this->shunting_yard, this->mut);
    this->commandMap.insert(pair<string, Command *>("connect", connectCommand));

    Command *varCommand = new VarCommand(this->data_server, this->client, this->shunting_yard, this->mut);
    this->commandMap.insert(pair<string, Command *>("var", varCommand));

    Command *equalCommand = new AssignCommand(this->data_server, this->client, this->shunting_yard, this->mut);
    this->commandMap.insert(pair<string, Command *>("equal", equalCommand));

    Command *printCommand = new PrintCommand(this->data_server, this->client, this->shunting_yard, this->mut);
    this->commandMap.insert(pair<string, Command *>("print", printCommand));

    Command *sleepCommand = new SleepCommand(this->data_server, this->client, this->shunting_yard, this->mut);
    this->commandMap.insert(pair<string, Command *>("sleep", sleepCommand));

    Command *if_command = new IfCommand(this->data_server, this->client, this->pars, this->shunting_yard, this->mut);
    this->commandMap.insert(pair<string, Command *>("if", if_command));


    Command *while_command = new WhileCommand(this->data_server, this->client, this->pars, this->shunting_yard,
                                              this->mut);
    this->commandMap.insert(pair<string, Command *>("while", while_command));


    Command *exitCommand = new ExitCommand(this->data_server, this->client, this->pars, this->shunting_yard, this->mut);
    this->commandMap.insert(pair<string, Command *>("exit", exitCommand));

}

void DataMaps::setServer(DataReaderServer *dataReaderServer, Client *client_data) {
    this->data_server = dataReaderServer;
    this->client = client_data;

}

void DataMaps::setDij(Dijkstra *dijkstra) {

    this->shunting_yard = dijkstra;
}

map<string, Command *> *DataMaps::getComMap() {
    return &(this->commandMap);
}

void DataMaps::setInterpreter(Interpreter *p) {

    this->pars = p;
}


