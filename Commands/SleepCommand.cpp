//
// Created by Eyal on 21/12/18.
//

#include "SleepCommand.h"

int SleepCommand::doCommand(vector<string> vec, map<string, double> *map1) {
    int size = vec.size();
    string paramToSleep = "";
    for (int i = 1; i < size; i++) {
        paramToSleep = paramToSleep + vec[i] + " ";

    }
    double sleepVal = this->dijkstra1->toVl(paramToSleep);
    usleep(static_cast<unsigned int> (sleepVal * 1000));

}