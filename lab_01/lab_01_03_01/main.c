#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	double v1, v2;
	double t1, t2;
	double v;
	double t;
	printf("Enter the amount and temperature of the first container:\n");
	scanf("%lf%lf", &v1, &t1);
	printf("Enter the amount and temperature of the second container:\n");
	scanf("%lf%lf", &v2, &t2);
	v = v1 + v2;
	t = (t1 * v1 + t2 * v2) / (v1 + v2);
	printf("%.6f %.6f", v, t);
	return EXIT_SUCCESS;
}
