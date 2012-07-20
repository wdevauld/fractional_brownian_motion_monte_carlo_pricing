#include "fbmmcp.h"

int main(int argc, char *argv[] )
{
    command_line_options *clo = calloc(1, sizeof(command_line_options));
    time_t timer;
    timer = time(NULL);
    char *localtime_buffer = (char *)asctime(localtime(&timer));

    /*
    time_t timer;
    timer = time(NULL);
    char *localtime_buffer = (char *)asctime(localtime(&timer));
    */

    if(!parse_command_line(clo, argc, argv)) {
        //Exit with failure after printing usage if the parameter parsing
        //has determined that things aren't right
        printf(USAGE);
        return 1; 
    }
    //TODO allow the user to specify the seeds
    phrtsd(localtime_buffer, &(clo->seed1), &(clo->seed2));
    
    DEBUG_MSG("Seeds are set to: 1=>%ld 2=>%ld\n",clo->seed1, clo->seed2);
  
    //Change program course depending on what the user is looking for 
    switch (clo->output_option) {
        case HOSKING_BROWNIAN_MOTION_PATHS:
            DEBUG_MSG("Output will be fractional Brownian Motion Paths\n");
            //Allocate the memory for output
            fractional_brownian_motion(clo);
            break;
    }
}
