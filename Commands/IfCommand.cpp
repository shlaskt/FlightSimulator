//
// Created by tomer on 12/20/18.
//

#include "IfCommand.h"

/**
 * if command
 * check the condition and action
 * @param itor
 * @param server
 */
void IfCommand::doCommand(vector<string>::iterator &itor, DataReaderServer *server) {
    Dijkstra shunting_yard(varDataBase.getSymbolTable());
    vector<string> condition_statement = getConditionStatement(itor);
    string expression_1 = condition_statement.at(0);
    string condition = condition_statement.at(1);
    string expression_2 = condition_statement.at(2);

    if (checkCondition(expression_1, condition, expression_2, shunting_yard)) {
        // do all the commands in the if untill the "}"
        for (list<Expression *>::iterator it = list_of_commands.begin(); it != list_of_commands.end(); ++it) {
            (*it)->calculate();
        }
    }
    ++itor; // increase iterator
}


