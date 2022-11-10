#include "find_diff.h"

int process(FILE *f, int *diff)
{
	int prev, curr, next;
	int index1 = 0;
	int index2 = 0;
	int k = 3;
	int temp;
	
	if (fscanf(f, "%d", &prev) != 1)
		return NO_ELEMS;
	if (fscanf(f, "%d", &curr) != 1)
		return TOO_FEW_ELEMS;
	if (fscanf(f, "%d", &next) != 1)
		return TOO_FEW_ELEMS;
	if (curr > prev && curr > next)
		index1 = 2;
	while (fscanf(f, "%d", &temp) == 1)
	{
		prev = curr;
		curr = next;
		next = temp;
		if (curr > prev && curr > next)
		{
			if (index2 != 0)
			{
				index1 = index2;
				index2 = k;
				if (index2 - index1 < *diff)
					*diff = index2 - index1;
			}
			else if (index1 == 0)
				index1 = k;
			else if (index2 == 0)
			{
				index2 = k;
				*diff = index2 - index1;
			}
		}
		k++;
	}
	if (index2 == 0)
		return LOCAL_MAX_ERROR;
	return EXIT_SUCCESS;
}	
