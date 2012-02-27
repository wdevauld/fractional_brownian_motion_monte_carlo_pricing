#include <stdio.h>
// fractional Brownian Motion Libraries
#include "circulant.h"
#include "hosking.h" 

// option parsing
#include "fbmmcp_options.h"

#define USAGE "USAGE:\n\
\tfbmmcp -n [NUM]\n\
FLAGS:\n\
\t-n [NUM]\tNUM of independent samples to perform\n\
OPTIONS:\n"
