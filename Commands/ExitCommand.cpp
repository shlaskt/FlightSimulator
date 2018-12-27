//
// Created by Eyal on 24/12/18.
//

#include "ExitCommand.h"

int ExitCommand::doCommand(vector<string> vec, map<string, double> *map1) {
    this->server->stopLoop();

    delete this->dij;
    delete this->client1;
    delete this->server;
    pthread_mutex_destroy(mut);
    delete this->mut;
    cout <<"exiiiittttt";

}
