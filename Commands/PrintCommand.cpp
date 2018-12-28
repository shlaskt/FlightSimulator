//
// Created by Tomer & Eyal on 20/12/18.
//

#include "PrintCommand.h"
#include "iostream"

int PrintCommand::doCommand(vector<vector<string>> vector1, map<string, double> *symbol_table, int index) {

    int size = vector1[index].size();
    int find = 0;
    if ((find = vector1[index][1].find("\"")) != std::string::npos) {
        string print_string = vector1[index][1];
        print_string.erase(print_string.begin() + find);
        find = print_string.find("\"");
        print_string.erase(print_string.begin() + find, print_string.begin() + print_string.size());
        std::cout << print_string << '\n';
    } else {
        string toPrint = "";
        for (int i = 1; i < size; i++) {
            toPrint = toPrint + vector1[index][i] + " ";
        }
        double print_string = this->shunting_yard->dijkstratoi(toPrint);
        cout << print_string << '\n';

    }
    return 2;
}
