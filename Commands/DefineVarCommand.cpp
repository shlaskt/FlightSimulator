

#include "DefineVarCommand.h"
#include <string>
using namespace std;
/**
 * assign var
 * if it should be bind -> bind it to the path
 * else - itsnt bind -> send it just to symbol map
 * after getting it's value
 * @param vector1
 * @param map1
 * @param index
 * @return
 */
int DefineVarCommand::doCommand(vector<vector<string>> vector1,map<string, double>* map1,int index){

    // string temp = list1[index+3];
    string temp = vector1[index][3];
    string var = vector1[index][1];

    //if var is bind
    if(temp.compare("bind")==0){
        // check valid name
        checkValidVarName(var);
        pthread_mutex_lock(this->mut); // lock mutex
        //add to map
        map1->insert(pair<string,double >(var,0));
        pthread_mutex_unlock(this->mut); // unlock mutex

        // if the 4th element is in the map
        if(map1->count(vector1[index][4])==1){
            string path_to_bind = this->server->getPath(vector1[index][4]);
            this->server->addNewPath(vector1[index][1], path_to_bind);
        } else{
            string var = vector1[index][1];
            string path = vector1[index][4];
            path = path.substr(1,path.size()-2);
            this->server->addNewPath(var, path);
        }
        this->server->updateSymbolTable();

        return 5; // curr index

    }else{ //if var isn't bind
        string val_str="";
        for (int i=3;i<vector1[index].size();i++){
            val_str=val_str+vector1[index][i]+" ";
        }
        // evaluate val
        double val;
        try {
            val=this->shunting_yard->dijkstratoi(val_str); // get the number / var value to assign the new var

        } catch (const out_of_range &no_such_var) {
            // if there is no var in this name- dijkstra throw error
            __throw_runtime_error("invalid params to var");
        }
        // lock mutex and update map
        pthread_mutex_lock(this->mut);
        map1->insert(pair<string, double>(var,val));
        pthread_mutex_unlock(this->mut);

        return 4; // curr index
    }
}

void DefineVarCommand::checkValidVarName(string var_name) {
    if (isdigit(var_name[0]) || var_name == "var") { // var cant start with digit or called var
        __throw_runtime_error("invalid name of var");
    }
}

