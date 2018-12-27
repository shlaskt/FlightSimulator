

//
// Created by eyal on 12/21/18.
//


#include "StdinReader.h"
/**
 * read line, if eof or other problem will return nullptr equal to false.
 * @return line from stdin.
 */
string StdinReader::readLine() {
    string line;
    getline(cin, line);
    if (!cin) {
        return "";
    }
    return line;
}