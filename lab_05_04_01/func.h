#ifndef __FUNC_C__

#define __FUNC_C__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <unistd.h>
#include <sys/types.h>
 
#define SURNAME_LEN 26
#define NAME_LEN 11
#define MARK_LEN 4

#define ARGS_ERROR 53
#define FREAD_ERROR 1
#define FWRITE_ERROR 2
#define FSEEK_ERROR 3
#define SIZE_ERROR 4
#define SCAN_FAILURE 5
#define FTELL_ERROR 6
#define LEN_ERROR 7
#define OPEN_ERROR 8
#define COPY_ERROR 9

typedef struct
{
	char surname[SURNAME_LEN];
	char name[NAME_LEN];
	uint32_t marks[MARK_LEN];
} student_t;

int scan_info(student_t *student);
int sort_students_by_surname(FILE *f);
long int size_file(FILE *f, long int *size_file);
double count_avg(FILE *f);
double count_student_avg(FILE *f, long int i);
int delete_students(FILE *f);
int copy_students(FILE *f, FILE *new_f, char *substr);
int get_student_by_pos(FILE *f, student_t *student, long int ind);
int put_student_by_pos(FILE *f, student_t *student, long int ind);

#endif // #ifndef __FUNC_C__
