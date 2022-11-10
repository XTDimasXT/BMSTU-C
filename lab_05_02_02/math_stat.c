#include "math_stat.h"

int arithmetic_mean(FILE *f, double *avg)
{
	double curr;
	double sum = 0.0;
	int k = 1;
	
	if (fscanf(f, "%lf", &curr) != 1)
		return NO_ELEMS;
	sum += curr;
	while (fscanf(f, "%lf", &curr) == 1)
	{
		sum += curr;
		k++;
	}
	*avg = sum / k;
	rewind(f);
	return EXIT_SUCCESS;
}

int dispersion(FILE *f, double *disp)
{
	double curr;
	double sum = 0.0;
	int k = 1;
	double avg;
	
	if (arithmetic_mean(f, &avg) != 0)
		return NO_ELEMS;
	if (fscanf(f, "%lf", &curr) != 1)
		return NO_ELEMS;
	sum += (curr - avg) * (curr - avg);
	while (fscanf(f, "%lf", &curr) == 1)
	{
		sum += (curr - avg) * (curr - avg);
		k++;
	}
	*disp = sum / k;
	rewind(f);
	return EXIT_SUCCESS;
}
