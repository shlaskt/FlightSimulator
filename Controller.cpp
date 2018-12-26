//
// Created by eyal on 12/21/18.
//

#include "Controller.h"


Controller::Controller(int argc, char **argv) {
    pthread_mutex_t *mut = new pthread_mutex_t();
    command_data_base = new CommandDataBase();
    var_data_base = new VarDataBase();
    data_reader_server = new DataReaderServer(var_data_base, mut);
    client = new Client();
    /**
     *
     * decide if to split responsabilities between DataReaderServer And VarData Base.
     * for now var data base not in heap.(not pointer).
     */
    if (argc > 1) {
        FileReader *reader = new FileReader(argv[1]);
        inputManager = new InputManager(reader);
        input_to_delete.push_back(reader);
    } else {
        StdinReader *reader = new StdinReader();
        inputManager = new InputManager(reader);
        input_to_delete.push_back(reader);
    }
}

/**
 * work on lines. make every line to command and return the command list.
 * use the member commandDataBase to get the commands from.
 * use the member DataReaderServer to read and write to server.
 * @param find_parenthesis check if need to find "{" before making commands.
 * @return commands list to execute. "syntax error, didn't find "{""
 */
vector<Expression *> Controller::conditionParser(bool find_parenthesis) {
    //list of commands to execute by reference(will saved after function done).
    vector<Expression *> commands_list;
    // read the next line.
    //string line = inputReader->readLine();
    vector<string> parsered_line = inputManager->readParseredLine();
//    lines_vector.push_back(parser(line));
    /**
     * i want the parsered vector and also the iterator still be alive after
     * function end, so i save them inside member.
     */
//    lines_iterators.push_back(lines_vector[lines_vector.size() - 1].begin());
    if (!find_parenthesis && parsered_line.back() != "{") {
        // check if didn't find "{" open to read command.
        throw runtime_error("syntax error, didn't find \"{\"");
    } else if (parsered_line[0] == "{" && parsered_line.size() == 1) {
        // skip on line "{".
        parsered_line = inputManager->readParseredLine();
    }
    // read and create commands until '}' or eof.
    while (!parsered_line.back().empty() && parsered_line.back() != "}") {
        //save the iterator reference to add to the commands.
        int current_index = inputManager->getStartVectorIndex();
        //parserd vector of string line input.
        Expression *ex = getCommandFromLine(parsered_line, current_index);
        commands_list.push_back(ex);
        parsered_line = inputManager->readParseredLine();
        //if only } end the loop.
        if (parsered_line.size() == 1 && parsered_line.back() == "}") {
            return commands_list;
        }
    }
    // if last command contain }.
    if (parsered_line.back() == "}") {
        parsered_line.pop_back();
        int current_index = inputManager->getStartVectorIndex();
        //parserd vector of string line input.
        Expression *ex = getCommandFromLine(parsered_line, current_index);
        commands_list.push_back(ex);
    }
    return commands_list;
}

void Controller::runProgram() {
    //reading line(stdin or file)
    vector<string> parsered_line = inputManager->readParseredLine();
    while (!parsered_line.back().empty()) {
        // save all the lines and the iterators on each line.
//        vector<string>::iterator it = inputManager->getParseredIterator();
        int index = inputManager->getStartVectorIndex();
        //parse vector in to expression.
        //send the last iterator made from the vector.
        Expression *expression = getCommandFromLine(parsered_line, index);
        pthread_mutex_lock(data_reader_server->getMutex());
        expression->calculate();
        pthread_mutex_unlock(data_reader_server->getMutex());
        parsered_line = inputManager->readParseredLine();
    }
}

/**
 * make and return command by
 * @param line of the file/stdin.
 * @param data_reader to connet with the commands.
 * @return command interpeted in specific line.
 */
Expression *Controller::getCommandFromLine(vector<string> &parsered_line, int &index) {
    Expression *expression_command;
    //    vector<string>::iterator it = parsered_line.begin();
    int current_index = 0;
    //split to cases, if its condition command create and return condition
    if (parsered_line[current_index] == "while" || parsered_line[current_index] == "if") {
        //check if saw "{" in the same line as the command if or while.
        bool saw_parenthesis = CheckValidityOfConditionCommand(parsered_line);
        // add all commands to command list in the scope between {};
        vector<Expression *> command_lists = conditionParser(saw_parenthesis);
        // create conditional command.
        expression_command =
                (command_data_base->getConditionCommand(parsered_line, index, data_reader_server, client, command_lists,
                                                        var_data_base));

    } else {
        // expression command create.
        expression_command = (command_data_base->getCommand(parsered_line, index, data_reader_server, client,
                                                            var_data_base));
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
    return (vec.back() == "{");
}

Controller::~Controller() {
    pthread_mutex_t *mut = data_reader_server->getMutex();
    pthread_mutex_lock(mut);
    delete (this->command_data_base);
    delete (this->var_data_base);
    delete (this->client);
    for (vector<Expression *>::iterator it = to_delete.begin(); it != to_delete.end(); ++it) {
        delete *it;
        *it = nullptr;
    }
    for (vector<InputReader *>::iterator it = input_to_delete.begin(); it != input_to_delete.end(); ++it) {
        delete *it;
        *it = nullptr;
    }
    delete (inputManager);
    pthread_mutex_unlock(mut);
    delete (this->data_reader_server);
    to_delete.clear();

    input_to_delete.clear();
}
