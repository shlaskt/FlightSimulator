//
// Created by tomer on 12/20/18.
//

#include "PrintCommand.h"

/**
 * print can get string, number (or expression) or var
 * if start with ' " ' -> string, print it as is
 * if exists var with that name -> get it's value and print it
 * else -> expression, calculate and print
 * @param itor
 * @param server
 */
int PrintCommand::doCommand(vector<string> line, int i, DataReaderServer *server) {
    Dijkstra shunting_yard(varDataBase.getSymbolTable());
    string print_me = (line[i]); // take value to print
    if (print_me[0] == '"') { // string
        cout << print_me << endl;
    } else if (varDataBase.isVarExists(print_me)) { // var
        cout << varDataBase.getVarValue(print_me) << endl;
    } else { // expression
        try {
            cout << shunting_yard(print_me) << endl; // get the number / var value to assign the new var
        } catch (const out_of_range &no_such_var) {
            // if there is no var in this name- dijkstra throw error
            __throw_runtime_error("Error in PrintCommend : invalid params to print");
        }
    }
    return ++i; // increase index
}
