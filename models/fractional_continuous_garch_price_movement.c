#include "fractional_continuous_garch_price_movement.h"

void fractional_continuous_garch_price_movement(command_line_options* clo) {
    int sim,step;
    double old_variance, new_variance, old_price, new_price, dt;
    double h = 0.5; 
    int method = 0;

    double *fractional_brownian_samples = (double *) calloc(clo->number_of_steps, sizeof(double));
    double *brownian_samples = (double *) calloc(clo->number_of_steps, sizeof(double));
    DEBUG_MSG("Executing Hosking's algorithm to generate paths\n");
   
    dt = clo->end_time / clo->number_of_steps;
 
    for(sim = 0; sim < clo->number_of_simulations; sim++) {
        //Franctional Brownian Motion
        hosking(&(clo->n), &(clo->hurst_exponent), &(clo->end_time), &method, 
                &(clo->seed1), &(clo->seed2), fractional_brownian_samples);

        //Use Hurst = 0.5 to get standard brownian motion
        hosking(&(clo->n), &h, &(clo->end_time), &method, 
                &(clo->seed1), &(clo->seed2), brownian_samples);

        old_variance = clo->variance;
        old_price = clo->stock_price; 

        for(step = 0; step < clo->number_of_steps; step++) {
            new_variance = old_variance + 
                           clo->variance_drift * old_variance * dt +
                           clo->variance_variance * old_variance * fractional_brownian_samples[step];

            new_price = old_price +
                        clo->risk_free_rate * old_price * dt +
                        sqrt(new_variance) * old_price * brownian_samples[step]; //These are already scaled via hoskin 


            printf("%lf\t", new_price);
            old_price = new_price;
            old_variance = new_variance;
        }
        printf("\n");
    }
}
