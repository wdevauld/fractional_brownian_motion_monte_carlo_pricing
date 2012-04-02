#include "fbmmcp.h"

#define DEBUG_MSG(...) if(clo->debug) fprintf(stderr, __VA_ARGS__)

int main(int argc, char *argv[] )
{
    command_line_options *clo = calloc(1, sizeof(command_line_options));
    int i;
    double T;
    int method = 1;
    long seed1, seed2, n;
    struct timeval ts;
    double *fractional_brownian_samples;
    gettimeofday(&ts, NULL);
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


    DEBUG_MSG("User desired: %ld simulations\n", clo->number_of_simulations);

    //Ensure that the number of simulations is a power of 2
    //so that both the fBm algorithms will work
    
    n = floor(log2(clo->number_of_simulations));
    clo->number_of_simulations = pow(2,n);
    fractional_brownian_samples = (double *) calloc(clo->number_of_simulations, sizeof(double));
    
    T = (double)clo->end_time;    

    DEBUG_MSG("Executing 2^%ld (%ld) simulations\n", n,  clo->number_of_simulations);    
    DEBUG_MSG("Using %f as a Hurst Exponent\n", clo->hurst_exponent);
    DEBUG_MSG("Simulating on [0,%f]\n", clo->end_time);
    DEBUG_MSG("Time increment: %f\n", clo->end_time / clo->number_of_simulations);

    //TODO allow the user to specify the seeds
    seed1 = ts.tv_sec;
    seed2 = ts.tv_usec;
    
    DEBUG_MSG("Seeds are set to: 1=>%ld 2=>%ld\n", seed1, seed2);
    
    hosking(&n, &(clo->hurst_exponent), &(T), &method, 
        &seed1, &seed2, fractional_brownian_samples);
    for(i = 0; i < clo->number_of_simulations; i++) {
        printf("%f\n", fractional_brownian_samples[i]);
    }
}
