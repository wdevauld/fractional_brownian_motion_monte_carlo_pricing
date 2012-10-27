#include "fractional_mean_reverting_volatilities.h"

void fractional_mean_reverting_volatilities(command_line_options* clo) {
    int sim,step;
    double old_volatilities, new_volatilities, old_price, new_price, dt;
    double h = 0.5; 
    int method = 0;

    double *fractional_brownian_samples = (double *) calloc(clo->number_of_steps, sizeof(double));
    double *brownian_samples = (double *) calloc(clo->number_of_steps, sizeof(double));
    DEBUG_MSG("Executing Hosking's algorithm to generate paths\n");
    DEBUG_MSG("Producing evolution of volatilities\n");
   
    dt = clo->end_time / clo->number_of_steps;
 
    for(sim = 0; sim < clo->number_of_simulations; sim++) {
        //Franctional Brownian Motion
        hosking(&(clo->n), &(clo->hurst_exponent), &(clo->end_time), &method, 
                &(clo->seed1), &(clo->seed2), fractional_brownian_samples);

        //Use Hurst = 0.5 to get standard brownian motion
        hosking(&(clo->n), &h, &(clo->end_time), &method, 
                &(clo->seed1), &(clo->seed2), brownian_samples);

        old_volatilities = clo->variance;
        old_price = clo->stock_price; 

        for(step = 0; step < clo->number_of_steps; step++) {
            new_volatilities = old_volatilities + 
                           clo->mean_reversion_rate * (clo->mean_reversion_level - old_volatilities) * dt +
                           clo->variance_variance * old_volatilities * fractional_brownian_samples[step];

            new_price = old_price +
                        clo->risk_free_rate * old_price * dt +
                        new_volatilities * old_price * brownian_samples[step]; //These are already scaled via hoskin 

            printf("%lf\t", new_price);
            old_price = new_price;
            old_volatilities = new_volatilities;
        }
        printf("\n");
    }
}
