//
// Created by Eyal on 13/12/18.
//
#include "Interpreter.h"

using namespace std;


/**
 * Interpreter constructor.
 * @param symbolTable of the agruments.
 * @param commandMap command map.
 */
Interpreter::Interpreter(map<string, double> *symbolTable, map<string, Command *> *commandMap) {
    this->symbolTable = symbolTable;
    this->commandMap = commandMap;
}

int Interpreter::interpLine(vector<string> parsered_line) {
    bool flagExit = false;
    //for the vars equal.
    int jump;
    //check if there is no var like this.
    if (symbolTable->count(parsered_line[0]) == 1) {
        if (parsered_line[1] != "=") {
            throw runtime_error("no such var");
        }
        this->commandMap->at("equal")->doCommand(parsered_line, this->symbolTable, i);
    } else if (parsered_line[0] == "while") {
        vector<string> newVec = parsered_line;

        // TODO:
        //fix it to be one line.
        //no need for this lines
        //newVec.erase(newVec.begin(), newVec.begin() + i);
        //int ind = countLoopIf(newVec);
        //newVec.erase(newVec.begin() + ind + 1, newVec.begin() + newVec.size());
        //this->commandMap->at("while")->doCommand(newVec, this->symbolTable, 0);
        //i = i + ind;
    } else if (parsered_line[0] == "if") {
        //vector<string> newVec = parsered_line;


        // TODO:
        //לבדוק אם חותך נכון
        //newVec.erase(newVec.begin(), newVec.begin() + i);
        //int ind = this->countLoopIf(newVec);
        //newVec.erase(newVec.begin() + ind + 1, newVec.begin() + newVec.size());
        //this->commandMap->at("if")->doCommand(newVec, this->symbolTable, 0);
        //i = i + ind;
    } else if (parsered_line[0] == "exit") {

        this->commandMap->at("exit")->doCommand(parsered_line, this->symbolTable, i);
        flagExit = true;


    } else {
        string dd = parsered_line[0];
        //int count = commandMap->count(parsered_line[i][0]);
        Command *co = this->commandMap->at(parsered_line[0]);
        this->commandMap->at(parsered_line[0])->doCommand(parsered_line, this->symbolTable, i);

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
    string split;
    vector<string> spaces_split;
    while (getline(stream, split, sign)) {
        spaces_split.push_back(split);
    }
    return spaces_split;
}

vector<string> Interpreter::lexer(string line) {
    return splitLine(addSpaces(line), ' ');
}

//vector<string> LexerClass:: lexer(string line){
//
//    vector<string> vecAfterLex;
//    string enterTolist = "";
//    regex number("[0-9,.]*");
//    regex var_name("[a-zA-Z_][a-zA-Z_0-9]*");
//    regex stringEx("[^]*");
//    regex whiteSpaces("[\t,\n, ]");
//    //regex operators("[+,-,/,*,=]");
//    regex operators("[^]");
//    smatch m;
//
//    while(line.size()>0) {
//        if (line[0] == '"') {
//            regex_search(line, m, stringEx);
//            for (unsigned i = 0; i < m.size(); ++i) {
//                enterTolist += enterTolist + m.str(i);
//            }
//            vecAfterLex.push_back(enterTolist);
//            line = line.substr(enterTolist.size(), line.size());
//            enterTolist = "";
//        } else if (line[0] == '\t' || line[0] == '\n' || line[0] == ' ') {
//            regex_search(line, m, whiteSpaces);
//            for (unsigned i = 0; i < m.size(); ++i) {
//                enterTolist += enterTolist + m.str(i);
//            }
//            line = line.substr(enterTolist.size(), line.size());
//            enterTolist = "";
//        } else if (line[0] > 48 && line[0] < 58) {
//            regex_search(line, m, number);
//            for (unsigned i = 0; i < m.size(); ++i) {
//                enterTolist += enterTolist + m.str(i);
//            }
//            vecAfterLex.push_back(enterTolist);
//            line = line.substr(enterTolist.size(), line.size());
//            enterTolist = "";
//        } else if ((line[0] >= 65 && line[0] <= 90) || (line[0] >= 97 && line[0] <= 122)) {
//            regex_search(line, m, var_name);
//            for (unsigned i = 0; i < m.size(); ++i) {
//                enterTolist += enterTolist + m.str(i);
//            }
//            vecAfterLex.push_back(enterTolist);
//            line = line.substr(enterTolist.size(), line.size());
//            enterTolist = "";
//        } else {
//            regex_search(line, m, operators);
//            for (unsigned i = 0; i < m.size(); ++i) {
//                enterTolist += enterTolist + m.str(i);
//            }
//            vecAfterLex.push_back(enterTolist);
//            line = line.substr(enterTolist.size(), line.size());
//            enterTolist = "";
//        }
//
//    }
//    return vecAfterLex;
//}

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

/**
* get line as a parameter and return vector in each index store expression.
* @param line to parse.
* @return vector after paresed.
*/
vector<string> Interpreter::parser(string line) {
    int index = 0;
    vector<string> lexered_line = lexer(line);
    cout << line << endl;
    if (lexered_line.size() == 0) {
        throw runtime_error("error in lexering line");
    }
    // get first value and forword the iterator.
    //    vector<string>::iterator it = (lexered_line.begin());
    vector<string> parserd_line;
    // save expression in one place together.
    bool is_neg = true;
    for (int i = 0; index < lexered_line.size() && i < lexered_line.size(); index++, i++) {
        string expression = "";
        //string current = *it;
        string current = lexered_line[index];
        /**
         * need to check if it is a minus repressent neg and not minus operator:
         * 3 option that the minus is neg:
         * 1) '-' after operator =, meant it is neg.
         * 2) '-' after first argument in the line. first argument is always command, so again its neg.
         * 3) '-' in third argument or after. in this case there has to be ',' before the neg sign.
         */

        if (current == "-") {
            // if ((*prev(it, 1) == "=") || i == 1 || (i > 1 && (*prev(it, 1) == ","))) {
            if (lexered_line[index - 1] == "=" || i == 1 || (i > 1 && lexered_line[index - 1] == ",")) {
                // send the end of the iterator to know when to stop.
//                vector<string>::iterator it_end = lexered_line.end();
                // call the makeExpression with the vector the string from "-" include.
                expression += makeExpression(index, lexered_line);
                parserd_line.push_back(expression);
                continue;
            }
        }
        if (current[0] == '\"') {
//            vector<string>::iterator it_end = lexered_line.end();
            expression += makeExpression(index, lexered_line);
            parserd_line.push_back(expression);
        }
        if (current == "+" || current == "-" || current == "*" ||
            current == "/" || current == "(") {
            // send the end of the iterator to know when to stop.
//            vector<string>::iterator it_end = lexered_line.end();
            //send to function that make expression.
            if (current == "(") {
                // call the makeExpression with the vector the string from '(' include.
                expression += makeExpression(index, lexered_line);
            } else {
                // its an operator, sent the vector from before the operator.
                int prev_index = index - 1;
                expression += makeExpression(prev_index, lexered_line);
                // update the iterator to its place
                index = prev_index;
                // need to remove the previous argument added that need to be begin of expression.
                parserd_line.pop_back();
            }
            // add the exprresion to the parserd vector:
            parserd_line.push_back(expression);
        } else {
            // relate to "," ass a value only if it's not a separator before neg expression.
            if (current == "," && lexered_line[index + 1] == "-") continue;
            //incase no need to make expression, add the value of the vector as is.
            parserd_line.push_back(lexered_line[index]);
        }
    }

    return
            parserd_line;
}
}


