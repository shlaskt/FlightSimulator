//
// Created by Tomer & Eyal on 24/12/18.
//

#include "ExitCommand.h"

/**
 * exit from the program
 * @param lines
 * @param symbolTable
 * @param line
 * @return line- no need here
 */
int ExitCommand::doCommand(vector<vector<string>> lines, map<string, double> *symbolTable, int line) {
    this->server->stopLoop(); // stop reading
    // delete all dynamic allocations
    delete this->dijkstra;
    delete this->data_client;
    delete this->server;
    pthread_mutex_destroy(mut);
    delete this->mut;
    // print massage (test)
    // cout <<"program finished successfully";
    return 0;
}
