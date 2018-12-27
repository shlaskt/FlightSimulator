//
// Created by eyal on 12/27/18.
//

#include "Controller.h"

Controller::Controller() {
    mut = new pthread_mutex_t();
    pthread_mutex_init(mut, nullptr);
    maps = new Maps(mut);
    server = new DataReaderServer(maps->getSymbolMap(), mut);
    client = new Client();
    dijkstra = new Dijkstra(maps->getSymbolMap());
    interpreter = new Interpreter(maps->getSymbolMap(), maps->getComMap());
}

/**
 * work on lines. make every line to command and return the command list.
 * use the member commandDataBase to get the commands from.
 * use the member DataReaderServer to read and write to server.
 * @param find_parenthesis check if need to find "{" before making commands.
 * @return commands list to execute. "syntax error, didn't find "{""
 */
vector<Command *> Controller::conditionParser(bool find_parenthesis) {
    //list of commands to execute by reference(will saved after function done).
    vector<Command *> commands_list;
    // read the next line and lexer it.
    string line = reader->readLine();
    vector<string> parsered_line = interpreter->lexer(line);

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

void Controller::runningProgram(int argc, char *argv[]) {
    maps->setDij(dijkstra);
    maps->setServer(server, client);
    maps->setInterpreter(interpreter);
    maps->initMapCom();
    vector<string> parered_line;
    vector<vector<string>> afterLex;
    string line;
    //read from the file
    //string fileName="tempppppp";
    string fileName = argv[1];
    int end;
    switch (argc) {
        case 0:
            throw runtime_error("erorr in main arguments");
        case 1:
            reader = new StdinReader();
            break;
        default:
            reader = new FileReader(fileName);
    }
    //pthread_mutex_destroy(&mut);
    line = reader->readLine();
    do {
        parered_line = interpreter->parser(line);
//        afterLex = interpreter->readFromFile(fileName);
        end = interpreter->interpLine(afterLex);
        line = reader->readLine();
    } while (line != "");

    if (end == 0) {
        server->stopLoop();
        pthread_mutex_destroy(mut);
        delete mut;
        delete dijkstra;
        delete interpreter;
        delete client;
        delete server;
    }
    /*
    //delete
    pthread_mutex_destroy(mut);
    delete mut;
    delete dijkstra;
    delete interpreter;
    delete client1;
    delete drs;*/
    delete reader;
    delete interpreter;
    delete maps;
}