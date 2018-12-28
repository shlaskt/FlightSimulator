#include "AssignCommand.h"

/**
 *
 * @param lines
 * @param symbol_table
 * @param index
 * @return
 */
int AssignCommand::doCommand(vector<vector<string>> lines, map<string, double> *symbol_table, int index) {

    string var = "";
    //save the value we need to update
    for (int i = 2; i < lines[index].size(); i++) {
        var = var + lines[index][i] + " ";
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
    if (symbol_table->count(lines[index][0])) {
        (*symbol_table)[lines[index][0]] = val;
    } else {
        __throw_runtime_error("var isn't exists - need to assign with 'var' command first");
    }
    pthread_mutex_unlock(this->mut);

    // update the data client
    if (this->server->getPath(lines[index][0]) != "") {
        string path = this->server->getPath(lines[index][0]);
        string str_to_set = SET + path + SPACE + to_string(val) + RN;
        this->client->setData(str_to_set);
    }

    return 3; // curr index
}
