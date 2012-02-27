#include "fbmmcp.h"

#define DEBUG_MSG(...) if(clo->debug) fprintf(stderr, __VA_ARGS__)

int main(int argc, char *argv[] )
{
    command_line_options *clo = malloc(sizeof(command_line_options));
    memset(clo,0,sizeof(command_line_options));
    
    if(!parse_command_line(clo, argc, argv)) {
        //Exit with failure after printing usage if the parameter parsing
        //has determined that things aren't right
        printf(USAGE);
        return 1; 
    }

    DEBUG_MSG("Executing with %'d simulations\n", clo->number_of_simulations);
    DEBUG_MSG("Using %f as a Hurst Exponent\n", clo->hurst_exponent);
    
 //   void hosking(clo.number_of_simulations, clo.hurst_exponent, double *L, int *cum, 
 //   	     long *seed1, long *seed2, double *output) {
      /* function that generates a fractional Brownian motion or fractional  */
      /* Gaussian noise sample using the Hosking method.                     */
      /* Input:  *n      determines the sample size N by N=2^(*n)            */
      /*         *H      the Hurst parameter of the trace                    */
      /*         *L      the sample is generated on [0,L]                    */
      /*         *cum    = 0: fractional Gaussian noise is produced          */
      /*                 = 1: fractional Brownian motion is produced         */
      /*         *seed1  seed1 for the random generator                      */
      /*         *seed2  seed2 for the random generator                      */
      /* Output: *seed1  new seed1 of the random generator                   */
      /*         *seed2  new seed2 of the random generator                   */
      /*         *output the resulting sample is stored in this array        */
    
    printf("0\n");
}
