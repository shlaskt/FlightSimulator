
#include "WhileCommand.h"
#include <string>

using namespace std;

int WhileCommand::doCommand(vector<string> vec, map<string, double> *map1) {
    int size = vec.size();

    int i = 1;
    string first = "";
    string second = "";
    while ((vec[i] != "<") && (vec[i] != ">") && (vec[i] != "=") && (vec[i] != "!")) {
        first = first + vec[i] + " ";
        i++;
    }
    string sign = vec[i];
    i++;
    if (vec[i] == "=") {
        sign = sign + vec[i];
        i++;

    }
    while (vec[i] != "{") {
        second = second + vec[i] + " ";
        i++;
    }
    //double firstParm= this->dijkstra1->operator()(first);
    //double secondParm= this->dijkstra1->operator()(second);

//    vector<vector<string>> newVactor = vector1;
//    newVactor.erase(newVactor.begin() + 0);
//    //check the }
//    for (int o = 0; o < newVactor[newVactor.size() - 1].size(); o++) {
//        if (newVactor[newVactor.size() - 1][o] == "}") {
//            newVactor[newVactor.size() - 1].erase(newVactor[newVactor.size() - 1].begin() + o);
//            break;
//        }
//    }
//    //if the last vector is empty erase the vector
//    if (newVactor[newVactor.size() - 1].size() == 0) {
//        newVactor.erase(newVactor.begin() + newVactor.size());
//    }
    //newVactor.erase(newVactor.begin()+newVactor.size());

    while (returnBoolSign(first, second, sign, map1)) {
        auto it = commands.begin();
        for (it; it != commands.end(); ++it) {
            (*it)->doCommand(vec, map1);
            delete (*it);
        }
    }
    return 0;
}

bool WhileCommand::returnBoolSign(string first, string second, string sign, map<string, double> *map1) {
    double firstParm = this->dijkstra1->toVl(first);
    double secondParm = this->dijkstra1->toVl(second);

    double firstVal = firstParm;
    double secondVal = secondParm;
    //check if the first is var in map
    /*if(map1->count(first)==1){
        firstVal = map1->at(first);
    } else{
        firstVal=stod(first);
    }
    //check if the second is var in map
    if(map1->count(second)==1){
        secondVal= map1->at(second);
    }else{
        secondVal=stod(second);
    }*/

    if (sign == ">") {
        if (firstVal > secondVal) {
            return true;
        } else {
            return false;
        }


    } else if (sign == "<") {
        if (firstVal < secondVal) {
            return true;
        } else {
            return false;
        }


    } else if (sign == ">=") {
        if (firstVal >= secondVal) {
            return true;
        } else {
            return false;
        }


    } else if (sign == "<=") {
        if (firstVal <= secondVal) {
            return true;
        } else {
            return false;
        }


    } else if (sign == "==") {
        if (firstVal == secondVal) {
            return true;
        } else {
            return false;
        }
    } else if (sign == "!=") {
        if (firstVal != secondVal) {
            return true;
        } else {
            return false;
        }

    } else {
        __throw_bad_exception();
    }
}

WhileCommand::WhileCommand(DataReaderServer *s, Client *c,
                           Dijkstra *d,
                           pthread_mutex_t *m) : ConditionCommand(s, c, d, m) {};
