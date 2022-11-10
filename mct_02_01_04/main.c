/*
О каждом предприятии известно: название, число работников, объем продукции за месяц, тип продукции
Реализовать добавление, сортировку по каждому из полей, удаление всех предприятий, производящих стулья
*/

#include "func.h"

int main(int argc, char **argv)
{
	if (argc < 2)
		return EXIT_FAILURE;
	if (strcmp(argv[1], "add") == 0)
	{
		FILE *f;
		company_t company;
		f = fopen(argv[2], "ab");
		int res = scan_info(&company);
		if (res == SCAN_FAILURE)
			return SCAN_FAILURE;
		fwrite(&company, sizeof(company_t), 1, f);
		fclose(f);
	}
	else if (strcmp(argv[1], "sort_name") == 0)
	{
		FILE *f;
		f = fopen(argv[2], "rb+");
		int res = sort_companies_by_name(f);
		if (res == SIZE_ERROR)
			return SIZE_ERROR;
		fclose(f);
	}
	else if (strcmp(argv[1], "sort_work_num") == 0)
	{
		FILE *f;
		f = fopen(argv[2], "rb+");
		int res = sort_companies_by_work_num(f);
		if (res == SIZE_ERROR)
			return SIZE_ERROR;
		fclose(f);
	}
	else if (strcmp(argv[1], "sort_volume") == 0)
	{
		FILE *f;
		f = fopen(argv[2], "rb+");
		int res = sort_companies_by_volume(f);
		if (res == SIZE_ERROR)
			return SIZE_ERROR;
		fclose(f);
	}
	else if (strcmp(argv[1], "sort_type") == 0)
	{
		FILE *f;
		f = fopen(argv[2], "rb+");
		int res = sort_companies_by_type(f);
		if (res == SIZE_ERROR)
			return SIZE_ERROR;
		fclose(f);
	}
	else if (strcmp(argv[1], "delete") == 0)
	{
		FILE *f;
		f = fopen(argv[2], "rb+");
		int res = delete_companies(f);
		if (res == SIZE_ERROR)
			return SIZE_ERROR;
		fclose(f);
	}
	return EXIT_SUCCESS;
}
