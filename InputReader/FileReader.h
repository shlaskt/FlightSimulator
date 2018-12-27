//
// Created by eyal on 12/27/18.
//

#ifndef FLIGHT_FILEREADER_H
#define FLIGHT_FILEREADER_H


#include <fstream>
#include "InputReader.h"

class FileReader: public InputReader {
private:
    ifstream input;
public:
    FileReader(string file_name);
    virtual string readLine();
};


#endif //FLIGHT_FILEREADER_H
