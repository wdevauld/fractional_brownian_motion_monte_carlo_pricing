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
#include "models/fractional_brownian_noise.h"
#include "models/geometric_fractional_brownian_motion.h"
#include "models/geometric_fractional_brownian_volatilities.h"

