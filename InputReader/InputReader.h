//
// Created by eyal on 12/27/18.
//

#ifndef FLIGHT_INPUTREADINTERFACE_H
#define FLIGHT_INPUTREADINTERFACE_H

#include <string>
#include <vector>

using namespace std;

class InputReader {
public:
    virtual string readLine() = 0;
};


#endif //FLIGHT_INPUTREADINTERFACE_H
