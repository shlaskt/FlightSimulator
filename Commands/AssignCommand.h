

#ifndef FLIGHT_EQUALCOMMAND_H
#define FLIGHT_EQUALCOMMAND_H

#include "Command.h"
#include <pthread.h>

#define SET "set "
#define SPACE ' '
#define RN "\r\n"

class AssignCommand : public Command {

public:
    virtual int doCommand(vector<vector<string>> vector1, map<string, double> *symbol_table, int index);

    AssignCommand(DataReaderServer *data_server, Client *client_data, Dijkstra *dij, pthread_mutex_t *mut)
            : Command(data_server, client_data, dij, mut) {}
};


#endif //FLIGHT_EQUALCOMMAND_H
