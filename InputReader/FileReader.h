//
// Created by Tomer & eyal on 12/27/18.
//

#ifndef FLIGHT_FILEREADER_H
#define FLIGHT_FILEREADER_H


#include <fstream>
#include "InputReadInterface.h"

class FileReader: public InputReadInterface {
private:
    ifstream input;
public:
    FileReader(string file_name);
    virtual string readLine();
};


#endif //FLIGHT_FILEREADER_H
