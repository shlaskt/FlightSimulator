#include "EqualCommand.h"

int EqualCommand::doCommand(vector<vector<string>> lines, map<string, double> *map1, int index) {

    //update the var in our map to according to the user change

    string valueExpr = "";
    //save the value we need to update
    for (int i = 2; i < lines[index].size(); i++) {
        valueExpr = valueExpr + lines[index][i] + " ";
    }
    double val = this->dijkstra->evluate(valueExpr);


    pthread_mutex_lock(this->mut);
    if (map1->count(lines[index][0])) {
        (*map1)[lines[index][0]] = val;
    } else {
        // TODO error

    }
    pthread_mutex_unlock(this->mut);
    //check if it bind
    if (this->dataServer->getPath(lines[index][0]) != "") {
        string s = "set ";
        s = s + this->dataServer->getPath(lines[index][0]);
        s = s + " " + to_string(val) + "\r\n";
        this->client->setData(s);
    }

    return 3;
}
