#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

//Oh man, an include guard....
#ifndef FBMMCP_OPTIONS_H
#define FBMMCP_OPTIONS_H 

#define DEBUG_MSG(...) if(clo->debug) fprintf(stderr, __VA_ARGS__)

#define DEFAULT_SIMULATIONS 5
#define DEFAULT_STEPS 16
#define DEFAULT_END_TIME 10.0
#define DEFAULT_HURST_EXPONENT 0.75
#define DEFAULT_OUTPUT 1
#define DEFAULT_VARIANCE 0.5
#define DEFAULT_RISK_FREE_RATE 0.0
#define DEFAULT_STOCK_PRICE 10.0
#define DEFAULT_VARIANCE_DRIFT 0.1
#define DEFAULT_VARIANCE_VARIANCE 0.25

//Output options
#define HOSKING_BROWNIAN_MOTION_PATHS 1
#define HOSKING_BROWNIAN_MOTION_NOISE 2
#define MOTION_WITH_FRACTIONAL_GARCH_VARIANCES 3
#define FRACTIONAL_GARCH_VARIANCES 4

#define USAGE "USAGE:\n\
\tfbmmcp -n [NUM]\n\
OPTIONS:\n\
\t-n [NUM]\tNUM of simulations to perform [DEFAULT: 5]\n\
\t-s [NUM]\tNUM of steps per simulation [DEFAULT: 16]\n\
\t-t [NUM]\tThe end time of the simulation [DEFAULT: 10.0]\n\
\t-H [NUM]\tThe Hurst Exponent to use in (0,1) [DEFAULT: 0.75]\n\
\t-o [NUM]\tThe type of output\n\
\t\t 1 - Fractional Brownian motion\n\
\t\t 2 - Fractional Brownian noise\n\
\t\t 3 - Stock price with stochastic volatility driven by continuous GARCH\n\
\t\t 4 - fractional GARCH stochastic volatilities\n\
\t-v [NUM]\tThe starting variance a_0 [DEFAULT: 0.5]\n\
\t-u [NUM]\tStarting stock price S_0 [DEFAULT: 10.0]\n\
\t-r [NUM]\tThe risk free rate[DEFAULT: 0.0]\n\
\t-b [NUM]\tThe mean-reversion level (beta) [DEFAULT: 0.5]\n\
\t-a [NUM]\tThe mean-reversion rate (alpha) [DEFAULT: 0.1]\n\
\t-g [NUM]\tVariance of variance (gamma) [DEFAULT: 0.25]\n\
\t-d\t\tEnable debug/verbose output\n"

typedef struct{
    long number_of_simulations;
    long number_of_steps;
    double end_time;
    double hurst_exponent;
    int output_option;
    double variance;
    double risk_free_rate;
    double stock_price;
    double variance_drift;
    double variance_variance;
    double mean_reversion_level;
    double mean_reversion_rate;
    long seed1;
    long seed2;
    int debug;    
    long n;   // 2^n = number_of_simulations
} command_line_options;

int parse_command_line(command_line_options* clo, int argc, char *argv[]);

#endif
