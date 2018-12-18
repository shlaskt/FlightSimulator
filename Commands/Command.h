//
// Created by tomer on 12/18/18.
//

#ifndef FLIGHTSIMULATOR_COMMAND_H
#define FLIGHTSIMULATOR_COMMAND_H

#include <vector>
#include <string>
using namespace std;

class Command {
public:
    virtual void doCommand()= 0;
};

#endif //FLIGHTSIMULATOR_COMMAND_H
