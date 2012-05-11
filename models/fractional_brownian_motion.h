#include <stdio.h>

#include "../fbmmcp_options.h"

#define DEBUG_MSG(...) if(clo->debug) fprintf(stderr, __VA_ARGS__)

void fractional_brownian_motion(command_line_options*);