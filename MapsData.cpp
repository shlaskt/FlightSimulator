

#include "MapsData.h"

map<string, double> *MapsData::getSymbolMap() { return &(this->symbolTable); }


void MapsData::initMapCom() {
    Command *openData = new openServerCommand(this->dataServer, this->client, this->dijkstra2, this->mut);
    this->commandMap.insert(pair<string, Command *>("openDataServer", openData));

    Command *varCommand = new VarCommand(this->dataServer, this->client, this->dijkstra2, this->mut);
    this->commandMap.insert(pair<string, Command *>("var", varCommand));

    Command *equalCommand = new EqualCommand(this->dataServer, this->client, this->dijkstra2, this->mut);
    this->commandMap.insert(pair<string, Command *>("equal", equalCommand));

    Command *connectCommand = new ConnectCommand(this->dataServer, this->client, this->dijkstra2, this->mut);
    this->commandMap.insert(pair<string, Command *>("connect", connectCommand));

    Command *whileCommand = new WhileCommand(this->dataServer, this->client, this->pars, this->dijkstra2, this->mut);
    this->commandMap.insert(pair<string, Command *>("while", whileCommand));

    Command *ifCommand = new IfCommand(this->dataServer, this->client, this->pars, this->dijkstra2, this->mut);
    this->commandMap.insert(pair<string, Command *>("if", ifCommand));

    Command *printCommand = new PrintCommand(this->dataServer, this->client, this->dijkstra2, this->mut);
    this->commandMap.insert(pair<string, Command *>("print", printCommand));

    Command *sleepCommand = new SleepCommand(this->dataServer, this->client, this->dijkstra2, this->mut);
    this->commandMap.insert(pair<string, Command *>("sleep", sleepCommand));

    Command *exitCommand = new ExitCommand(this->dataServer, this->client, this->pars, this->dijkstra2, this->mut);
    this->commandMap.insert(pair<string, Command *>("exit", exitCommand));

}

void MapsData::setServer(DataReaderServer *dataReaderServer, Client *client1) {
    this->dataServer = dataReaderServer;
    this->client = client1;

}

void MapsData::setDij(Dijkstra *dijkstra) {

    this->dijkstra2 = dijkstra;
}

map<string, Command *> *MapsData::getComMap() {
    return &(this->commandMap);
}

void MapsData::setInterpreter(Interpreter *p) {

    this->pars = p;
}

MapsData::~MapsData() {
    map<string, Command *>::iterator it = this->commandMap.begin();
    for (it; it != this->commandMap.end(); ++it) {

        delete (*it).second;
    }
}


