//
// Created by eyal on 12/19/18.
//

#include "CommandDataBase.h"
#include "../Commands/ConnectCommand.h"
#include "../Commands/OpenDataServer.h"
#include "../Commands/EqualCommand.h"
#include "../Commands/IfCommand.h"
#include "../Commands/WhileCommand.h"
#include "../Commands/PrintCommand.h"
#include "../Commands/SleepCommand.h"
#include "../Commands/VarCommand.h"


CommandDataBase::CommandDataBase() {
    /**
     * Regular commands
     */
    commands_map["connect"] = new ConnectCommand();
    commands_map["equal"] = new EqualCommand();
    commands_map["openDataServer"] = new OpenDataServer();
    commands_map["print"] = new PrintCommand();
    commands_map["sleep"] = new SleepCommand();
    commands_map["var"] = new VarCommand();

    /**
    * Conditional commands
    */
    condition_commands_map["if"] = new IfCommand();
    condition_commands_map["while"] = new WhileCommand();
}

/**
 * the function get iterator as an input and make a command by the name of iterator by command map.
 * the first iterator value is the name of the command.
 * @param it to run over the line(interpreter).
 * @param rd data server to connect with the command.
 * @return expression command.
 */
ExpressionCommand *CommandDataBase::getCommand(vector<string> vec, int index, DataReaderServer *rd,
                                               VarDataBase *varDataBase) {
    // first parameter, the command name.
    string command_name = vec[index];
    if (commands_map.find(command_name) != commands_map.end()) {
        Command *c = commands_map[command_name];
        ++index;
        ExpressionCommand *ex_command = new ExpressionCommand(c, vec, index, rd, varDataBase);
        to_delete.push_back(ex_command);
        return ex_command;
    }
    // if no matching key.
    throw runtime_error("there is no such command");
}


ExpressionConditionalsCommand *
CommandDataBase::getConditionCommand(vector<string> vec, int index,
                                     DataReaderServer *reader, list<Expression *> command_list,
                                     VarDataBase *varDataBase) {
    // first parameter, the command name.
    string command_name = vec[index];
    if (condition_commands_map.find(command_name) != condition_commands_map.end()) {
        ConditionCommand *c = condition_commands_map[command_name];
        ExpressionConditionalsCommand *ex_command = new ExpressionConditionalsCommand(c, vec,
                                                                                      ++index, reader, command_list,
                                                                                      varDataBase);
        to_delete.push_back(ex_command);
        return ex_command;
    }
    // if no matching key.
    throw runtime_error("there is no such command");
}


/**
 * delete all the ExpressionCommand and .
 */
CommandDataBase::~CommandDataBase() {
    //delete all the ExpressionCommand and Command.
    for (vector<Expression *>::iterator it = to_delete.begin(); it != to_delete.end(); ++it) {
        delete (*it);
    }
    for (map<string, Command *>::iterator it_command = commands_map.begin();
         it_command != commands_map.end(); ++it_command) {
        delete ((*it_command).second);
    }
    for (map<string, ConditionCommand *>::iterator it_command = condition_commands_map.begin();
         it_command != condition_commands_map.end(); ++it_command) {
        delete ((*it_command).second);
    }
}
