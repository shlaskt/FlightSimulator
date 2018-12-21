//
// Created by eyal on 12/21/18.
//

#include "Controller.h"


Controller::Controller(int argc, char **argv) {
    command_data_base = new CommandDataBase();
    var_data_base = new VarDataBase();
    data_reader_server = new DataReaderServer(var_data_base);
    /**
     *
     * decide if to split responsabilities between DataReaderServer And VarData Base.
     * for now var data base not in heap.(not pointer).
     */
    if (argc > 1) {
        inputReader = new FileReader(argv[1]);
    } else {
        inputReader = new StdinReader();
    }
}

/**
 * work on lines. make every line to command and return the command list.
 * @param lines to convert to commands.
 * @param commandDataBase to get the commands from.
 * @param dr read and write to server.
 * @return commands list to execute.
 */
vector<Expression *> Controller::conditionPareser() {
    //list of commands to execute.
    vector<Expression *> commands_list;
    // read the next line.
    string line = inputReader->readLine();
    // read and create commands until '}' or eof.
    while (!line.empty() && line != "}") {
        //parserd vector of string line input.
        commands_list.push_back(getCommandFromLine(line));
    }
    return commands_list;
}

void Controller::runProgram() {
    //reading line(stdin or file)
    string line = inputReader->readLine();
    while (!line.empty()) {
        //parse vector in to expression.
        Expression *expression = getCommandFromLine(line);
        expression->calculate();
    }
}

/**
 * make and return command by
 * @param line of the file/stdin.
 * @param data_reader to connet with the commands.
 * @return command interpeted in specific line.
 */
ExpressionCommand *Controller::getCommandFromLine(string line) {
    vector<string> parsered_line = parser(line);
    vector<string>::iterator it = parsered_line.begin();
    //split to cases, if its condition command create and return condition
    if (*it == "while" || *it =="if"){
/**
 *
 * add to command data server conditional command data_base and make one and return.
 *
 *
 *
 *
 *
 *
 */

    }
    ExpressionCommand *expressionCommand = (command_data_base->getCommand(it, data_reader_server));
    to_delete.push_back(expressionCommand);
    return expressionCommand;
}

Controller::~Controller() {
    delete (this->command_data_base);
    delete (this->var_data_base);
    delete (this->data_reader_server);
    delete (inputReader);
    for (vector<Expression *>::iterator it = to_delete.begin(); it != to_delete.end(); ++it) {
        delete *it;
        *it = nullptr;
    }
    to_delete.clear();
}
