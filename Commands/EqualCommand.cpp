//
// Created by tomer on 12/20/18.
//

#include "EqualCommand.h"

/**
 * assign (update) the value in the right arg to the left arg
 * left arg must be declared var (if new var- VarCommand handle it)
 * right arg must be expression- var/num
 * @param itor iterator
 * @param server
 */
int EqualCommand::doCommand(vector<string> line, int i, DataReaderServer *server) {
    Dijkstra shunting_yard(varDataBase.getSymbolTable());
    string var = (line[i++]);
    double val;
    if(!varDataBase.isVarExists(var)){ // var isn't exists
        __throw_runtime_error("var isn't exists - need to assign with 'var' command first");
    }
    // else - var exists, make sure you have ' = '
    if(line[i++] != "=") __throw_runtime_error("Error in Equal - '=' excepted");
    // try to calculate to assign into the var
    try {
        val = shunting_yard((line[i++])); // get the number / var value to assign the exists var
    } catch (const out_of_range& no_such_var){
        // if there is no var in this name- dijkstra throw error
        __throw_runtime_error("Error in Equal - invalid params to var");
    }
    // update var
    varDataBase.assignVarValue(var, val); // without binding
    return i; // return index
}
