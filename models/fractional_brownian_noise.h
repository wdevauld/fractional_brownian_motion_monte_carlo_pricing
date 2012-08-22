#include <stdio.h>

#include "../fbmmcp_options.h"
#include "../hosking.h"

#define DEBUG_MSG(...) if(clo->debug) fprintf(stderr, __VA_ARGS__)

void fractional_brownian_noise(command_line_options*);
