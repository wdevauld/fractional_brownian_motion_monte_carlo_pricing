#include <unistd.h>
#include <stdlib.h>

#define DEFAULT_NUM_SIMULATIONS 10000
#define DEFAULT_HURST_EXPONENT 0.75
#define DEFAULT_END_TIME 1.0

typedef struct{
    long number_of_simulations;
    int debug;
    double hurst_exponent;
    double end_time;
} command_line_options;

int parse_command_line(command_line_options* clo, int argc, char *argv[]);