//
// Created by eyal on 12/21/18.
//

#include "ExpressionConditionalsCommand.h"


/**
 * do the command, Object Adapter.
 * @return 0 if succeeded
 */
double ExpressionConditionalsCommand::calculate() {
    command->setListOfCommands(command_lists);
    command->doCommand(vec,index, reader);
    return 0;
}

ExpressionConditionalsCommand::ExpressionConditionalsCommand(ConditionCommand *command, vector<string> vec, int index,
                                                             DataReaderServer *reader, list<Expression *> list_c) {

}
