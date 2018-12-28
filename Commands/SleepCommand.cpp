//
// Created by Tomer & Eyal on 21/12/18.
//

#include "SleepCommand.h"

int SleepCommand::doCommand(vector<vector<string>> lines, map<string, double> *symbol_table, int index) {
    int size=lines[index].size();
    string paramToSleep="";
    for (int i=1;i<size;i++){
        paramToSleep=paramToSleep+lines[index][i]+" ";

    }
    double sleepVal = this->shunting_yard->dijkstratoi(paramToSleep);
    usleep(static_cast<unsigned int> (sleepVal * 1000));

}