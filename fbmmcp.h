#include <stdio.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>

// fractional Brownian Motion Libraries
#include "circulant.h"
#include "hosking.h" 

// option parsing
#include "fbmmcp_options.h"

#define USAGE "USAGE:\n\
\tfbmmcp -n [NUM]\n\
OPTIONS:\n\
\t-n [NUM]\tNUM of independent samples to perform [DEFAULT: 10,000]\n\
\t-H [NUM]\tThe Hurst Exponent, NUM, to use in (0,1) [DEFAULT: 0.75]\n\
\t-d\t\tEnable debug output\n\
\t-t [NUM]\tThe end time of the simulation [DEFAULT: 1.0]\n"
