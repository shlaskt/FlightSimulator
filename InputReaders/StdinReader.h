//
// Created by eyal on 12/21/18.
//

#ifndef FLIGHTSIMULATOR_STDINREADER_H
#define FLIGHTSIMULATOR_STDINREADER_H


#include "InputReader.h"

class StdinReader : public InputReader {
public:
    StdinReader() {};

    virtual string readLine();
};


#endif //FLIGHTSIMULATOR_STDINREADER_H
