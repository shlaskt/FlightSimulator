

#include "VarCommand.h"
#include <string>
using namespace std;
/**
 * assign var
 * if it should be bind -> bind it to the path
 * else - itsnt bind -> send it just to symbol map
 * after getting it's value
 * @param lines
 * @param symbolTable
 * @param line
 * @return
 */
int VarCommand::doCommand(vector<vector<string>> lines,map<string, double>* symbolTable,int line){
    string temp = lines[line][3];
    // get var
    string var = lines[line][1];

    //if var is bind
    if(temp.compare("bind")==0){
        // check valid name
        checkValidVarName(var);
        pthread_mutex_lock(this->mut); // lock mutex
        //add to map
        symbolTable->insert(pair<string,double >(var,0));
        pthread_mutex_unlock(this->mut); // unlock mutex

        // if the 4th element is in the map
        if(symbolTable->count(lines[line][4])==1){
            string path_to_bind = this->server->getPath(lines[line][4]);
            this->server->addNewPath(lines[line][1], path_to_bind);
        } else{
            string var = lines[line][1];
            string path = lines[line][4];
            path = path.substr(1,path.size()-2);
            this->server->addNewPath(var, path);
        }
        this->server->updateSymbolTable();
        return 5; // curr index

    }else{ //if var isn't bind
        string val_str="";
        for (int i=3;i<lines[line].size();i++){
            val_str=val_str+lines[line][i]+" ";
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
        symbolTable->insert(pair<string, double>(var,val));
        pthread_mutex_unlock(this->mut);
        return 4; // curr index
    }
}

/**
 * check the valid of var name
 * @param var_name
 */
void VarCommand::checkValidVarName(string var_name) {
    if (isdigit(var_name[0]) || var_name == "var") { // var cant start with digit or called var
        __throw_runtime_error("invalid name of var");
    }
}

