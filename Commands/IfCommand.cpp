//
// Created by Tomer & Eyal on 20/12/18.
//

#include "IfCommand.h"

/**
 * if statement
 * check the left and right expressions and the conditions between
 * action as excepted
 * @param vector1
 * @param map1
 * @param index
 * @return
 */
int IfCommand::doCommand(vector<vector<string>> vector1, map<string, double> *map1, int index) {
    int i = 1;
    string expression_1;
    string expression_2;
    while ((vector1[index][i] != "<") && (vector1[index][i] != ">") &&
           (vector1[index][i] != "=") && (vector1[index][i] != "!")) {
        expression_1 += vector1[index][i] + " ";
        i++;
    }
    string condition = vector1[index][i];
    i++;
    if (vector1[index][i] == "=") { // for !=,==,<=,>=
        condition += vector1[index][i];
        i++;

    }
    while (vector1[index][i] != "{") {
        expression_2 += vector1[index][i] + " ";
        i++;
    }
    vector<vector<string>> vector2 = vector1;
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
    if (checkCondition(expression_1, expression_2, condition, map1)) {
        this->interpreter->interpLine(vector2);
    }
    return 0;
}

/**
 * check the condition
 * @param expression_1
 * @param expression_2
 * @param condition
 * @param map1
 * @return
 */
bool IfCommand::checkCondition(string expression_1, string expression_2, string condition, map<string, double> *map1) {
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


