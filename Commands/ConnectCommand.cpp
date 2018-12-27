//
// Created by Eyal on 18/12/18.
//

#include <string.h>
#include "ConnectCommand.h"

int ConnectCommand::doCommand(vector<vector<string>> lines, map<string, double> *map1, int index) {

    string second;

    //take care of the port number
    int size=lines[index].size();

    for(int i=2;i<size;i++){
        second=second+lines[index][i]+" ";
    }
    double port_value=this->dijkstra->evluate(second);

    client->createSock(lines[index][1],port_value);
    return 3;
}
