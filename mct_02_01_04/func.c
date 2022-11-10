#define _XOPEN_SOURCE 500

#include "func.h"
 
int scan_info(company_t *company)
{
	if (scanf("%s", company->name) != 1)
		return SCAN_FAILURE;
	if (scanf("%d", &company->work_num) != 1)
		return SCAN_FAILURE;
	if (scanf("%d", &company->volume) != 1)
		return SCAN_FAILURE;
	if (scanf("%s", company->type) != 1)
		return SCAN_FAILURE;
	return EXIT_SUCCESS;
}

int sort_companies_by_name(FILE *f)
{
	company_t company, min_company;
	long int i, j, ind_min;
	long int file_size;
	if (size_file(f, &file_size) != 0)
		return SIZE_ERROR;
	for (i = 0; i < file_size - 1; i++)
	{
		ind_min = i;
		get_company_by_pos(f, &min_company, ind_min);
		for (j = i + 1; j < file_size; j++)
		{
			get_company_by_pos(f, &company, j);
			if (strcmp(company.name, min_company.name) < 0)
			{
				ind_min = j;
				min_company = company;
			}
		}
		get_company_by_pos(f, &company, i);
		put_company_by_pos(f, &company, ind_min);
		put_company_by_pos(f, &min_company, i);
	}
	return EXIT_SUCCESS;		
}

int sort_companies_by_work_num(FILE *f)
{
	company_t company, min_company;
	long int i, j, ind_min;
	long int file_size;
	if (size_file(f, &file_size) != 0)
		return SIZE_ERROR;
	for (i = 0; i < file_size - 1; i++)
	{
		ind_min = i;
		get_company_by_pos(f, &min_company, ind_min);
		for (j = i + 1; j < file_size; j++)
		{
			get_company_by_pos(f, &company, j);
			if (company.work_num < min_company.work_num)
			{
				ind_min = j;
				min_company = company;
			}
		}
		get_company_by_pos(f, &company, i);
		put_company_by_pos(f, &company, ind_min);
		put_company_by_pos(f, &min_company, i);
	}
	return EXIT_SUCCESS;
}

int sort_companies_by_volume(FILE *f)
{
	company_t company, min_company;
	long int i, j, ind_min;
	long int file_size;
	if (size_file(f, &file_size) != 0)
		return SIZE_ERROR;
	for (i = 0; i < file_size - 1; i++)
	{
		ind_min = i;
		get_company_by_pos(f, &min_company, ind_min);
		for (j = i + 1; j < file_size; j++)
		{
			get_company_by_pos(f, &company, j);
			if (company.volume < min_company.volume)
			{
				ind_min = j;
				min_company = company;
			}
		}
		get_company_by_pos(f, &company, i);
		put_company_by_pos(f, &company, ind_min);
		put_company_by_pos(f, &min_company, i);
	}
	return EXIT_SUCCESS;
}

int sort_companies_by_type(FILE *f)
{
	company_t company, min_company;
	long int i, j, ind_min;
	long int file_size;
	if (size_file(f, &file_size) != 0)
		return SIZE_ERROR;
	for (i = 0; i < file_size - 1; i++)
	{
		ind_min = i;
		get_company_by_pos(f, &min_company, ind_min);
		for (j = i + 1; j < file_size; j++)
		{
			get_company_by_pos(f, &company, j);
			if (strcmp(company.type, min_company.type) < 0)
			{
				ind_min = j;
				min_company = company;
			}
		}
		get_company_by_pos(f, &company, i);
		put_company_by_pos(f, &company, ind_min);
		put_company_by_pos(f, &min_company, i);
	}
	return EXIT_SUCCESS;
}

long int size_file(FILE *f, long int *file_size)
{
	if (fseek(f, 0, SEEK_END) != 0)
		return FSEEK_ERROR;
	long int cur_pos = ftell(f);
	if (cur_pos == -1 || cur_pos == 0 || cur_pos % (long int) sizeof(company_t) != 0)
		return FTELL_ERROR;
	*file_size = cur_pos / sizeof(company_t);
	long int start = fseek(f, 0, SEEK_SET);
	return start;
}

int delete_companies(FILE *f)
{
	company_t company;
	long int i;
	long int file_size;
	int k = 0;
	char temp[] = "chairs";
	if (size_file(f, &file_size) != 0)
		return SIZE_ERROR;
	for (i = 0; i < file_size; i++)
	{
		get_company_by_pos(f, &company, i);
		if (strcmp(company.type, temp) != 0)
		{
			put_company_by_pos(f, &company, k);
			k++;
		}
	}
	ftruncate(fileno(f), sizeof(company_t) * (file_size - k));
	return EXIT_SUCCESS;
}

int get_company_by_pos(FILE *f, company_t *company, long int ind)
{
	if (fseek(f, sizeof(company_t) * ind, SEEK_SET) != 0)
		return FSEEK_ERROR;
	if (fread(company, sizeof(company_t), 1, f) != 1)
		return FREAD_ERROR;
	return EXIT_SUCCESS;
}

int put_company_by_pos(FILE *f, company_t *company, long int ind)
{
	if (fseek(f, sizeof(company_t) * ind, SEEK_SET) != 0)
		return FSEEK_ERROR;
	if (fwrite(company, sizeof(company_t), 1, f) != 1)
		return FWRITE_ERROR;
	return EXIT_SUCCESS;
}
