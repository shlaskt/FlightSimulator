//
// Created by Tomer & Eyal on 20/12/18.
//

#include "IfCommand.h"

/**
 * if statement
 * check the left and right expressions and the conditions between
 * action as excepted
 * @param lines
 * @param symbol_table
 * @param index
 * @return
 */
int IfCommand::doCommand(vector<vector<string>> lines, map<string, double> *symbol_table, int index) {
    int i = 1;
    string expression_1;
    string expression_2;
    while ((lines[index][i] != "<") && (lines[index][i] != ">") &&
           (lines[index][i] != "=") && (lines[index][i] != "!")) {
        expression_1 += lines[index][i] + " ";
        ++i;
    }
    string condition = lines[index][i];
    ++i;
    if (lines[index][i] == "=") { // for !=,==,<=,>=
        condition += lines[index][i];
        ++i;

    }
    while (lines[index][i] != "{") {
        expression_2 += lines[index][i] + " ";
        ++i;
    }
    vector<vector<string>> vector2 = lines;
    vector2.erase(vector2.begin() + 0);
    for (int i1 = 0; i1 < vector2[vector2.size() - 1].size(); i1++) {
        if (vector2[vector2.size() - 1][i1] == "}") {
            vector2[vector2.size() - 1].erase(vector2[vector2.size() - 1].begin() + i1);
            break;
        }
    }
    if (vector2[vector2.size() - 1].size() == 0) {
        vector2.erase(vector2.begin() + vector2.size());
    }

    // if true - do the commands
    if (checkCondition(expression_1, expression_2, condition, symbol_table)) {
        this->interpreter->interpLine(vector2);
    }
    return 0;
}

/**
 * check the condition
 * @param expression_1
 * @param expression_2
 * @param condition
 * @param symbol_table
 * @return
 */
bool IfCommand::checkCondition(string expression_1, string expression_2,
        string condition, map<string, double> *symbol_table) {
    double ex1, ex2;     // calculate and check valid expressions
    // can change inside the loop
    try {
        ex1 = this->shunting_yard->dijkstratoi(expression_1);
        ex2 = this->shunting_yard->dijkstratoi(expression_2);
    } catch (const out_of_range &no_such_var) {
        // if there is var without decleration in the expression- dijkstra throw error
        __throw_runtime_error("Error in condition command - invalid params");
    }
    // cant do switch-case on string in c++ :(
    if (condition == "<") return (ex1 < ex2);
    if (condition == ">") return (ex1 > ex2);
    if (condition == "<=") return (ex1 <= ex2);
    if (condition == ">=") return (ex1 >= ex2);
    if (condition == "==") return (ex1 == ex2);
    if (condition == "!=") return (ex1 != ex2);
    // else ( !, = ,#, $...)
    __throw_runtime_error("Error in condition Command - invalid condition");
}


