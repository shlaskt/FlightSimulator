//
// Created by Tomer & Eyal on 20/12/18.
//

#include "PrintCommand.h"
#include "iostream"

int PrintCommand::doCommand(vector<vector<string>> lines, map<string, double> *symbol_table, int index) {

    int size=lines[index].size();
    int find =0;
    if((find = lines[index][1].find("\""))!=std::string::npos){
        string to_print = lines[index][1];
        to_print.erase(to_print.begin()+find);
        find = to_print.find("\"");
        to_print.erase(to_print.begin()+find,to_print.begin()+ to_print.size());
        std::cout << to_print <<'\n';
    } else{
        string toPrint="";
        for(int i=1;i<size;i++){
            toPrint=toPrint+lines[index][i]+" ";
        }
        double to_print=this->shunting_yard->dijkstratoi(toPrint);
        cout << to_print <<'\n';

    }



    return 2;
}
