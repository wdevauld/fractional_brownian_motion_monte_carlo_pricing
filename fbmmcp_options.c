#include "fbmmcp_options.h"

int parse_command_line(command_line_options* clo, int argc, char *argv[]) {
    int opt;
    long n;
    int error_encountered = 0;
    while((opt = getopt(argc, argv, "H:n:dt:s:o:v:r:u:b:g:")) != -1) {
        switch(opt)
        {
            case 'n':
                clo->number_of_simulations = atoi(optarg);
                break;
            case 's':
                clo->number_of_steps = atoi(optarg);
                break;
            case 't':
                clo->end_time = atof(optarg);
                break;
            case 'H':
                clo->hurst_exponent = atof(optarg);
                break;
            case 'o':
                clo->output_option = atoi(optarg);
                break;
            case 'v':
                clo->variance = atof(optarg);
                break;
            case 'u':
                clo->stock_price = atof(optarg);
                break;
            case 'r':
                clo->risk_free_rate = atof(optarg);
                break;
            case 'b':
                clo->mean_reversion_level = atof(optarg);
                break;
            case 'a':
                clo->mean_reversion_rate = atof(optarg);
                break;
            case 'g':
                clo->variance_variance = atof(optarg);
                break;
            case 'd':
                clo->debug = 1;
                break;
            default: 
                //Most likely the user entered an invalid option
                error_encountered = 1;
        }
    }
    //Check if the parameters are all valid.
    if(clo->number_of_simulations <= 0) {
        clo->number_of_simulations = DEFAULT_SIMULATIONS;
    }
    
    DEBUG_MSG("Executing %ld simulations\n", clo->number_of_simulations);
    if(clo->number_of_steps <= 0) {
        clo->number_of_steps = DEFAULT_STEPS;
    }
    n = floor(log2(clo->number_of_steps));
    clo->number_of_steps = pow(2,n);
    DEBUG_MSG("Paths contain 2^%ld (%ld) steps\n", n,  clo->number_of_steps);
    
    if(clo->hurst_exponent < 0.5 || clo->hurst_exponent >= 1) {
        clo->hurst_exponent = DEFAULT_HURST_EXPONENT;
    }
    DEBUG_MSG("Using %f as a Hurst Exponent\n", clo->hurst_exponent);
    
    if(clo->end_time <= 0) {
        clo->end_time = DEFAULT_END_TIME;
    }
    DEBUG_MSG("Simulating to t=%f\n", clo->end_time);

    if(clo->output_option < 1 || clo-> output_option > 6) {
        clo->output_option = DEFAULT_OUTPUT;
    }

    if(clo->variance <= 0) {
        clo->variance = DEFAULT_VARIANCE;
    }
    DEBUG_MSG("Starting variance/volatility is: %f\n", clo->variance);
    
    if(clo->risk_free_rate <= 0) {
        clo->risk_free_rate = DEFAULT_RISK_FREE_RATE;
    }
    DEBUG_MSG("Using %f as a risk free rate\n", clo->risk_free_rate);

    if(clo->stock_price <= 0) {
        clo->stock_price = DEFAULT_STOCK_PRICE;
    }
    DEBUG_MSG("Starting stock price is $ %f\n", clo->stock_price);
    
    DEBUG_MSG("Mean reversion rate is %f\n", clo->mean_reversion_rate);
    
    
    //TODO: Add in checking of the level.

    if(clo->variance_variance <= 0) {
        clo->variance_variance = DEFAULT_VARIANCE_VARIANCE;
    }
    DEBUG_MSG("Volatility of Volatility is set to %f\n", clo->variance_variance);
    
    return !error_encountered;
}
