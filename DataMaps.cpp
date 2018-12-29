

#include "DataMaps.h"

/**
 * constuctor getting mutex.
 * @param mut mutex.
 */
DataMaps::DataMaps(pthread_mutex_t *mut) {
    this->mut = mut;
}

/**
 * get symbol table.
 * @return symbol table.
 */
map<string, double> *DataMaps::getSymbolMap() { return &(this->symbolTable); }

/**
 * initilze all map data.
 */
void DataMaps::createComanndMap() {
    Command *whileCommand = new WhileCommand(this->data_server, this->client, this->pars, this->shunting_yard, this->mut);
    this->commandMap.insert(pair<string, Command *>("while", whileCommand));

    Command *ifCommand = new IfCommand(this->data_server, this->client, this->pars, this->shunting_yard, this->mut);
    this->commandMap.insert(pair<string, Command *>("if", ifCommand));
    Command *openData = new openServerCommand(this->data_server, this->client, this->shunting_yard, this->mut);
    this->commandMap.insert(pair<string, Command *>("openDataServer", openData));

    Command *varCommand = new VarCommand(this->data_server, this->client, this->shunting_yard, this->mut);
    this->commandMap.insert(pair<string, Command *>("var", varCommand));

    Command *equalCommand = new AssignCommand(this->data_server, this->client, this->shunting_yard, this->mut);
    this->commandMap.insert(pair<string, Command *>("equal", equalCommand));

    Command *connectCommand = new ConnectCommand(this->data_server, this->client, this->shunting_yard, this->mut);
    this->commandMap.insert(pair<string, Command *>("connect", connectCommand));

    Command *printCommand = new PrintCommand(this->data_server, this->client, this->shunting_yard, this->mut);
    this->commandMap.insert(pair<string, Command *>("print", printCommand));

    Command *sleepCommand = new SleepCommand(this->data_server, this->client, this->shunting_yard, this->mut);
    this->commandMap.insert(pair<string, Command *>("sleep", sleepCommand));

    Command *exitCommand = new ExitCommand(this->data_server, this->client, this->pars, this->shunting_yard, this->mut);
    this->commandMap.insert(pair<string, Command *>("exit", exitCommand));

}

void DataMaps::setDataServer(DataReaderServer *dataReaderServer, Client *client_data) {
    this->data_server = dataReaderServer;
    this->client = client_data;

}

void DataMaps::setDij(Dijkstra *dijkstra) {
    this->shunting_yard = dijkstra;
}

map<string, Command *> *DataMaps::getComanndMap() {
    return &(this->commandMap);
}

void DataMaps::setInterpreter(Interpreter *p) {
    this->pars = p;
}

DataMaps::~DataMaps() {
    map<string, Command *>::iterator it = this->commandMap.begin();
    for (it; it != this->commandMap.end(); ++it) {
        delete (*it).second;
    }
}

