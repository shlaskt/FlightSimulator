//
// Created by Tomer & Eyal on 22/12/18.
//

#include "IfCommand.h"

/**
 * if statement
 * check the left and right expressions and the conditions between
 * action as excepted
 * @param lines
 * @param symbolTable
 * @param line
 * @return
 */
int IfCommand::doCommand(vector<vector<string>> lines, map<string, double> *symbolTable, int line) {
    int i = 1;
    string expression_1;
    string expression_2;
    while ((lines[line][i] != "<") && (lines[line][i] != ">") &&
           (lines[line][i] != "=") && (lines[line][i] != "!")) {
        expression_1 += lines[line][i] + " ";
        i++;
    }
    string condition = lines[line][i];
    i++;
    if (lines[line][i] == "=") { // for !=,==,<=,>=
        condition += lines[line][i];
        i++;

    }
    while (lines[line][i] != "{") {
        expression_2 += lines[line][i] + " ";
        i++;
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
    if (checkCondition(expression_1, expression_2, condition, symbolTable)) {
        this->interpreter->interpLine(vector2);
    }
    return 0;
}

/**
 * check the condition
 * @param expression_1
 * @param expression_2
 * @param condition
 * @param symbolTable
 * @return
 */
bool IfCommand::checkCondition(string expression_1, string expression_2, string condition,
        map<string, double> *symbolTable) {
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


