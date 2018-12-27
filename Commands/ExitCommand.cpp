//
// Created by Eyal on 24/12/18.
//

#include "ExitCommand.h"

int ExitCommand::doCommand(vector<vector<string>> lines, map<string, double> *map1, int index) {
    this->server->stopLoop();
    delete this->dij;
    delete this->client1;
    delete this->server;
    pthread_mutex_destroy(mut);
    delete this->mut;
    cout << "Good bye, have a nice day.";
}
