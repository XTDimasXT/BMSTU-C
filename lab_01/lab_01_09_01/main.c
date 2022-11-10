#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	int n = 0;
	double g = 0;
	double x;
	double gx;
	
	printf("Enter x:\n");
	if (scanf("%lf", &x) != 1)
		return EXIT_FAILURE;
	while (x >= 0)
	{
		n++;
		g += sqrt(x / n);
		if (scanf("%lf", &x) != 1)
			return EXIT_FAILURE;
	}
	if (n == 0)
		return EXIT_FAILURE;
	gx = sin(g);
	printf("%.6f", gx);
	return EXIT_SUCCESS;
}
