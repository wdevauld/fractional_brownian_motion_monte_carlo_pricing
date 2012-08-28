#include "continuous_garch_price_volatilities.h"

void continuous_garch_price_volatilities(command_line_options* clo) {
    int sim,step;
    double old_variance, new_variance, dt;
    int method = 0;

    double *fractional_brownian_samples = (double *) calloc(clo->number_of_steps, sizeof(double));
    
    DEBUG_MSG("Executing Hosking's algorithm to generate fractional Brownian noise\n");
    DEBUG_MSG("Producing evolution of volatilities\n");
    
    dt = clo-> end_time / clo-> number_of_steps;

    for(sim = 0; sim < clo->number_of_simulations; sim++) {
        hosking(&(clo->n), &(clo->hurst_exponent), &(clo->end_time), &method, 
                &(clo->seed1), &(clo->seed2), fractional_brownian_samples);

        //Reset to the start of a new path
        old_variance = clo->variance;

        for(step = 0; step < clo->number_of_steps; step++) {

//            printf("variance drift: %f\nold_variance: %f\ndt: %f\nvariance of variance: %f\nsample: %f\n",
//                clo->variance_drift, old_variance, dt, clo->variance_variance, fractional_brownian_samples[step]);

            new_variance = old_variance + 
                           clo->variance_drift * old_variance * dt +
                           clo->variance_variance * old_variance * fractional_brownian_samples[step];

            printf("%lf\t", sqrt(new_variance));
            old_variance = new_variance;
        }
        printf("\n");
    }
}
