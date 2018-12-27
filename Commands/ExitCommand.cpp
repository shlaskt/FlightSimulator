//
// Created by reut on 24/12/18.
//

#include "ExitCommand.h"

int ExitCommand::doCommand(vector<vector<string>> vector1, map<string, double> *map1, int index) {
    this->server->stopLoop();

    delete this->dij;
    delete this->dataClient1;
    delete this->server;
    pthread_mutex_destroy(mut);
    delete this->mut;
    cout <<"exiiiittttt";

}
