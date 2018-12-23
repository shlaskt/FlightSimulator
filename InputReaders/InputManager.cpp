//
// Created by eyal on 12/23/18.
//

#include "InputManager.h"

InputManager::InputManager(InputReader *inputReader) : inputReader(inputReader) {
    lists_index = 0;
}

vector<string> &InputManager::readParseredLine() {
    string line = inputReader->readLine();
    vector<string> vec;
    if (line == "") {
        vec.push_back("");
        parserd_commands.push_back(vec);
        return parserd_commands[parserd_commands.size() - 1];
    } else {
        vec = parser(line);
        parserd_commands.push_back(vec);
        return parserd_commands[parserd_commands.size() - 1];
    }
}

//list<Expression *> &InputManager::createCommandList() {
//    list<Expression *> list;
//    commands_lists.push_back(list);
//    return commands_lists[commands_lists.size() - 1];
//}

int InputManager::getStartVectorIndex() {
    command_start_indexes.push_back(0);
    return command_start_indexes.back();
}