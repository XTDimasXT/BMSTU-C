#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPS 1e-8

int main()
{
	double f;
	double s;
	double eps;
	double x;
	double a;
	int i;
	
	if (scanf("%lf", &x) != 1 || x == 0)
		return EXIT_FAILURE;
	if (scanf("%lf", &eps) != 1 || eps <= 0 || fabs(eps) < EPS)
		return EXIT_FAILURE;
	
	f = (1.0 / (x * x * x)) * (1.0 - exp(-(x * x)) * (1.0 + x * x));
	
	i = 2;
	a = ((-1) * x * x * x) / ((i - 1) + i);
	s = a;
	while (fabs(a) > eps * eps)
	{
		a = a * (-x * x * (1.0 + i)) / (i * i + 2.0 * i);
		s += a;
		i++;
	}
	
	printf("%e %g", f, s);
	return EXIT_SUCCESS;
}
