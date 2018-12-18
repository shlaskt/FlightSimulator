//
// Created by eyal on 12/18/18.
//

#include <iostream>
#include <sstream>
#include "InputManagement.h"

/**
 * sets the spaces to be ok.
 * @param line to convert.
 * @return the line after fine spaces.
 */
string addSpaces(string line) {
    string output;
    if (line == "") return line;
    for (char ch : line) {
        switch (ch) {
            case '+':
            case '-':
            case '*':
            case '/':
            case '=':
            case ',':
            case ')':
            case '(': {
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
            case ' ': {
                if (output.back() != ' ' && !output.empty()) output += ' ';
                break;
            }
            default: {
                output += ch;
            }
        }
    }
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

vector<string> lexer(string line) {
    vector<string> arr = splitLine(addSpaces(line), ' ');
    return arr;
}

void Lexertests() {
    bool sucseed = true;
    if (addSpaces("(h1+h2)/2") != "( h1 + h2 ) / 2") {
        cout << "\"(h1+h2)/2\" test failed" << endl;
        sucseed = false;
    }
    if (addSpaces("6*3") != "6 * 3") {
        cout << "\"6 * 3\" test failed" << endl;
        sucseed = false;
    }
    if (addSpaces("x=var/3") != "x = var / 3") {
        cout << "\"x=var/3\" test failed" << endl;
        sucseed = false;
    }
    if (addSpaces("    x=var1   +   var2") != "x = var1 + var2") {
        cout << "\"x = var1 + var2\" test failed" << endl;
        sucseed = false;
    }
    if (addSpaces("-5") != "- 5") {
        cout << "\"- 5 \" test failed" << endl;
        sucseed = false;
    }
    if (sucseed) {
        cout << "all lexer spaces tests passed";
    }
}