//
// Created by eyal on 12/21/18.
//

#ifndef FLIGHTSIMULATOR_FILEREADER_H
#define FLIGHTSIMULATOR_FILEREADER_H


#include "InputReader.h"
#include <fstream>

class FileReader : public InputReader {
private:
    ifstream input;
public:
    FileReader(string file_name);

    virtual string readLine();
};


#endif //FLIGHTSIMULATOR_FILEREADER_H
