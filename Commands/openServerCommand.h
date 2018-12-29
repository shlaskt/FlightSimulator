

#ifndef FLIGHT_OPENSERVERCOMMAND_H
#define FLIGHT_OPENSERVERCOMMAND_H

#include "Command.h"

class openServerCommand: public Command{
private:
    double port;
    double time;
    struct data_to_socket *initParams();
    void getPortAndTime(vector<vector<string>> lines, int line);
public:
   virtual int doCommand(vector<vector<string>> lines,map<string, double>* symbolTable,int line);
    void* createThread(void *pVoid);
    openServerCommand(DataReaderServer* server5,Client* client1,Dijkstra* dij,pthread_mutex_t *mut)
            :Command(server5,client1,dij,mut){}

};
#endif //FLIGHT_OPENSERVERCOMMAND_H
