#include "fbmmcp_options.h"

int parse_command_line(command_line_options* clo, int argc, char *argv[]) {
    int opt;

    while((opt = getopt(argc, argv, "n:d")) != -1) {
        switch(opt)
        {
            case 'n':
                clo->number_of_simulations = atoi(optarg);
                break;
            case 'd':
                clo->debug = 1;
        }
    }
    //Check if the parameters are all valid.
        
    if(clo->number_of_simulations <= 0) {
        clo->number_of_simulations = DEFAULT_NUM_SIMULATIONS;
    }
    return 1;
}
