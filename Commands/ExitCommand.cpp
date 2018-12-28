//
// Created by Tomer & Eyal on 24/12/18.
//

#include "ExitCommand.h"

int ExitCommand::doCommand(vector<vector<string>> vector1, map<string, double> *symbol_table, int index) {
    this->server->endRead();

    delete this->dij;
    delete this->client1;
    delete this->server;
    pthread_mutex_destroy(mut);
    delete this->mut;
    cout <<"exit from the program";

}
