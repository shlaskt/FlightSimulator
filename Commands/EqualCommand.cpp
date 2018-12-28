#include "EqualCommand.h"

int EqualCommand::doCommand(vector<vector<string>> vector1, map<string, double> *symbol_table, int index) {

    //update the var in our map to according to the user change

    string valueExpr = "";
    //save the value we need to update
    for (int i = 2; i < vector1[index].size(); i++) {
        valueExpr = valueExpr + vector1[index][i] + " ";
    }
    double val = this->shunting_yard->dijkstratoi(valueExpr);


    pthread_mutex_lock(this->mut);
    if (symbol_table->count(vector1[index][0])) {
        (*symbol_table)[vector1[index][0]] = val;
    } else {
        // TODO error

    }
    pthread_mutex_unlock(this->mut);
    //check if it bind
    //if(this->server->getPath(list1[index+0])!= ""){
    if (this->server->getPath(vector1[index][0]) != "") {
        string s = "set ";
        s = s + this->server->getPath(vector1[index][0]);
        //s = s+" "+vector1[index][0]+"\r\n";
        s = s + " " + to_string(val) + "\r\n";
        this->client->setData(s);
    }

    return 3;
}
