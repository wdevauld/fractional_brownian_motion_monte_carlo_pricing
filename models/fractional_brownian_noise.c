#include "fractional_brownian_motion.h"

void fractional_brownian_noise(command_line_options* clo) {
    int sim,step;
    int method = 0;
    double *fractional_brownian_samples = (double *) calloc(clo->number_of_steps, sizeof(double));
    DEBUG_MSG("Executing Hosking's algorithm to generate noise\n");
    
    for(sim = 0; sim < clo->number_of_simulations; sim++) {
        hosking(&(clo->n), &(clo->hurst_exponent), &(clo->end_time), &method, 
                &(clo->seed1), &(clo->seed2), fractional_brownian_samples);
                
        for(step = 0; step < clo->number_of_steps; step++) {
            printf("%lf\t", fractional_brownian_samples[step]);
        }
        printf("\n");
    }
}
