#ifndef __FUNC_C__

#define __FUNC_C__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WRITE_ERROR 1
#define TOO_FEW_ARGS 2
#define FSEEK_ERROR 3
#define FTELL_ERROR 4
#define SIZE_ERROR 5
#define READ_ERROR 6
#define OPEN_ERROR 7
#define INCORRECT_ARGS 8

int create_file(FILE *f);
long int size_file(FILE *f, long int *file_size);
int get_number_by_pos(FILE *f, int *number, long int ind);
int put_number_by_pos(FILE *f, int number, long int ind);
int print_file(FILE *f);
int sort_file(FILE *f);

#endif // #ifndef __FUNC_C__
