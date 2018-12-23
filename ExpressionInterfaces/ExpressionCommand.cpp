//
// Created by eyal on 12/18/18.
//

#include "ExpressionCommand.h"

/**
 * do the command, Object Adapter.
 * @return 0 if succeeded
 */
double ExpressionCommand::calculate() {
    command->doCommand(line, index, reader, varDataBase);
    return 0;
}
/**
 * get command object adapter, iterator to work with, and reader to connet to server.
 * @param command to do.
 * @param iterator to itrerate.
 * @param reader to connect with.
 */
ExpressionCommand::ExpressionCommand(Command *command, const vector<string> &line, int index, DataReaderServer *reader,
                                     Client *client, VarDataBase *varDataBase) : command(command), line(line),
                                                                                 index(index), reader(reader),
                                                                                 client(client),
                                                                                 varDataBase(varDataBase) {}