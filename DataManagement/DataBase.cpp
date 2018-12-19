//
// Created by eyal on 12/18/18.
//

#include "DataBase.h"

void DataBase::initMaps() {
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
double DataBase::getVarValue(string var) {
    return symbol_table.at(var);
}

/**
 * get var value by var name.
 * @param var name.
 * @return var value.
 */
ExpressionCommand *DataBase::getCommand(const vector<string>::iterator &it, DataReaderServer rd) {
    // first parameter, the command name.
    string command_name = (*it);
    if (commands_map.find(command_name) != commands_map.end()) {
        Command *c = commands_map[command_name];
        ExpressionCommand *ex_c = new ExpressionCommand(c, it + 1);
    }
}

DataBase::DataBase() {

}
