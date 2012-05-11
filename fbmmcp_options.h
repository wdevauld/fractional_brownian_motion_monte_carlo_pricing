#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

//Oh man, an include guard....
#ifndef FBMMCP_OPTIONS_H
#define FBMMCP_OPTIONS_H 

#define DEBUG_MSG(...) if(clo->debug) fprintf(stderr, __VA_ARGS__)

#define DEFAULT_SIMULATIONS 5
#define DEFAULT_HURST_EXPONENT 0.75
#define DEFAULT_STEPS 16
#define DEFAULT_END_TIME 10.0
#define DEFAULT_OUTPUT 1

//Output options
#define HOSKING_BROWNIAN_MOTION_PATHS 1

typedef struct{
    long number_of_simulations;
    long number_of_steps;
    int debug;
    double hurst_exponent;
    int output_option;
    double end_time;
    long seed1;
    long seed2;
} command_line_options;

int parse_command_line(command_line_options* clo, int argc, char *argv[]);

#endif