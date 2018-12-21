//
// Created by tomer on 12/20/18.
//

#include "SleepCommand.h"

/**
 * sleep for x milisec
 * @param itor x is given inside
 * @param server
 */
void SleepCommand::doCommand(vector<string>::iterator &itor, DataReaderServer *server) {
    Dijkstra shunting_yard(varDataBase.getSymbolTable());
    try {
        usleep(static_cast<unsigned int> (shunting_yard(*itor) * MILI_SEC));
    } catch (const out_of_range& no_such_var){
        // if there is no var in this name- dijkstra throw error
        __throw_runtime_error("Error in Sleep Command - invalid params");
    }
    ++itor; // increase iterator
}
