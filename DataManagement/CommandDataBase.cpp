//
// Created by eyal on 12/19/18.
//

#include "CommandDataBase.h"


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
    commands_map["Enterc"] = new EntercCommand();

    /**
    * Conditional commands
    */
    condition_commands_map["if"] = new IfCommand();
    condition_commands_map["while"] = new WhileCommand();
}

/**
 * the function get vector and index as an input and make a command by the name of iterator by command map.
 * the first vector value is the name of the command.
 * @param index to run over the line(interpreter).
 * @param rd data server to connect with the command.
 * @param vec vecotr parsered.
 * @return expression command.
 */
ExpressionCommand *CommandDataBase::getCommand(vector<string> vec, int index, DataReaderServer *rd,
                                               Client *client, VarDataBase *varDataBase) {
    // first parameter, the command name.
    string command_name = vec[index];
    if (commands_map.find(command_name) != commands_map.end()) {
        Command *c = commands_map[command_name];
        ++index;
        ExpressionCommand *ex_command = new ExpressionCommand(c, vec, index, rd,client, varDataBase);
        to_delete.push_back(ex_command);
        return ex_command;
    } else {
        for (++index; index < vec.size(); ++index) {
            int current_index = 0;
            /**
             * check if we se assaing of equasion:
             * check its not one of the cases like this:
             * " >= "," <= "," != "," == ".
             */
            if (vec[index] == "=" && vec[index - 1] != "<" && vec[index - 1] != ">" && vec[index - 1] != "!"
                && vec[index + 1] != "=") {
                Command *c = commands_map["equal"];
                ExpressionCommand *ex_command = new ExpressionCommand(c, vec, current_index, rd,client, varDataBase);
                to_delete.push_back(ex_command);
                return ex_command;
            }
        }
    }
    // if no matching key.
    throw runtime_error("there is no such command");
}


ExpressionConditionalsCommand *
CommandDataBase::getConditionCommand(vector<string> vec, int index,
                                     DataReaderServer *reader,Client *client, vector<Expression *> command_list,
                                     VarDataBase *varDataBase) {
    // first parameter, the command name.
    string command_name = vec[index];
    if (condition_commands_map.find(command_name) != condition_commands_map.end()) {
        ConditionCommand *c = condition_commands_map[command_name];
        ExpressionConditionalsCommand *ex_command = new ExpressionConditionalsCommand(c, vec,
                                                                                      ++index, reader,
                                                                                      client,
                                                                                      command_list,
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
