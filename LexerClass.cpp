//
// Created by reut on 13/12/18.
//
#include "LexerClass.h"
#include <fstream>
#include <string.h>
#include <map>
#include <list>
#include <regex>

using namespace std;

vector<string> LexerClass::Lexer() {
    //reading from file or console
    string i ="openDataServer 5400 10 connect 127.0.0.1 5402";
    return splitToCommand(i);
}

vector<string> LexerClass:: splitToCommand(string line){

    vector<string> vecAfterLex;
    string enterTolist = "";
    regex number("[0-9,.]*");
    regex var_name("[a-zA-Z_][a-zA-Z_0-9]*");
    regex stringEx("[^]*");
    regex whiteSpaces("[\t,\n, ]");
    //regex operators("[+,-,/,*,=]");
    regex operators("[^]");
    smatch m;

    while(line.size()>0) {
        if (line[0] == '"') {
            regex_search(line, m, stringEx);
            for (unsigned i = 0; i < m.size(); ++i) {
                enterTolist += enterTolist + m.str(i);
            }
            vecAfterLex.push_back(enterTolist);
            line = line.substr(enterTolist.size(), line.size());
            enterTolist = "";
        } else if (line[0] == '\t' || line[0] == '\n' || line[0] == ' ') {
            regex_search(line, m, whiteSpaces);
            for (unsigned i = 0; i < m.size(); ++i) {
                enterTolist += enterTolist + m.str(i);
            }
            line = line.substr(enterTolist.size(), line.size());
            enterTolist = "";
        } else if (line[0] > 48 && line[0] < 58) {
            regex_search(line, m, number);
            for (unsigned i = 0; i < m.size(); ++i) {
                enterTolist += enterTolist + m.str(i);
            }
            vecAfterLex.push_back(enterTolist);
            line = line.substr(enterTolist.size(), line.size());
            enterTolist = "";
        } else if ((line[0] >= 65 && line[0] <= 90) || (line[0] >= 97 && line[0] <= 122)) {
            regex_search(line, m, var_name);
            for (unsigned i = 0; i < m.size(); ++i) {
                enterTolist += enterTolist + m.str(i);
            }
            vecAfterLex.push_back(enterTolist);
            line = line.substr(enterTolist.size(), line.size());
            enterTolist = "";
        } else {
            regex_search(line, m, operators);
            for (unsigned i = 0; i < m.size(); ++i) {
                enterTolist += enterTolist + m.str(i);
            }
            vecAfterLex.push_back(enterTolist);
            line = line.substr(enterTolist.size(), line.size());
            enterTolist = "";
        }

    }
    return vecAfterLex;
}

vector<vector<string>>  LexerClass:: readFromFile(string fileName){
    string command;
    string line;
    string buffer;
    size_t found;
    size_t begining = 0;
    vector<vector<string>> vector1;
    ifstream myfile (fileName);
    if(myfile.good()) {
        while (getline(myfile, line)) {
            vector<string> afterSplit= splitToCommand(line);
            if(afterSplit.size()>0){
                vector1.push_back(splitToCommand(line));
            }

        }
    }
    return vector1;
}


