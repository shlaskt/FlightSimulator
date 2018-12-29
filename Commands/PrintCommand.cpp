//
// Created by Tomer & Eyal on 20/12/18.
//

#include "PrintCommand.h"
#include "iostream"

/**
 * do command- print
 * print can get string, number (or expression) or var
 * if start with ' " ' -> string, print it as is
 * else -> expression, calculate and print
 * @param lines
 * @param symbolTable
 * @param line
 * @return
 */
int PrintCommand::doCommand(vector<vector<string>> lines, map<string, double> *symbolTable, int line) {
    int size = lines[line].size();
    int parentheses_index = 0;
    // if start with ' " ', it is string, get it and print it as is
    if ((parentheses_index = lines[line][1].find("\"")) != std::string::npos) {
        string print_me = lines[line][1];
        print_me.erase(print_me.begin() + parentheses_index);
        parentheses_index = print_me.find("\"");
        print_me.erase(print_me.begin() + parentheses_index, print_me.begin() + print_me.size());
        // print the string
        cout << print_me << endl;

    } else { // expression, get it, evaluate it and print it
        string toPrint = "";
        for (int i = 1; i < size; i++) {
            toPrint += lines[line][i] + " ";
        }
        try {
            // get the number / var value to print and print
            cout << this->shunting_yard->dijkstratoi(toPrint) << endl;
        } catch (const out_of_range &no_such_var) {
            // if there is no var in this name- dijkstra throw error
            __throw_runtime_error("Error in PrintCommend : invalid params to print");
        }
    }
    return 2; // curr index
}
