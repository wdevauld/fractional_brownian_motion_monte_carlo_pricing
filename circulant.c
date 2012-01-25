/*  This program simulates fractional Gaussian noise or fractional          */
/*  Brownian motion using the Wood and Chan algorithm.                      */
/*  The C-packages Ranlib and Meschach are used, both available             */
/*  via Netlib (http://www.netlib.org).                                     */

/*  References:                                                             */
/*  1) R.B. Davies and D.S. Harte (1987),                                   */
/*     Tests for Hurst effect,                                              */
/*     Biometrika, Vol. 74, pp. 95--102.                                    */
/*  2) C.R. Dietrich and G.N. Newsam (1997),                                */
/*     Fast and exact simulation of stationary Gaussian processes through   */
/*     circulant embedding of the covariance matrix,                        */
/*     SIAM Journal Sci. Comput., Vol. 18, pp. 1088--1107.                  */
/*  3) A. Wood and G. Chan (1994),                                          */
/*     Simulation of Stationary Gaussian Processes in [0,1]^d,              */
/*     Journal of Comp. and Graphical Statistics, Vol. 3, pp. 409--432.     */

/*  Copyright Ton Dieker                                                    */
/*  Centre of Mathematics and Computer Science (CWI) Amsterdam              */
/*  April 2002                                                              */

/*  ton@cwi.nl                                                              */


#include "circulant.h"

/* the autocovariance function of fractional Gaussian noise */
extern double covariance(long i, double H);


VEC *eigenvalues(double n, double H) {
  /* computes the eigenvalues of the circulant matrix that embeds the */
  /* covariance matrix                                                */

  VEC *re;
  VEC *im;
  long i, size = pow(2,n+1);
  re = v_get(size);
  im = v_get(size);

  for (i=0; i<size; i++) {
    if (i<=pow(2,n)) 
      re->ve[i] = covariance(i, H);
    else
      re->ve[i] = re->ve[size-i];
  }
  im = v_zero(im);

  fft(re,im); 
  v_free(im);

  for (i=0; i<size; i++) {
    if (re->ve[i] <= 0) {
      printf("The program should be modified to deal with this ");
      printf("covariance function.\n");
      printf("See A. Wood and G. Chan (1994),\n");
      printf("Simulation of Stationary Gaussian Processes in [0,1]^d,\n");
      printf("Journal of Computational and Graphical ");
      printf("Statistics, Vol. 3, pp. 409-432\n");
      exit(0);
    }      
  }

  return re;
}


void computeSandT(long m, VEC *ev, VEC *S, VEC *T) {
  /* simulates two auxiliary vectors that serve as input */
  /* in the FFT algorithm                                */
  long i;

  S->ve[0]   = sqrt(ev->ve[0])*snorm()/sqrt(m);
  T->ve[0]   = 0;
  S->ve[m/2] = sqrt(ev->ve[m/2])*snorm()/sqrt(m);
  T->ve[m/2] = 0;
  
  for (i=1; i<m/2; i++) {
    S->ve[i]   = sqrt(ev->ve[i])*snorm()/sqrt(2*m);
    T->ve[i]   = sqrt(ev->ve[i])*snorm()/sqrt(2*m); 
    S->ve[m-i] = S->ve[i];
    T->ve[m-i] = -T->ve[i];
  }
}


void circulant(long *n, double *H, double *L, int *cum, 
	       long *seed1, long *seed2, double *output) {
  /* function that generates a fractional Brownian motion or fractional  */
  /* Gaussian noise sample.                                              */
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
  VEC *ev;
  VEC *S;
  VEC *T;
  long i, generator;
  double scaling;

  /* set random generator and seeds */
  snorm(); 
  generator = 1;
  gscgn(1, &generator);
  setall(*seed1,*seed2);

  /* compute the eigenvalues of the circulant matrix */
  ev = eigenvalues(*n, *H);

  /* compute the input vectors for the FFT algorithm */
  S  = v_get(pow(2,*n+1));
  T  = v_get(pow(2,*n+1));
  computeSandT(pow(2,*n+1), ev, S, T);

  /* real part of Fourier transform of S + iT gives sample path */
  fft(S,T);
  
  /* rescale to obtain a sample of size 2^(*n) on [0,L] */
  v_resize(S,pow(2,*n));
  scaling = pow(*L/pow(2,*n),*H);
  for(i=0; i<pow(2,*n); i++) {
    output[i] = scaling*(S->ve[i]);
    if (*cum && i>0) {
      output[i] += output[i-1];
    }
  }
  
  /* store the new random seeds and free memory */
  getsd(seed1,seed2);

  v_free(ev);
  v_free(S);
  v_free(T);
}
