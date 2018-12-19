//
// Created by eyal on 12/19/18.
//

#include "CommandDataBase.h"

/**
 * get var value by var name.
 * @param var name.
 * @return var value.
 */
ExpressionCommand *CommandDataBase::getCommand(vector<string>::iterator &it, DataReaderServer &rd) {
    // first parameter, the command name.
    string command_name = (*it);
    if (commands_map.find(command_name) != commands_map.end()) {
        Command *c = commands_map[command_name];
        ExpressionCommand *ex_command = new ExpressionCommand(c, ++it, rd);
        to_delete.push_back(ex_command);
        return ex_command;
    }
    // if no matching key.
    throw runtime_error("there is no such var");
}
/**
 * delete all the ExpressionCommand and .
 */
CommandDataBase::~CommandDataBase() {
    //delete all the ExpressionCommand and Command.
    for (vector<ExpressionCommand *>::iterator it = to_delete.begin(); it != to_delete.end(); ++it) {
        delete (*it);
    }
    for (map<string,Command *>::iterator it_command = commands_map.begin();
    it_command != commands_map.end(); ++it_command) {
        delete ((*it_command).second);
    }
}
