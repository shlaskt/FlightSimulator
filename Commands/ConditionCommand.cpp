//
// Created by tomer on 12/21/18.
//

#include "ConditionCommand.h"

vector<string> ConditionCommand::getConditionStatement(vector<string>::iterator &itor) {
    string expression_1 = *itor++; // first arg
    string condition = *itor++; // <, >, !, =
    if (*itor == "=") { // condition with 2 chars- like >=, <=, !=, ==...
        condition += *itor++;
    }
    string expression_2 = *itor; // second arg
    // inset to vector
    vector<string> condition_stat = {expression_1, condition, expression_2};
    return condition_stat;
}


bool ConditionCommand::checkCondition(string expression_1, string condition, string expression_2,
                                      Dijkstra shunting_yard) {
    double ex1, ex2;     // calculate and check valid expressions
    // can change inside the loop
    try {
        ex1 = shunting_yard(expression_1);
        ex2 = shunting_yard(expression_2);
    } catch (const out_of_range &no_such_var) {
        // if there is var without decleration in the expression- dijkstra throw error
        __throw_runtime_error("Error in IfCommand - invalid params");
    }
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

/**
 * set the list of the commands.
 * @param command_list to save.
 */
void ConditionCommand::setListOfCommands(list<Expression *> command_list) {
    this->list_of_commands = command_list;
}

