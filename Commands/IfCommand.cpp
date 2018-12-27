//
// Created by Eyal on 20/12/18.
//

#include "IfCommand.h"

int IfCommand::doCommand(vector<vector<string>> lines, map<string, double> *map1, int index) {

    int i = 1;
    string first = "";
    string second = "";
    while ((lines[index][i] != "<") && (lines[index][i] != ">") && (lines[index][i] != "=") &&
           (lines[index][i] != "!")) {
        first = first + lines[index][i] + " ";
        i++;
    }
    string sign = lines[index][i];
    i++;
    if (lines[index][i] == "=") {
        sign = sign + lines[index][i];
        i++;

    }
    while (lines[index][i] != "{") {
        second = second + lines[index][i] + " ";
        i++;
    }
    vector<vector<string>> newVactor = lines;
    newVactor.erase(newVactor.begin() + 0);
    for (int o = 0; o < newVactor[newVactor.size() - 1].size(); o++) {
        if (newVactor[newVactor.size() - 1][o] == "}") {
            newVactor[newVactor.size() - 1].erase(newVactor[newVactor.size() - 1].begin() + o);
            break;
        }
    }
    if (newVactor[newVactor.size() - 1].size() == 0) {
        newVactor.erase(newVactor.begin() + newVactor.size());
    }
    if (returnBoolSign(first, second, sign, map1)) {

        this->interpreter->interpreteFile(newVactor);
    }

    return 0;

}

bool IfCommand::returnBoolSign(string first, string second, string sign, map<string, double> *map1) {
    double firstParm = this->dijkstra->evluate(first);
    double secondParm = this->dijkstra->evluate(second);

    double firstVal = firstParm;
    double secondVal = secondParm;
    if (sign == ">=") {
        return (firstVal >= secondVal);
    } else if (sign == "<=") {
        return (firstVal <= secondVal);

    } else if (sign == "==") {
        return (firstVal == secondVal);

    } else if (sign == "!=") {
        return (firstVal != secondVal);
    } else if (sign == ">") {
        return (firstVal > secondVal);
    } else if (sign == "<") {
        return (firstVal < secondVal);

    } else {
        throw runtime_error("error on reading operator");
    }
}

