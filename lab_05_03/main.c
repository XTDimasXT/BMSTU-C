#include "func.h"

/*
Выбранный целочисленный тип - int
Выбранная сортировка - сортировка выбором
Направление упорядочивания - по возрастанию
*/

int main(int argc, char **argv)
{
	if (argc < 3)
		return TOO_FEW_ARGS;
	if (strcmp(argv[1], "c") == 0)
	{
		FILE *f = fopen(argv[2], "wb");
		int res = create_file(f);
		if (res == OPEN_ERROR)
			return OPEN_ERROR;
		fclose(f);
		if (res == WRITE_ERROR)
			return WRITE_ERROR;
	}
	else if (strcmp(argv[1], "p") == 0)
	{
		FILE *f = fopen(argv[2], "rb");
		int res = print_file(f);
		if (res == OPEN_ERROR)
			return OPEN_ERROR;
		fclose(f);
		if (res == FSEEK_ERROR)
			return FSEEK_ERROR;
		if (res == FTELL_ERROR)
			return FTELL_ERROR;
		if (res == SIZE_ERROR)
			return SIZE_ERROR;
	}
	else if (strcmp(argv[1], "s") == 0)
	{
		FILE *f = fopen(argv[2], "rb+");
		int res = sort_file(f);
		if (res == OPEN_ERROR)
			return OPEN_ERROR;
		fclose(f);
		if (res == SIZE_ERROR)
			return SIZE_ERROR;
	}
	else
		return INCORRECT_ARGS;
	return EXIT_SUCCESS;
}
