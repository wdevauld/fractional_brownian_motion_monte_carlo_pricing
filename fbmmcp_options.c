#include "fbmmcp_options.h"


int parse_command_line(command_line_options* clo, int argc, char *argv[]) {
    int opt;
    int error_encountered = 0;
    while((opt = getopt(argc, argv, "H:n:d")) != -1) {
        switch(opt)
        {
            case 'n':
                clo->number_of_simulations = atoi(optarg);
                break;
            case 'd':
                clo->debug = 1;
                break;
            case 'H':
                clo->hurst_exponent = atof(optarg);
                break;
            default: 
                //Most likely the user entered an invalid option
                error_encountered = 1;
        }
    }
    //Check if the parameters are all valid.
        
    if(clo->number_of_simulations <= 0) {
        clo->number_of_simulations = DEFAULT_NUM_SIMULATIONS;
    }
    if(clo->hurst_exponent < 0.5 || clo->hurst_exponent >= 1) {
        clo->hurst_exponent = DEFAULT_HURST_EXPONENT;
    }
    return !error_encountered;
}
