#include <unistd.h>

typedef struct{
    int number_of_simulations;
} command_line_options;

int parse_command_line(command_line_options* clo, int argc, char *argv[]);