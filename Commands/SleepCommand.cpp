//
// Created by reut on 21/12/18.
//

#include "SleepCommand.h"

int SleepCommand::doCommand(vector<vector<string>> vector1, map<string, double> *map1, int index) {
    int size=vector1[index].size();
    string paramToSleep="";
    for (int i=1;i<size;i++){
        paramToSleep=paramToSleep+vector1[index][i]+" ";

    }
    double sleepVal = this->dijkstra1->toVl(paramToSleep);
    usleep(static_cast<unsigned int> (sleepVal * 1000));

}