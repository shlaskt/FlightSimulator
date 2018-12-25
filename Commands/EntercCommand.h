//
// Created by eyal on 12/24/18.
//

#ifndef FLIGHTSIMULATOR_ENTERC_H
#define FLIGHTSIMULATOR_ENTERC_H


#include "Command.h"

class EntercCommand: public Command {
public:
    virtual int doCommand(vector<string> line, int i, DataReaderServer *server,
                          Client* client, VarDataBase* var_data_base);
};


#endif //FLIGHTSIMULATOR_ENTERC_H
