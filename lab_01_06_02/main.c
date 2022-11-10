#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPS 1e-6

int main(void)
{
	double ax, ay;
	double bx, by;
	double cx, cy;
	double mx, my;
	double a, b, c;
	double tmp;
	
	if (scanf("%lf", &ax) != 1 || scanf("%lf", &ay) != 1)
		return EXIT_FAILURE;
	if (scanf("%lf", &bx) != 1 || scanf("%lf", &by) != 1)
		return EXIT_FAILURE;
	if (scanf("%lf", &cx) != 1 || scanf("%lf", &cy) != 1)
		return EXIT_FAILURE;
	tmp = (ax - cx) * (by - cy) - (bx - cx) * (ay - cy);
	if (fabs(tmp) < EPS)
		return EXIT_FAILURE;
		
	if (scanf("%lf", &mx) != 1 || scanf("%lf", &my) != 1)
		return EXIT_FAILURE; 
	a = (ax - mx) * (by - ay) - (bx - ax) * (ay - my);
	b = (bx - mx) * (cy - by) - (cx - bx) * (by - my);
	c = (cx - mx) * (ay - cy) - (ax - cx) * (cy - my);
	
	if ((a > 0.0 && b > 0.0 && c > 0.0) || (a < 0.0 && b < 0.0 && c < 0.0))
		printf("0");
	else if ((fabs(a) < EPS) || (fabs(b) < EPS) || (fabs(c) < EPS))
		printf("1");
	else
		printf("2");
	return EXIT_SUCCESS;
} 
