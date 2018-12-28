

#ifndef FLIGHT_OPENSERVERCOMMAND_H
#define FLIGHT_OPENSERVERCOMMAND_H

#include "Command.h"

class openServerCommand : public Command {
private:
    double port;
    double time;

public:

    virtual int doCommand(vector<vector<string>> vector1, map<string, double> *symbol_table, int index);

    void *OpenThread(void *pVoid);

    openServerCommand(DataReaderServer *serverData, Client *client1, Dijkstra *dij, pthread_mutex_t *mut)
            : Command(serverData, client1, dij, mut) {}

};

#endif //FLIGHT_OPENSERVERCOMMAND_H
