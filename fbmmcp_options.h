#include <unistd.h>

#define DEFAULT_NUM_SIMULATIONS 10000

typedef struct{
    int number_of_simulations;
    int debug;
} command_line_options;

int parse_command_line(command_line_options* clo, int argc, char *argv[]);