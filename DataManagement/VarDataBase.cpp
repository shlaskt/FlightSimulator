//
// Created by eyal on 12/18/18.
//

#include "VarDataBase.h"

void VarDataBase::initMaps() {
    this->paths_map.insert(pair<string, double>("/instrumentation/airspeed-indicator/indicated-speed-kt", 0));
    this->paths_map.insert(pair<string, double>("/instrumentation/altimeter/indicated-altitude-ft", 0));
    this->paths_map.insert(pair<string, double>("/instrumentation/altimeter/pressure-alt-ft", 0));
    this->paths_map.insert(pair<string, double>("/instrumentation/attitude-indicator/indicated-pitch-deg", 0));
    this->paths_map.insert(pair<string, double>("/instrumentation/attitude-indicator/indicated-roll-deg", 0));
    this->paths_map.insert(pair<string, double>("/instrumentation/attitude-indicator/internal-pitch-deg", 0));
    this->paths_map.insert(pair<string, double>("/instrumentation/attitude-indicator/internal-roll-deg", 0));
    this->paths_map.insert(pair<string, double>("/instrumentation/encoder/indicated-altitude-ft", 0));
    this->paths_map.insert(pair<string, double>("/instrumentation/encoder/pressure-alt-ft", 0));
    this->paths_map.insert(pair<string, double>("/instrumentation/gps/indicated-altitude-ft", 0));
    this->paths_map.insert(pair<string, double>("/instrumentation/gps/indicated-ground-speed-kt", 0));
    this->paths_map.insert(pair<string, double>("/instrumentation/gps/indicated-vertical-speed", 0));
    this->paths_map.insert(pair<string, double>("/instrumentation/heading-indicator/indicated-heading-deg", 0));
    this->paths_map.insert(pair<string, double>("/instrumentation/magnetic-compass/indicated-heading-deg", 0));
    this->paths_map.insert(pair<string, double>("/instrumentation/slip-skid-ball/indicated-slip-skid", 0));
    this->paths_map.insert(pair<string, double>("/instrumentation/turn-indicator/indicated-turn-rate", 0));
    this->paths_map.insert(pair<string, double>("/instrumentation/vertical-speed-indicator/indicated-speed-fpm", 0));
    this->paths_map.insert(pair<string, double>("/controls/flight/aileron", 0));
    this->paths_map.insert(pair<string, double>("/controls/flight/elevator", 0));
    this->paths_map.insert(pair<string, double>("/controls/flight/rudder", 0));
    this->paths_map.insert(pair<string, double>("/controls/flight/flaps", 0));
    this->paths_map.insert(pair<string, double>("/controls/engines/engine/throttle", 0));
    this->paths_map.insert(pair<string, double>("/engines/engine/rpm", 0));
}

/**
 * get var value by var name.
 * @param var name.
 * @return var value.
 */
double VarDataBase::getVarValue(string var) {
    return symbol_table.at(var);
}

/**
 * get var value by var name.
 * @param var name.
 * @return var value.
 */
ExpressionCommand *VarDataBase::getCommand(vector<string>::iterator &it, DataReaderServer &rd) {
    // first parameter, the command name.
    string command_name = (*it);
    if (commands_map.find(command_name) != commands_map.end()) {
        Command *c = commands_map[command_name];
        ExpressionCommand *ex_command = new ExpressionCommand(c, ++it, rd);
        to_delete.push_back(ex_command);
        return ex_command;
    }
    // if no matching key.
    throw runtime_error("there is no such var");
}

VarDataBase::VarDataBase() {

}

/**
 * this function update var value by its name, if it is bind, update also its path value.
 * @param var name.
 * @param val double value.
 */
void VarDataBase::assignVarValue(string var, double val) {
    // update var value in symbol table.
    symbol_table[var] = val;
    // if its bind var, find the path that need to be update and change its value.
    if (var_bind.find(var) != var_bind.end()) {
        paths_map[var_bind[var]] = val;
    }
}

/**
 * check if the path exsits and if it does return its value.
 * @param path string name.
 * @return its value.
 */
double VarDataBase::getPathValue(string path) {
    // if found the path key, return its value.
    if (paths_map.count(path) != 0) {
        return paths_map[path];
    }
    throw runtime_error("there is no such path directory");
}

/**
 * update path value to val by path name.
 * @param path name.
 * @param val value double.
 */
void VarDataBase::assignPathValue(string path, double val) {
    // if found the path key, return its value.
    if (paths_map.count(path) != 0) {
        paths_map[path] = val;
    }
    throw runtime_error("there is no such path directory");
}

/**
 * bind var to path, and update its value.
 * @param var to connect with path.
 * @param path the path to connect to.
 */
void VarDataBase::createAndBindVarToPath(string var, string path) {
    // if found the path key, bind var to it, and update var value.
    if (paths_map.count(path) != 0) {
        //add var to symbol table and update its value.
        symbol_table[var] = paths_map[path];
        //bind between var and path.
        var_bind[var] = path;
    }
    throw runtime_error("there is no such path directory");

}
