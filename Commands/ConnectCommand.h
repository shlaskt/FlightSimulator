//
// Created by tomer on 12/19/18.
//

#ifndef FLIGHTSIMULATOR_CONNECTCOMMAND_H
#define FLIGHTSIMULATOR_CONNECTCOMMAND_H


#include "Command.h"

class ConnectCommand : public Command {
private:
    void CreateThread(struct params_to_socket *params);

public:
    ConnectCommand();

    virtual void doCommand(vector<string>::iterator &itor, DataReaderServer *server);
};


#endif //FLIGHTSIMULATOR_CONNECTCOMMAND_H
