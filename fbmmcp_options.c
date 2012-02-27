#include "fbmmcp_options.h"

int parse_command_line(command_line_options* clo, int argc, char *argv[]) {
    int opt;

    while((opt = getopt(argc, argv, "n:")) != -1) {
        switch(opt)
        {
            case 'n':
                clo->number_of_simulations = atoi(optarg);
                break;
        }
    }
    
    //Check if the parameters are all valid.
    return 0;
}
