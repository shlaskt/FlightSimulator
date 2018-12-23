//
// Created by tomer on 12/21/18.
//

#include "WhileCommand.h"

/**
 * while command
 * check the condition every iteration and action
 * @param itor
 * @param server
 */
int WhileCommand::doCommand(vector<string> line, int i, DataReaderServer *server) {
    Dijkstra shunting_yard(varDataBase.getSymbolTable());
    vector<string> condition_statement = getConditionStatement(line, i);
    string expression_1 = condition_statement.at(0);
    string condition = condition_statement.at(1);
    string expression_2 = condition_statement.at(2);
    i = atoi(condition_statement.at(3).c_str()); // get the update index

    while (checkCondition(expression_1, condition, expression_2, shunting_yard)) {
        // do all the commands in the if untill the "}"
        for (list<Expression *>::iterator it = list_of_commands.begin(); it != list_of_commands.end(); ++it) {
            (*it)->calculate();
        }
    }
    return i; // return the index
}