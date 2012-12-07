#include <stdio.h>
#include <math.h>

#include "../fbmmcp_options.h"
#include "../hosking.h"

#define DEBUG_MSG(...) if(clo->debug) fprintf(stderr, __VA_ARGS__)

void fractional_ou(command_line_options*);
void fractional_cir(command_line_options*);
