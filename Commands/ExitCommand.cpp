//
// Created by Tomer & Eyal on 24/12/18.
//

#include "ExitCommand.h"

/**
 * exit from the program
 * @param vector1
 * @param map1
 * @param index
 * @return index- no need here
 */
int ExitCommand::doCommand(vector<vector<string>> vector1, map<string, double> *map1, int index) {
    this->server->stopLoop(); // stop reading
    // delete all dynamic allocations
    delete this->dijkstra;
    delete this->data_client;
    delete this->server;
    pthread_mutex_destroy(mut);
    delete this->mut;
    // print massage
    cout <<"program finished successfully";
    return 0;
}
