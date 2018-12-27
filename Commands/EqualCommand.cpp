#include "EqualCommand.h"

int EqualCommand::doCommand(vector<string> vec, map<string, double> *map1) {

    //update the var in our map to according to the user change

    string valueExpr = "";
    //save the value we need to update
    for (int i = 2; i < vec.size(); i++) {
        valueExpr = valueExpr + vec[i] + " ";
    }
    double val = this->dijkstra1->toVl(valueExpr);


    pthread_mutex_lock(this->mut);
    if (map1->count(vec[0])) {
        (*map1)[vec[0]] = val;
    } else {
        // TODO error

    }
    pthread_mutex_unlock(this->mut);
    //check if it bind
    if (this->server1->getPath(vec[0]) != "") {
        string s = "set ";
        s = s + this->server1->getPath(vec[0]);
        s = s + " " + to_string(val) + "\r\n";
        this->client->setData(s);
    }

    return 3;
}
