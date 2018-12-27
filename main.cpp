
#include "Controller.h"

int main(int argc, char *argv[]) {
    Controller *controller = new Controller(argc,argv);
    controller->runningProgram(argc, argv);
    return 0;
}

