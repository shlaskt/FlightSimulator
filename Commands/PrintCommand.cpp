//
// Created by Eyal on 20/12/18.
//

#include "PrintCommand.h"
#include "iostream"

int PrintCommand::doCommand(vector<string> vec, map<string, double> *map1) {

    int size = vec.size();
    int find = 0;
    if ((find = vec[1].find("\"")) != std::string::npos) {
        string to_print = vec[1];
        to_print.erase(to_print.begin() + find);
        find = to_print.find("\"");
        to_print.erase(to_print.begin() + find, to_print.begin() + to_print.size());
        std::cout << to_print << '\n';
    } else {
        string toPrint = "";
        for (int i = 1; i < size; i++) {
            toPrint = toPrint + vec[i] + " ";
        }
        double pri = this->dijkstra1->toVl(toPrint);
        cout << pri << '\n';

    }


    return 2;
}
