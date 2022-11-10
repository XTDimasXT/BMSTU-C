#ifndef __FUNC_C__

#define __FUNC_C__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
 
#define SCAN_FAILURE 1
#define SIZE_ERROR 2
#define FSEEK_ERROR 3
#define FTELL_ERROR 4
#define FREAD_ERROR 5
#define FWRITE_ERROR 6

#define STR_LEN 15
 
typedef struct
{
	char name[STR_LEN];
	int work_num;
	int volume;
	char type[STR_LEN];
} company_t;

int scan_info(company_t *company);
int sort_companies_by_name(FILE *f);
int sort_companies_by_work_num(FILE *f);
int sort_companies_by_volume(FILE *f);
int sort_companies_by_type(FILE *f);
long int size_file(FILE *f, long int *size_file);
int delete_companies(FILE *f);
int get_company_by_pos(FILE *f, company_t *company, long int ind);
int put_company_by_pos(FILE *f, company_t *company, long int ind);

#endif // #ifndef __FUNC_C__
