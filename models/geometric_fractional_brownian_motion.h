#include <stdio.h>

#include "../fbmmcp_options.h"
#include "../hosking.h"

#define DEBUG_MSG(...) if(clo->debug) fprintf(stderr, __VA_ARGS__)

void geometric_fractional_brownian_motion(command_line_options*);
