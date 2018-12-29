

#include "VarCommand.h"
#include <string>

#define VAR_NAME 1
#define BIND_PLACE 3
#define BIND_PATH 4
using namespace std;

/**
 * assign var
 * if it should be bind -> bind it to the path
 * else - itsnt bind -> send it just to symbol map
 * after getting it's value
 * @param lines
 * @param symbol_table
 * @param index
 * @return
 */
int VarCommand::doCommand(vector<vector<string>> lines, map<string, double> *symbol_table, int index) {

    string temp = lines[index][BIND_PLACE];
    string var = lines[index][VAR_NAME];

    /**
     * check if there is a need to bind the var.
     */
    if (temp == "bind") {
        // check valid name
        checkValidVarName(var);
        pthread_mutex_lock(this->mut); // lock mutex
        //add to map
        symbol_table->insert(pair<string, double>(var, 0));
        pthread_mutex_unlock(this->mut); // unlock mutex

        // check if its var bind var.
        if (symbol_table->count(lines[index][4]) == 1) {
            string path_to_bind = this->server->getPath(lines[index][4]);
            this->server->addNewPath(lines[index][1], path_to_bind);
        } else {
            string var = lines[index][VAR_NAME];
            string path = lines[index][BIND_PATH];
            path = path.substr(1, path.size() - 2);
            this->server->addNewPath(var, path);
        }
        this->server->updateSymbolTable();

        return 5;
    } else { //if var isn't bind
        string val_str = "";
        for (int i = 3; i < lines[index].size(); ++i) {
            val_str = val_str + lines[index][i] + " ";
        }
        // evaluate val
        double val;
        try {
            val = this->shunting_yard->dijkstratoi(val_str); // get the number / var value to assign the new var

        } catch (const out_of_range &no_such_var) {
            // if there is no var in this name- dijkstra throw error
            __throw_runtime_error("invalid params to var");
        }
        // lock mutex and update map
        pthread_mutex_lock(this->mut);
        symbol_table->insert(pair<string, double>(var, val));
        pthread_mutex_unlock(this->mut);

        return 4; // curr index
    }
}

/**
 * check if the var name is valid, means first char is not a digit and its not name var.
 * @param var_name var name.
 */
void VarCommand::checkValidVarName(string var_name) {
    if (isdigit(var_name[0]) || var_name == "var") { // var cant start with digit or called var
        __throw_runtime_error("invalid name of var");
    }
}

