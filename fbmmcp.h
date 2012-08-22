#include <time.h>
#include <sys/time.h>

#include <stdio.h>
#define DEBUG_MSG(...) if(clo->debug) fprintf(stderr, __VA_ARGS__)

// fractional Brownian Motion Libraries
#include "circulant.h"
#include "hosking.h" 

// option parsing
#include "fbmmcp_options.h"

// Models or Modes of output functions
#include "models/fractional_brownian_motion.h"

#define USAGE "USAGE:\n\
\tfbmmcp -n [NUM]\n\
OPTIONS:\n\
\t-n [NUM]\tNUM of independent samples to perform [DEFAULT: 10]\n\
\t-H [NUM]\tThe Hurst Exponent, NUM, to use in (0,1) [DEFAULT: 0.75]\n\
\t-v\t\tEnable verbose output\n\
\t-t [NUM]\tThe end time of the simulation [DEFAULT: 10.0]\n\
\t-o [NUM]\tThe type of output\n\
\t\t 1 - Fractional Brownian motion\n\
\t\t 2 - Fractional Brownian noise\n\
\t\t 3 - Geometric fractional brownian motion\n\
\t\t 4 - Geometric Fractional brownian noise\n"