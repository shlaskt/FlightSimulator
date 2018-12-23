//
// Created by tomer on 12/21/18.
//

#include "ConditionCommand.h"

vector<string> ConditionCommand::getConditionStatement(vector<string> line, int i) {
    string expression_1 = line.at(i++); // first arg
    string condition = line.at(i++); // <, >, !, =
    if (line[i] == "=") { // condition with 2 chars- like >=, <=, !=, ==...
        condition += line[i++];
    }
    string expression_2 = line[i++]; // second arg
    // inset to vector
    vector<string> condition_stat = {expression_1, condition, expression_2, to_string(i)};
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

/**
 * set the list of the commands.
 * @param command_list to save.
 */
void ConditionCommand::setListOfCommands(list<Expression *> command_list) {
    this->list_of_commands = command_list;
}

