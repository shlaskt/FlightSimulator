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
int EqualCommand::doCommand(vector<string> line, int i, DataReaderServer *server,
                            Client *client, VarDataBase *var_data_base) {
    Dijkstra shunting_yard(var_data_base->getSymbolTable());
    string var = (line[i++]);
    double val;
    if (!var_data_base->isVarExists(var)) { // var isn't exists
        __throw_runtime_error("var isn't exists - need to assign with 'var' command first");
    }
    // else - var exists, make sure you have ' = '
    if (line[i++] != "=") __throw_runtime_error("Error in Equal - '=' excepted");
    // try to calculate to assign into the var
    try {
        val = shunting_yard((line[i++])); // get the number / var value to assign the exists var
    } catch (const out_of_range &no_such_var) {
        // if there is no var in this name- dijkstra throw error
        __throw_runtime_error("Error in Equal - invalid params to var");
    }
    // update var
    var_data_base->assignVarValue(var, val); // without binding

    // update the data client
    if (var_data_base->isVarBinded(var)) {
        string path = var_data_base->getPath(var);
        // delete first '  "/  ' and last '  "  ' from the path
        path = path.substr(2, path.length() - 3);
        // create the set command
        string s = "set";
        s += SPACE + path + SPACE + to_string(val) + RN;
        client->set(s); // send to set
    }
    return i; // return index
}
