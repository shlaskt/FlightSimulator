//
// Created by Tomer & Eyal on 21/12/18.
//

#include "SleepCommand.h"

/**
 * sleep for x milisec
 * @param lines
 * @param symbolTable
 * @param line
 * @return
 */
int SleepCommand::doCommand(vector<vector<string>> lines, map<string, double> *symbolTable, int line) {
    // get the time to sleep
    int size = lines[line].size();
    string sleep_for;
    for (int i = 1; i < size; i++) {
        sleep_for += lines[line][i] + " ";
    }
    // try to evaluate sleep time
    double sleep;
    try {
        sleep = this->shunting_yard->dijkstratoi(sleep_for);
    } catch (const out_of_range &no_such_var) {
        // if there is no var in this name- dijkstra throw error
        __throw_runtime_error("Error in Sleep Command - invalid params");
    }
    // sleep for the given time (*1000 for milisec)
    usleep(static_cast<unsigned int> (sleep * MILI_SEC));
}