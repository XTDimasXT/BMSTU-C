#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI acos(-1)

int main(void)
{
	double a, b;
	double c;
	double s;
	printf("Enter the bases of the trapezoid:\n");
	scanf("%lf%lf", &a, &b);
	printf("Enter the angle of the trapezoid:\n");
	scanf("%lf", &c);
	c = c * PI / 180.0;
	while (c > PI / 2.0)
		c = c - PI / 2.0;
	while (c < 0)
		c = c + PI / 2.0;
	s = fabs(tan(c) * 0.25 * (b - a) * (b + a));
	printf("%.6f", s);
	return EXIT_SUCCESS;
}
