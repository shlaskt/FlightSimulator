//
// Created by Tomer & Eyal on 13/12/18.
//
#include "Interpreter.h"

using namespace std;


Interpreter::Interpreter(map<string, double> *symbolTable, map<string, Command *> *commandMap) {
    this->symbolTable = symbolTable;
    this->commandMap = commandMap;
}

int Interpreter::interpLine(vector<vector<string>> vector1) {
    bool flagExit = false;
    for (int i = 0; i < vector1.size(); i++) {
        //for the vars equal.
        int jump;
        if (symbolTable->count(vector1[i][0]) == 1) {
            if (vector1[i][1] != "=") {
                __throw_bad_exception();
            }
            this->commandMap->at("equal")->doCommand(vector1, this->symbolTable, i);

        } else if (vector1[i][0] == "while") {
            vector<vector<string>> newVec = vector1;


            newVec.erase(newVec.begin(), newVec.begin() + i);
            int ind = this->countLoopIf(newVec);
            newVec.erase(newVec.begin() + ind + 1, newVec.begin() + newVec.size());
            this->commandMap->at("while")->doCommand(newVec, this->symbolTable, 0);
            i = i + ind;
        } else if (vector1[i][0] == "if") {
            vector<vector<string>> newVec = vector1;


            //TODO :
            //לבדוק אם חותך נכון
            newVec.erase(newVec.begin(), newVec.begin() + i);
            int ind = this->countLoopIf(newVec);
            newVec.erase(newVec.begin() + ind + 1, newVec.begin() + newVec.size());
            this->commandMap->at("if")->doCommand(newVec, this->symbolTable, 0);
            i = i + ind;
        } else if (vector1[i][0] == "exit") {

            this->commandMap->at("exit")->doCommand(vector1, this->symbolTable, i);
            flagExit = true;


        } else {
            string dd = vector1[i][0];
            //int count = commandMap->count(vector1[i][0]);
            Command *co = this->commandMap->at(vector1[i][0]);
            this->commandMap->at(vector1[i][0])->doCommand(vector1, this->symbolTable, i);

        }
    }
    //if he didnt call to exit
    if (!flagExit) {
        return 0;
    }
    return 1;
}

int Interpreter::countLoopIf(vector<vector<string>> vector1) {
    int breaks = -1;
    int index = 0;
    int flag = 0;
    for (int i = 1; i < vector1.size(); i++) {
        for (int j = 0; j < vector1[i].size(); j++) {
            if ((vector1[i][j] == "while") || (vector1[i][j] == "if")) {
                flag++;
            }
            if ((vector1[i][j] == "}")) {

                if (flag == 0) {
                    breaks = i;
                }
                flag--;
            }
            if (breaks >= 0) {
                break;
            }
        }
        if (breaks >= 0) {
            break;
        }
    }
    index = breaks;
    return index;
}

/**
 * sets the spaces to be ok.
 * @param line to convert.
 * @return the line after fine spaces.
 */
string addSpaces(string line) {
    string output;
    bool in_quotation_marks = false;
    if (line == "") return line;
    for (char ch : line) {
        switch (ch) {
            case ' ': {
                if (output.back() != ' ' && !output.empty()) output += ' ';
                break;
            }
            case '\"': {
                output += ch;
                in_quotation_marks = !in_quotation_marks;
                break;
            }
            case '+':
            case '-':
            case '*':
            case '/':
            case '=':
            case '>':
            case '<':
            case '!':
            case ',':
            case '{':
            case '}':
            case ')':
            case '(': {
                if (!in_quotation_marks) {
                    //first letter of the line, no space.
                    if (output.empty() || output.back() == ' ') {
                        output += ch;
                        output += ' ';
                    } else {
                        output += ' ';
                        output += ch;
                        output += ' ';
                    }
                    break;
                }
            }
            default: {
                output += ch;
            }
        }
    }
    //if the last char is space, delete it.
    if (output.back() == ' ') output.pop_back();
    return output;
}

/**
 * split line to vector by separate sign
 * e.x - splitLine("hey-you-o", v, '-')
 *          --> v = {"hey", "you", "o"}
 * @param line to split
 * @param sign to separte
 */
vector<string> splitLine(const string &line, char sign) {
    stringstream stream(line);
    bool qoute = false;
    string print = "";
    string split;
    vector<string> spaces_split;
    while (getline(stream, split, sign)) {
        spaces_split.push_back(split);
    }
    return spaces_split;
}

vector<string> Interpreter::lexer(string line) {
    size_t found = line.find("print");
    if (found != string::npos) {
        return lexerWithqute(line);
    }
    return splitLine(addSpaces(line), ' ');
}

vector<string> Interpreter::lexerWithqute(string line) {

    vector<string> vecAfterLex;
    string enterTolist = "";
    regex number("[0-9,.]*");
    regex var_name("[a-zA-Z_][a-zA-Z_0-9]*");
    regex stringEx("[^]*");
    regex whiteSpaces("[\t,\n, ]");
    //regex operators("[+,-,/,*,=]");
    regex operators("[^]");
    smatch m;

    while (line.size() > 0) {
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

vector<vector<string>> Interpreter::readFromFile(string fileName) {
    string command;
    string line;
    string buffer;
    size_t found;
    size_t begining = 0;
    vector<vector<string>> vector1;
    ifstream myfile(fileName);
    if (myfile.good()) {
        while (getline(myfile, line)) {
            vector<string> afterSplit = lexer(line);
            if (afterSplit.size() > 0) {
                vector1.push_back(lexer(line));
            }

        }
    }
    return vector1;
}


