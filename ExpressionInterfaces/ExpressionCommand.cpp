//
// Created by eyal on 12/18/18.
//

#include "ExpressionCommand.h"

/**
 * do the command, Object Adapter.
 * @return 0 if succeeded
 */
double ExpressionCommand::calculate() {
    command->doCommand(iterator, reader);
    return 0;
}

/**
 * get command object adapter, iterator to work with, and reader to connet to server.
 * @param command to do.
 * @param iterator to itrerate.
 * @param reader to connect with.
 */
ExpressionCommand::ExpressionCommand(Command *command, vector<string>::iterator &iterator,
                                     DataReaderServer &reader) : command(command), iterator(iterator),
                                                                 reader(reader) {}
