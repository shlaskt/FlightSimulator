//
// Created by tomer on 12/18/18.
//

#ifndef FLIGHTSIMULATOR_COMMAND_H
#define FLIGHTSIMULATOR_COMMAND_H

#include <vector>
#include <string>
#include "../Sockets/DataReaderServer.h"
#include "../Sockets/Client.h"

using namespace std;

class Command {
//    DataReaderServer* server;
//protected:
//    vector<string>::iterator itor;
public:
    // Ctor for server and iterator - same for all commands
//    Command(DataReaderServer *server,
//            const vector<std::__cxx11::basic_string<char, std::char_traits<char>,
//                    std::allocator<char>>, std::allocator<std::__cxx11::basic_string<char,
//                    std::char_traits<char>, std::allocator<char>>>>::iterator &itor)
//            : server(server), itor(itor) {}
     /**
      * doCommand
      */
    virtual int doCommand(vector<string> line, int i, DataReaderServer *server,
            Client *client, VarDataBase* var_data_base)= 0;
/**
 * get server
 * @return
 */
//    DataReaderServer* getServer() {return server;}

//    /**
//     * get iterator
//     * @return
//     */
//    const vector<std::__cxx11::basic_string<char, std::char_traits<char>,
//            std::allocator<char>>, std::allocator<std::__cxx11::basic_string<char,
//            std::char_traits<char>, std::allocator<char>>>>::iterator &
//    getItor() const {
//        return itor;
//    }
///**
// * set iterator
// * @param itor
// */
//    void setItor(const vector<std::__cxx11::basic_string<char, std::char_traits<char>,
//            std::allocator<char>>, std::allocator<std::__cxx11::basic_string<char,
//            std::char_traits<char>, std::allocator<char>>>>::iterator &itor) {
//        Command::itor = itor;
//    }
};

#endif //FLIGHTSIMULATOR_COMMAND_H
