//
// Created by reut on 16/12/18.
//

#include "Parser.h"

int Parser::interpLine(vector<vector<string>> vector1) {
    bool flagExit = false;
    for(int i = 0;i<vector1.size();i++){
        //for the vars equal.
        int jump;
        if(symbolTable->count(vector1[i][0])==1){
            if(vector1[i][1]!="="){
                __throw_bad_exception();
            }
            this->commandMap->at("equal")->doCommand(vector1,this->symbolTable,i);

        }
        else if(vector1[i][0]=="while"){
            vector<vector<string>> newVec=vector1;


            newVec.erase(newVec.begin(),newVec.begin()+i);
            int ind =this->countLoopIf(newVec);
            newVec.erase(newVec.begin()+ind+1,newVec.begin()+newVec.size());
            this->commandMap->at("while")->doCommand(newVec,this->symbolTable,0);
            i=i+ind;
        }else if(vector1[i][0]=="if"){
            vector<vector<string>> newVec=vector1;


            //TODO :
            //לבדוק אם חותך נכון
            newVec.erase(newVec.begin(),newVec.begin()+i);
            int ind =this->countLoopIf(newVec);
            newVec.erase(newVec.begin()+ind+1,newVec.begin()+newVec.size());
            this->commandMap->at("if")->doCommand(newVec,this->symbolTable,0);
            i=i+ind;
        } else if(vector1[i][0]=="exit"){

            this->commandMap->at("exit")->doCommand(vector1,this->symbolTable,i);
            flagExit = true;


        } else{
            string dd = vector1[i][0];
            //int count = commandMap->count(vector1[i][0]);
            Command* co = this->commandMap->at(vector1[i][0]);
            this->commandMap->at(vector1[i][0])->doCommand(vector1,this->symbolTable,i);

        }
    }
    //if he didnt call to exit
    if(!flagExit){
        return 0;
    }
    return 1;
}

int Parser::countLoopIf(vector<vector<string>> vector1) {
    int breaks = -1;
    int index = 0;
    int flag = 0;
    for(int i = 1;i<vector1.size();i++){
        for(int j = 0;j<vector1[i].size();j++){
            if((vector1[i][j]=="while")||(vector1[i][j]=="if")){
                flag++;
            }
            if((vector1[i][j]=="}")){

                if(flag==0){
                    breaks = i;
                }
                flag--;
            }
            if(breaks>=0){
                break;
            }
        }
        if(breaks>=0){
            break; }
    }
    index = breaks;
    return index;
}



