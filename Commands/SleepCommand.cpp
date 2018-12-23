//
// Created by tomer on 12/20/18.
//

#include "SleepCommand.h"

/**
 * sleep for x milisec
 * @param itor x is given inside
 * @param server
 */
int SleepCommand::doCommand(vector<string> line, int i, DataReaderServer *server,
                            Client *client, VarDataBase *var_data_base) {
    Dijkstra shunting_yard(var_data_base->getSymbolTable());
    try {
        usleep(static_cast<unsigned int> (shunting_yard(line.at(i)) * MILI_SEC));
    } catch (const out_of_range &no_such_var) {
        // if there is no var in this name- dijkstra throw error
        __throw_runtime_error("Error in Sleep Command - invalid params");
    }
    return ++i; // increase index
}
