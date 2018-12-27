//
// Created by Eyal on 13/12/18.
//
#include "Interpreter.h"

#define FIRST 0
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

bool Interpreter::interpreteFile(vector<vector<string>> vector1) {
    bool flagExit = false;
    for (int i = 0; i < vector1.size(); i++) {
        //for the vars equal.
        int jump;
        //check if there is no var like this.
        if (symbolTable->count(vector1[i][0]) == 1) {
            if (vector1[i][1] != "=") {
                throw runtime_error("no such var");
            }
            this->commandMap->at("equal")->doCommand(vector1, this->symbolTable, i);
        } else if (vector1[i][0] == "while") {
            vector<vector<string>> newVec = vector1;


            newVec.erase(newVec.begin(), newVec.begin() + i);
            int ind = countLoopIf(newVec);
            newVec.erase(newVec.begin() + ind + 1, newVec.begin() + newVec.size());
            this->commandMap->at("while")->doCommand(newVec, this->symbolTable, FIRST);
            i = i + ind;
        } else if (vector1[i][FIRST] == "if") {
            vector<vector<string>> newVec = vector1;


            // TODO:
            //לבדוק אם חותך נכון
            newVec.erase(newVec.begin(), newVec.begin() + i);
            int ind = this->countLoopIf(newVec);
            newVec.erase(newVec.begin() + ind + 1, newVec.begin() + newVec.size());
            this->commandMap->at("if")->doCommand(newVec, this->symbolTable, FIRST);
            i = i + ind;
        } else if (vector1[i][FIRST] == "exit") {

            this->commandMap->at("exit")->doCommand(vector1, this->symbolTable, i);
            flagExit = true;


        } else {
            string dd = vector1[i][FIRST];
            //int count = commandMap->count(vector1[i][FIRST]);
            Command *co = this->commandMap->at(vector1[i][FIRST]);
            this->commandMap->at(vector1[i][FIRST])->doCommand(vector1, this->symbolTable, i);

        }
    }
    //if he didnt call to exit
    return flagExit;
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

/**
 * get iterator to start and to end, and make it one string of exprresion.
 * @param it start.
 * @param end iteartor end.
 * @return string exprresion.
 */
string makeExpression(int &index, vector<string> vec) {
    string expression;
    bool is_this_operator;
    bool is_next_operator;
    bool is_this_right_parenthesis = false;
    bool is_quote;
    string current = vec[index];
    // case is a quote add all the quote to one expression.
    if (current[FIRST] == '\"') {
        expression += vec[index];
        if (current.back() == '\"') return expression;
        do {
            ++index;
            // if only one expression end function.
            //forword iterator.
            current = vec[index];
            expression = expression + " " + current;
        } while (current.back() != '\"');
        return expression;
    }
    do {
        // adding value to expression.
        expression += current;
        if (current == "+" || current == "-" || current == "*" || current == "/"
            || current == "(" || current == ")") {
            is_this_operator = true;
            if (current == ")") is_this_right_parenthesis = true;
        } else { is_this_operator = false; }
        //forword the iterator.
        if (index == vec.size() - 1) {
            ++index;
            break;
        }
        ++index;
        //update current.
        current = vec[index];
        // check if operator.
        if (current == "+" || current == "-" || current == "*" || current == "/"
            || current == "(" || current == ")") {
            is_next_operator = true;
        } else {
            // if there is right paranthesis and after it a number.
            if (is_this_right_parenthesis && index != vec.size()) {
                break;
            }
            is_next_operator = false;
        }
        is_this_right_parenthesis = false;
    } while ((is_this_operator || is_next_operator) && index != vec.size() && current != ",");
    // if reached to the end, return it -- * twice because end loop do ++ becuase need to read the current value.
    --index;
    //added spaces to make it valid.
    return addSpaces(expression);
}


/**
 * get line as a parameter and return vector in each index store expression.
 * @param line to parse.
 * @return vector after paresed.
 */
vector<string> Interpreter::parser(string line) {
    int index = 0;
    vector<string> lexered_line = lexer(line);
//    cout << line << endl;
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
        if (current[FIRST] == '\"') {
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

vector<vector<string>> Interpreter::readFromFile(InputReader *inputReader) {
    string command;
    string line;
    string buffer;
    vector<vector<string>> vector1;
    line = inputReader->readLine();
    while (line != "") {
        vector<string> afterSplit = lexer(line);
        if (afterSplit.size() > 0) {
            vector1.push_back(lexer(line));
        }
        line = inputReader->readLine();
    }
    return vector1;
}


