#include "fbmmcp.h"

int main(int argc, char *argv[] )
{
    command_line_options *clo = calloc(1, sizeof(command_line_options));
    time_t timer;
    int n;
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

    DEBUG_MSG("User desired: %ld steps\n", clo->number_of_steps);
    clo->n = floor(log2(clo->number_of_steps));
    clo->number_of_steps = pow(2,clo->n);
    DEBUG_MSG("Executing with 2^%ld (%ld) steps\n", clo->n,  clo->number_of_steps);
  
    //Change program course depending on what the user is looking for 
    switch (clo->output_option) {
        case HOSKING_BROWNIAN_MOTION_PATHS:
            DEBUG_MSG("Output will be fractional Brownian motion paths\n");
            fractional_brownian_motion(clo);
            break;
            
        case HOSKING_BROWNIAN_MOTION_NOISE:
            DEBUG_MSG("Output will be fractional Brownian noise\n");
            fractional_brownian_noise(clo);
            break;
            
        case FRACTIONAL_GARCH_VARIANCES:
            DEBUG_MSG("Output will be stock prices with stochastic volatility driven by fractional continuous time GARCH\n");
            fractional_continuous_garch_price_movement(clo);
            break;

        case MOTION_WITH_FRACTIONAL_GARCH_VARIANCES:
            DEBUG_MSG("Output will be stochastic variance driven by fractional continuous time GARCH\n");
            fractional_continuous_garch_price_variances(clo);
            break;
    }
}
