//
// Created by eyal on 12/21/18.
//

#include "Controller.h"



Controller::Controller(int argc, char **argv) {
    command_data_base = new CommandDataBase();
    data_reader_server = new DataReaderServer(var_data_base);
    /**
     *
     * decide if to split responsabilities between DataReaderServer And VarData Base.
     * for now var data base not in heap.(not pointer).
     */
    if (argc > 1) {
        inputReader = new FileReader(argv[1]);
    }
    else{
        inputReader = new StdinReader();
    }
}
