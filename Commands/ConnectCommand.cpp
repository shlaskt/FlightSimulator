//
// Created by Eyal on 18/12/18.
//

#include <string.h>
#include "ConnectCommand.h"

int ConnectCommand::doCommand(vector<string> vec, map<string, double> *map1) {

    string second;

    //take care of the port number
    int size=vec.size();

    for(int i=2;i<size;i++){
        second=second+vec[i]+" ";
    }
    double portVal=this->dijkstra1->toVl(second);

    client->createSock(vec[1],portVal);
    return 3;
}
