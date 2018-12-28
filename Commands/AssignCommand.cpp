#include "AssignCommand.h"

/**
 * assign (update) the value in the right arg to the left arg
 * left arg must be declared var (if new var- VarCommand handle it)
 * right arg must be expression- var/num
 * @param vector1
 * @param map1
 * @param index
 * @return
 */
int AssignCommand::doCommand(vector<vector<string>> vector1, map<string, double> *map1, int index) {

    string var = "";
    //save the value we need to update
    for (int i = 2; i < vector1[index].size(); i++) {
        var = var + vector1[index][i] + " ";
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
    if (map1->count(vector1[index][0])) {
        (*map1)[vector1[index][0]] = val;
    } else {
        __throw_runtime_error("var isn't exists - need to assign with 'var' command first");
    }
    pthread_mutex_unlock(this->mut);

    // update the data client
    if (this->server->getPath(vector1[index][0]) != "") {
        string path = this->server->getPath(vector1[index][0]);
        string str_to_set = SET + path + SPACE + to_string(val) + RN;
        this->client->setData(str_to_set);
    }

    return 3; // curr index
}
