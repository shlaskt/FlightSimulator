
#include "WhileCommand.h"
#include <string>


/***
 * if statement
 * check the left and right expressions and the conditions between
 * action as excepted
 * @param vector1
 * @param map1
 * @param index
 * @return
 */
int WhileCommand::doCommand(vector<vector<string>> vector1, map<string, double> *map1, int index) {
    int i = 1;
    string expression_1 = "";
    string expression_2 = "";
    while ((vector1[index][i] != "<") && (vector1[index][i] != ">") &&
           (vector1[index][i] != "=") && (vector1[index][i] != "!")) {
        expression_1 = expression_1 + vector1[index][i] + " ";
        i++;
    }
    string sign = vector1[index][i];
    i++;
    if (vector1[index][i] == "=") { // for !=,==,<=,>=
        sign = sign + vector1[index][i];
        i++;
    }
    while (vector1[index][i] != "{") {
        expression_2 = expression_2 + vector1[index][i] + " ";
        i++;
    }
    vector<vector<string>> vector2 = vector1;
    vector2.erase(vector2.begin() + 0);
    //check the }
    for (int o = 0; o < vector2[vector2.size() - 1].size(); o++) {
        if (vector2[vector2.size() - 1][o] == "}") {
            vector2[vector2.size() - 1].erase(vector2[vector2.size() - 1].begin() + o);
            break;
        }
    }
    //if the last vector is empty erase the vector
    if (vector2[vector2.size() - 1].size() == 0) {
        vector2.erase(vector2.begin() + vector2.size());
    }

    // while true - do the commands
    while (checkCondition(expression_1, expression_2, sign, map1)) {
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
bool
WhileCommand::checkCondition(string expression_1, string expression_2, string condition, map<string, double> *map1) {
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