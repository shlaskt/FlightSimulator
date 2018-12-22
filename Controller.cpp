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
 * use the member commandDataBase to get the commands from.
 * use the member DataReaderServer to read and write to server.
 * @param find_parenthesis check if need to find "{" before making commands.
 * @return commands list to execute. "syntax error, didn't find "{""
 */
list<Expression *> Controller::conditionParser(bool find_parenthesis) {
    //list of commands to execute.
    list<Expression *> commands_list;
    // read the next line.
    string line = inputReader->readLine();
    lines_vector.push_back(parser(line));
    /**
     * i want the parsered vector and also the iterator still be alive after
     * function end, so i save them inside member.
     */
    lines_iterators.push_back(lines_vector[lines_vector.size() - 1].begin());
    if (!find_parenthesis && line != "{") {
        // check if didn't find "{" open to read command.
        throw runtime_error("syntax error, didn't find \"{\"");
    }
    // read and create commands until '}' or eof.
    while (!line.empty() && line != "}") {
        //parserd vector of string line input.
        Expression *ex = getCommandFromLine(lines_vector[lines_vector.size() - 1],
                                            lines_iterators[lines_iterators.size() - 1]);
        commands_list.push_back(ex);
        line = inputReader->readLine();
        if (line != "}") {
            lines_vector.push_back(parser(line));
            lines_iterators.push_back(lines_vector[lines_vector.size() - 1].begin());
        }
    }
    return commands_list;
}

void Controller::runProgram() {
    //reading line(stdin or file)
    string line = inputReader->readLine();
    int index = 0;
    while (!line.empty()) {
        // save all the lines and the iterators on each line.
        vector<string> parsered_line = parser(line);
        vector<string>::iterator it = parsered_line.begin();
        //parse vector in to expression.
        //send the last iterator made from the vector.
        Expression *expression = getCommandFromLine(parsered_line, it);
        expression->calculate();
        line = inputReader->readLine();
    }
}

/**
 * make and return command by
 * @param line of the file/stdin.
 * @param data_reader to connet with the commands.
 * @return command interpeted in specific line.
 */
Expression *Controller::getCommandFromLine(vector<string> &parsered_line, vector<string>::iterator &it_p) {
    Expression *expression_command;
    vector<string>::iterator it = parsered_line.begin();
    //split to cases, if its condition command create and return condition
    if ((*it) == "while" || (*it) == "if") {
        //check if saw "{" in the same line as the command if or while.
        bool saw_parenthesis = CheckValidityOfConditionCommand(parsered_line);
        // add all commands to command list in the scope between {};
        list<Expression *> command_lists = conditionParser(saw_parenthesis);
        // create conditional command.
        expression_command =
                (command_data_base->getConditionCommand(it_p, data_reader_server, command_lists));

    } else {
        // expression command create.
        expression_command = (command_data_base->getCommand(it_p, data_reader_server));
    }
    to_delete.push_back(expression_command);
    return expression_command;
}

/**
 * get iterator to a line of condition and check if it has "{".
 * throw exception if not.
 * @param it to iterate the line and find "{".
 */
bool Controller::CheckValidityOfConditionCommand(vector<string> &vec) {
    for (vector<string>::iterator it = vec.begin(); it != vec.end(); ++it) {
        if (*it == "{") {
            return true;
        }
    }
    return false;
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
