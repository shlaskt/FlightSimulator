//
// Created by eyal on 12/27/18.
//

#ifndef FLIGHT_STDINREADER_H
#define FLIGHT_STDINREADER_H


//
// Created by eyal on 12/21/18.
//

#include "InputReader.h"

#include <iostream>

class StdinReader : public InputReader {
public:
    StdinReader() {};

    virtual string readLine();
};

#endif //FLIGHT_STDINREADER_H
