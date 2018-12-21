//
// Created by eyal on 12/21/18.
//

#ifndef FLIGHTSIMULATOR_INPUTREADER_H
#define FLIGHTSIMULATOR_INPUTREADER_H

#include <string>
#include <iostream>

using namespace std;

class InputReader {
public:
    InputReader() {};

    virtual string readLine() = 0;
};


#endif //FLIGHTSIMULATOR_INPUTREADER_H
