#include "fbmmcp.h"

int main(int argc, char *argv[] )
{
    command_line_options *clo = malloc(sizeof(command_line_options));
    parse_command_line(clo, argc, argv);

    printf("Executing with %d simulations\n", clo->number_of_simulations);
}
