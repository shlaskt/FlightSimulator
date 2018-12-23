//
// Created by tomer on 12/19/18.
//

#include "ConnectCommand.h"


int ConnectCommand::doCommand(vector<string> line, int i, DataReaderServer *server) {
    Dijkstra shunting_yard(varDataBase.getSymbolTable());
    string ip = line.at(i++); // get ip
    string port_s = line.at(i++);
    // check valid and return port (to involve double calculate)
    int port= checkValid(ip, port_s, shunting_yard);


}

int ConnectCommand::checkValid(string ip, string port_s, Dijkstra shunting_yard) {
    // check ip
    int point_counter = 0;
    for (int i = 0; i < ip.size(); ++i) {
        if (ip[i] == '.')
            ++point_counter;
        if (ip[i] == '-')
            __throw_runtime_error("Error in connectCommand - cant get ip with neg numbers");
    }
    if (point_counter != 3)
        __throw_runtime_error("Error in connectCommand - ip must be -> x.y.z.w");

    // check port
    double port;
    try {
        port = shunting_yard(port_s); // get the number / var value to assign the exists var
    } catch (const out_of_range &no_such_var) {
        // if there is no var in this name- dijkstra throw error
        __throw_runtime_error("Error in connectCommand - invalid params to port");
    }
    if (port < 0)
        __throw_runtime_error("Error in connectCommand - negative params to port");

    return (int)port; // castint to int
}
