#include "fbmmcp.h"

int main(int argc, char *argv[] )
{
    command_line_options *clo = calloc(1, sizeof(command_line_options));
    int n;

    if(!parse_command_line(clo, argc, argv)) {
        //Exit with failure after printing usage if the parameter parsing
        //has determined that things aren't right
        printf(USAGE);
        return 1; 
    }
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
            
        case MOTION_WITH_FRACTIONAL_OU:
            DEBUG_MSG("Output will be stock prices with stochastic volatility driven by fractional Ornstein-Uhlenbeck\n");
            fractional_ou(clo);
            break;

        case FRACTIONAL_GARCH:
            DEBUG_MSG("Output will be fractional Continuous GARCH(1,1)\n");
            fractional_garch(clo);
            break;
            
        case MOTION_WITH_FRACTIONAL_CIR:
            DEBUG_MSG("Output will be stock prices with stochastic volatility driven by fractional Cox-Ingersoll-Ross\n");
            fractional_cir(clo);
            break;

        case FRACTIONAL_HESTON:
            DEBUG_MSG("Output will be fractional Heston\n");
            fractional_heston(clo);
            break;               
    }
}
