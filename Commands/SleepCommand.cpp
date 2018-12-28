//
// Created by Tomer & Eyal on 21/12/18.
//

#include "SleepCommand.h"

int SleepCommand::doCommand(vector<vector<string>> vector1, map<string, double> *symbol_table, int index) {
    int size=vector1[index].size();
    string paramToSleep="";
    for (int i=1;i<size;i++){
        paramToSleep=paramToSleep+vector1[index][i]+" ";

    }
    double sleepVal = this->shunting_yard->dijkstratoi(paramToSleep);
    usleep(static_cast<unsigned int> (sleepVal * 1000));

}