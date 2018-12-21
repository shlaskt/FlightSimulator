//
// Created by eyal on 12/21/18.
//

#include "ExpressionConitionalCommand.h"

/**
 * get command object adapter, iterator to work with,reader to connet to server, list to execute.
 * @param command to do.
 * @param iterator to itrerate.
 * @param reader to connect with.
 * @param list_c to execute commands.
 */
ExpressionConitionalCommand::ExpressionConitionalCommand(Command *command,
                                                         vector<string>::iterator &iterator,
                                                         DataReaderServer &reader,
                                                         list<ExpressionCommand *> list_c) :
        command(command),
        iterator(iterator),
        reader(reader), command_lists(list_c) {};

/**
 * do the command, Object Adapter.
 * @return 0 if succeeded
 */
double ExpressionConitionalCommand::calculate() {
    command.addCommandList(command_lists);
    command->doCommand(iterator, reader);
    return 0;
}
