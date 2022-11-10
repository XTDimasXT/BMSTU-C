#ifndef __MATH_STAT_H__

#define __MATH_STAT_H__

#include <stdio.h>
#include <stdlib.h>

#define NO_ELEMS -1
#define OPEN_ERROR 1
#define TOO_FEW_ARGS 2

int arithmetic_mean(FILE *f, double *avg);
int dispersion(FILE *f, double *disp);

#endif // #ifndef __MATH_STAT_H__
