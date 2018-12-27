

#include "DefineVarCommand.h"
#include <string>
using namespace std;
int DefineVarCommand::doCommand(vector<string> vec,map<string, double> *map1){

    // string temp = list1[index+3];
    string temp = vec[3];
    //if var is bind

    if(temp.compare("bind")==0){
        //add to map
        pthread_mutex_lock(this->mut);
        map1->insert(pair<string,double >(vec[1],0));
        pthread_mutex_unlock(this->mut);
        //if the 4th elemt is in the map
        if(map1->count(vec[4])==1){
            string path25 = this->server1->getPath(vec[4]);
            this->server1->addPath(vec[1],path25);
        } else{
            string nameVar = vec[1];
            string path = vec[4];
            path = path.substr(1,path.size()-2);
            this->server1->addPath(nameVar,path);
        }
        this->server1->updateMap();

        return 5;

        //if var isn't bind
    }else{
        string var = vec[1];
                                    //temp = list1[index+3];
        string valueExp="";
        for (int i=3;i<vec.size();i++){
            valueExp=valueExp+vec[i]+" ";
        }

        double val=this->dijkstra1->toVl(valueExp);
        pthread_mutex_lock(this->mut);
        map1->insert(pair<string, double>(var,val));
        pthread_mutex_unlock(this->mut);

        return 4;

    }


}

