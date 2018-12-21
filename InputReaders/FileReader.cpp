//
// Created by eyal on 12/21/18.
//

#include "FileReader.h"

/**
 * save a file reader stream.
 * @param file_name of the file.
 */
FileReader::FileReader(string file_name) {
    input = ifstream(file_name);
}
/**
 * read lines from the file and return nullptr equal false if end of file or other problem.
 * @return string line or false.
 */
string FileReader::readLine() {
    string line;
    getline(input, line);
    if (!input) {
        return nullptr;
    }
    return line;
}
