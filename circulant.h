/*  Copyright Ton Dieker                                                    */
/*  Centre of Mathematics and Computer Science (CWI) Amsterdam              */
/*  April 2002                                                              */
/*  ton@cwi.nl                                                              */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "matrix.h"
#include "matrix2.h"
#include "ranlib.h"

extern void circulant(long *n, double *H, double *L, int *cum, 
		      long *seed1, long *seed2, double *output);
