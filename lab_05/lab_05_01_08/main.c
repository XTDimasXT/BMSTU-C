#include "find_diff.h"

int main(void)
{
	int diff;
	FILE *f = stdin;
	int res;
	
	res = process(f, &diff);
	if (res == NO_ELEMS)
		return NO_ELEMS;
	if (res == TOO_FEW_ELEMS)
		return TOO_FEW_ELEMS;
	if (res == LOCAL_MAX_ERROR)
		return LOCAL_MAX_ERROR;
	
	printf("%d", diff);
	return EXIT_SUCCESS;
}
