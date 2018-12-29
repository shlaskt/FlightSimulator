//
// Created by Tomer & Eyal on 18/12/18.
//

#include <string.h>
#include "ConnectCommand.h"

/**
 * connect command, get ip and port and connect
 * @param lines
 * @param symbolTable
 * @param line
 * @return
 */
int ConnectCommand::doCommand(vector<vector<string>> lines, map<string, double> *symbolTable, int line) {
    string port_s;
    int size = lines[line].size();
    // get ip
    string ip = lines[line][1];
    // get d_port as string
    for (int i = 2; i < size; i++) {
        port_s = port_s + lines[line][i] + " ";
    }
    // check valid of d_port and ip
    double port = checkValid(ip, port_s);
    // open socket
    client->openSocket(ip, port);
    return 3; // line
}

/**
 * check if the ip and port valids
 * @param ip
 * @param port_s
 * @return
 */
double ConnectCommand::checkValid(string ip, string port_s) {
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

    // check d_port
    double port;
    try {
        port = shunting_yard->dijkstratoi(port_s); // get the number / var value to assign the exists var
    } catch (const out_of_range &no_such_var) {
        // if there is no var in this name- dijkstra throw error
        __throw_runtime_error("Error in connectCommand - invalid params to d_port");
    }
    if (port < 0)
        __throw_runtime_error("Error in connectCommand - negative params to d_port");

    return port;
}