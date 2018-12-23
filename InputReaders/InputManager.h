//
// Created by eyal on 12/23/18.
//

#ifndef FLIGHTSIMULATOR_INPUTMANAGER_H
#define FLIGHTSIMULATOR_INPUTMANAGER_H


#include <vector>
#include "FileReader.h"
#include "../ExpressionInterfaces/Expression.h"
#include "../InputManagement.h"

class InputManager {
private:
    InputReader *inputReader;
    vector<string> lines;
    vector<vector<string>> parserd_commands;
    vector<int> command_start_indexes;
public:
    InputManager(InputReader *inputReader);

    vector<string> &readParseredLine();

    int getStartVectorIndex();

};


#endif //FLIGHTSIMULATOR_INPUTMANAGER_H
