#include "fbmmcp.h"

#define DEBUG_MSG(...) if(clo->debug) fprintf(stderr, __VA_ARGS__)

int main(int argc, char *argv[] )
{
    command_line_options *clo = malloc(sizeof(command_line_options));
    memset(clo,0,sizeof(command_line_options));
    
    if(!parse_command_line(clo, argc, argv)) {
        //Exit with failure after printing usage if the parameter parsing
        //has determined that things aren't right
        printf(USAGE);
        return 1; 
    }

    DEBUG_MSG("Executing with %'d simulations\n", clo->number_of_simulations);
    
    printf("0\n");
}
