//
// Created by Tomer & Eyal on 15/12/18.
//
#include "Interpreter.h"

using namespace std;


Interpreter::Interpreter(map<string, double> *symbolTable, map<string, Command *> *commandMap) {
    this->symbolTable = symbolTable;
    this->commandMap = commandMap;
}

int Interpreter::interpLine(vector<vector<string>> lines) {
    bool flagExit = false;
    for (int i = 0; i < lines.size(); i++) {
        //for the vars equal.
        int jump;
        if (symbolTable->count(lines[i][0]) == 1) {
            if (lines[i][1] != "=") {
                __throw_bad_exception();
            }
            this->commandMap->at("equal")->doCommand(lines, this->symbolTable, i);

        } else if (lines[i][0] == "while") {
            vector<vector<string>> newVec = lines;


            newVec.erase(newVec.begin(), newVec.begin() + i);
            int ind = this->countLoopIf(newVec);
            newVec.erase(newVec.begin() + ind + 1, newVec.begin() + newVec.size());
            this->commandMap->at("while")->doCommand(newVec, this->symbolTable, 0);
            i = i + ind;
        } else if (lines[i][0] == "if") {
            vector<vector<string>> newVec = lines;
            newVec.erase(newVec.begin(), newVec.begin() + i);
            int ind = this->countLoopIf(newVec);
            newVec.erase(newVec.begin() + ind + 1, newVec.begin() + newVec.size());
            this->commandMap->at("if")->doCommand(newVec, this->symbolTable, 0);
            i = i + ind;
        } else if (lines[i][0] == "exit") {

            this->commandMap->at("exit")->doCommand(lines, this->symbolTable, i);
            flagExit = true;


        } else {
            string dd = lines[i][0];
            //int count = commandMap->count(lines[i][0]);
            Command *co = this->commandMap->at(lines[i][0]);
            this->commandMap->at(lines[i][0])->doCommand(lines, this->symbolTable, i);

        }
    }
    //if he didnt call to exit
    if (!flagExit) {
        return 0;
    }
    return 1;
}

int Interpreter::countLoopIf(vector<vector<string>> lines) {
    int breaks = -1;
    int line = 0;
    int flag = 0;
    for (int i = 1; i < lines.size(); i++) {
        for (int j = 0; j < lines[i].size(); j++) {
            if ((lines[i][j] == "while") || (lines[i][j] == "if")) {
                flag++;
            }
            if ((lines[i][j] == "}")) {

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
    line = breaks;
    return line;
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
    string split;
    vector<string> spaces_split;
    while (getline(stream, split, sign)) {
        spaces_split.push_back(split);
    }
    return spaces_split;
}

vector<string> Interpreter::lexer(string line) {
    size_t found = line.find("\"");
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
    vector<vector<string>> lines;
    ifstream myfile(fileName);
    if (myfile.good()) {
        while (getline(myfile, line)) {
            vector<string> afterSplit = lexer(line);
            if (afterSplit.size() > 0) {
                lines.push_back(lexer(line));
            }

        }
    }
    return lines;
}


