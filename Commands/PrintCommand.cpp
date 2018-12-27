//
// Created by Eyal on 20/12/18.
//

#include "PrintCommand.h"
#include "iostream"

int PrintCommand::doCommand(vector<vector<string>> lines, map<string, double> *map1, int index) {

    int size=lines[index].size();
    int find =0;
    if((find = lines[index][1].find("\""))!=std::string::npos){
        string pri = lines[index][1];
        pri.erase(pri.begin()+find);
        find = pri.find("\"");
        pri.erase(pri.begin()+find,pri.begin()+ pri.size());
        std::cout << pri <<'\n';
    } else{
        string toPrint="";
        for(int i=1;i<size;i++){
            toPrint=toPrint+lines[index][i]+" ";
        }
        double pri=this->dijkstra->evluate(toPrint);
        cout << pri <<'\n';

    }



    return 2;
}
