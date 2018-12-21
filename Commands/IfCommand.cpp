//
// Created by tomer on 12/20/18.
//

#include "IfCommand.h"

void IfCommand::doCommand(vector<string>::iterator &itor, DataReaderServer *server) {
    Dijkstra shunting_yard(varDataBase.getSymbolTable());
    double expression_1, expression_2;
    string expression_1_st = *itor++; // first arg
    string condition = *itor++; // <, >, !, =
    if (*itor == "=") { // condition with 2 chars- like >=, <=, !=, ==...
        condition += *itor++;
    }
    string expression_2_st = *itor; // second arg
    // calculate and check valid expressions
    try {
        expression_1 = shunting_yard(expression_1_st);
        expression_2 = shunting_yard(expression_2_st);
    } catch (const out_of_range &no_such_var) {
        // if there is var without decleration in the expression- dijkstra throw error
        __throw_runtime_error("Error in IfCommand - invalid params");
    }
    // read commands
    if (checkCondition(expression_1, condition, expression_2)) {

    }
    ++itor; // increase iterator
}

bool IfCommand::checkCondition(double ex1, string condition, double ex2) {
    // cant do switch-case on string in c++ :(
    if (condition == "<") return (ex1 < ex2);
    if (condition == ">") return (ex1 > ex2);
    if (condition == "<=") return (ex1 <= ex2);
    if (condition == ">=") return (ex1 >= ex2);
    if (condition == "==") return (ex1 == ex2);
    if (condition == "!=") return (ex1 != ex2);
    // else ( !, = ,#, $...)
    __throw_runtime_error("Error in IfCommand - invalid condition");
}
