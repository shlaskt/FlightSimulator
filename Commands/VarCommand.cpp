//
// Created by tomer on 12/20/18.
//

#include "VarCommand.h"

/**
 * assign var
 * if it should be bind -> bind it to the path
 * else - itsnt bind -> send it just to symbol map
 * after getting it's value
 * @param itor iterator on the string
 * @param server
 */
int VarCommand::doCommand(vector<string> line, int i, DataReaderServer *server, VarDataBase* var_data_base) {
    Dijkstra shunting_yard(var_data_base->getSymbolTable());
    string var_name = line.at(i++);
    // check valid input
    if (isdigit(var_name[0]) || var_name == "var"){ // var cant start with digit or called var
        __throw_runtime_error("invalid name of var");
    }
    if (line.at(i++) != "=") { // second arg must be operator "="
        __throw_runtime_error("invalid var assign-> '=' expected");
    }
    // check if bind assign or shallow assign
    if (line.at(i) == "bind") { // assign to path
        // can be bind to path, or bind to path of other var
        string arg_to_bind = line.at(++i);
        if (var_data_base->isVarExists(arg_to_bind)) { // var, bind to the var's path
            string path = var_data_base->getPath(arg_to_bind);
            var_data_base->createAndBindVarToPath(var_name, path);
        } else { // this is a path, bind directed to it
            var_data_base->createAndBindVarToPath(var_name, arg_to_bind);
        }
    } else { // no bind-> assign to expression
        double val;
        try {
            val = shunting_yard(line.at(i)); // get the number / var value to assign the new var

        } catch (const out_of_range &no_such_var) {
            // if there is no var in this name- dijkstra throw error
            __throw_runtime_error("invalid params to var");
        }
        var_data_base->assignVarValue(var_name, val);
    }
    return ++i; // increase index
}
