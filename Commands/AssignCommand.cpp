#include "AssignCommand.h"

/**
 * assign (update) the value in the right arg to the left arg
 * left arg must be declared var (if new var- VarCommand handle it)
 * right arg must be expression- var/num
 * @param lines
 * @param symbolTable
 * @param line
 * @return
 */
int AssignCommand::doCommand(vector<vector<string>> lines, map<string, double> *symbolTable, int line) {

    string var = "";
    //save the value we need to update
    for (int i = 2; i < lines[line].size(); i++) {
        var = var + lines[line][i] + " ";
    }
    double val;
    try {
        val=this->shunting_yard->dijkstratoi(var); // get the number / var value to assign the new var

    } catch (const out_of_range &no_such_var) {
        // if there is no var in this name- dijkstra throw error
        __throw_runtime_error("invalid params to var");
    }

    // lock mutex and update map
    pthread_mutex_lock(this->mut);
    if (symbolTable->count(lines[line][0])) {
        (*symbolTable)[lines[line][0]] = val;
    } else {
        __throw_runtime_error("var isn't exists - need to assign with 'var' command first");
    }
    pthread_mutex_unlock(this->mut);

    // update the data client
    if (this->server->getPath(lines[line][0]) != "") {
        string path = this->server->getPath(lines[line][0]);
        string str_to_set = SET + path + SPACE + to_string(val) + RN;
        this->client->setData(str_to_set);
    }

    return 3; // curr line
}
