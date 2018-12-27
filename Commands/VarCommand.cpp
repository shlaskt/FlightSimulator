

#include "VarCommand.h"
#include <string>
using namespace std;
int VarCommand::doCommand(vector<vector<string>> lines,map<string, double>* map1,int index){

    // string temp = list1[index+3];
    string temp = lines[index][3];
    //if var is bind

    if(temp.compare("bind")==0){
        //add to map
        pthread_mutex_lock(this->mut);
        map1->insert(pair<string,double >(lines[index][1],0));
        pthread_mutex_unlock(this->mut);
        //if the 4th elemt is in the map
        if(map1->count(lines[index][4])==1){
            string path25 = this->dataServer->getPath(lines[index][4]);
            this->dataServer->addPath(lines[index][1],path25);
        } else{
            string nameVar = lines[index][1];
            string path = lines[index][4];
            path = path.substr(1,path.size()-2);
            this->dataServer->addPath(nameVar,path);
        }
        this->dataServer->updateMap();

        return 5;

        //if var isn't bind
    }else{
        string var = lines[index][1];
                                    //temp = list1[index+3];
        string valueExp="";
        for (int i=3;i<lines[index].size();i++){
            valueExp=valueExp+lines[index][i]+" ";
        }

        double val=this->dijkstra->evluate(valueExp);
        pthread_mutex_lock(this->mut);
        map1->insert(pair<string, double>(var,val));
        pthread_mutex_unlock(this->mut);

        return 4;

    }


}

