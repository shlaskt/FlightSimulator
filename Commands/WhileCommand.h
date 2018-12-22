//
// Created by tomer on 12/21/18.
//

#ifndef FLIGHTSIMULATOR_WHILECOMMAND_H
#define FLIGHTSIMULATOR_WHILECOMMAND_H


#include "ConditionCommand.h"

class WhileCommand : public ConditionCommand{
    VarDataBase varDataBase;
public:
    virtual void doCommand(vector<string>::iterator &itor, DataReaderServer* server);
};


#endif //FLIGHTSIMULATOR_WHILECOMMAND_H
