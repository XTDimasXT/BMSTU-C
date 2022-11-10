#include "math_stat.h"

int main(int argc, char **argv)
{
	double disp;
	int res;
	
	if (argc < 2)
		return TOO_FEW_ARGS;
	FILE *f = fopen(argv[1], "r");
	if (f == NULL)
		return OPEN_ERROR;
	res = dispersion(f, &disp);
	if (res != 0)
		return NO_ELEMS;
	fclose(f);
	printf("%lf", disp);
	return EXIT_SUCCESS;
}
