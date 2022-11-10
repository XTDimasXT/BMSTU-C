#ifndef __FIND_DIFF_H__

#define __FIND_DIFF_H__

#include <stdio.h>
#include <stdlib.h>

#define NO_ELEMS -1
#define TOO_FEW_ELEMS -2
#define LOCAL_MAX_ERROR -3

int process(FILE *f, int *diff);

#endif // #ifndef __FIND_DIFF_H__
