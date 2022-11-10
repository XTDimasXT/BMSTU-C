#include "func.h"
 
int scan_info(student_t *student)
{
	if (scanf("%s", student->surname) != 1)
		return SCAN_FAILURE;
	if (scanf("%s", student->name) != 1)
		return SCAN_FAILURE;
	for (size_t i = 0; i < MARK_LEN; i++)
		if (scanf("%"SCNu32, &student->marks[i]) != 1)
			return SCAN_FAILURE;
	return EXIT_SUCCESS;
}

int sort_students_by_surname(FILE *f)
{
	student_t student, min_student;
	long int i, j, ind_min;
	long int file_size;
	if (size_file(f, &file_size) != 0)
		return SIZE_ERROR;
	for (i = 0; i < file_size - 1; i++)
	{
		ind_min = i;
		get_student_by_pos(f, &min_student, ind_min);
		for (j = i + 1; j < file_size; j++)
		{
			get_student_by_pos(f, &student, j);
			if (strcmp(student.surname, min_student.surname) < 0)
			{
				ind_min = j;
				min_student = student;
			}
			else if (strcmp(student.surname, min_student.surname) == 0)
			{
				if (strcmp(student.name, min_student.name) < 0)
				{
					ind_min = j;
					min_student = student;
				}
			}
		}
		get_student_by_pos(f, &student, i);
		put_student_by_pos(f, &student, ind_min);
		put_student_by_pos(f, &min_student, i);
	}
	return EXIT_SUCCESS;		
}

long int size_file(FILE *f, long int *file_size)
{
	if (fseek(f, 0, SEEK_END) != 0)
		return FSEEK_ERROR;
	long int cur_pos = ftell(f);
	if (cur_pos == -1 || cur_pos == 0 || cur_pos % (long int) sizeof(student_t) != 0)
		return FTELL_ERROR;
	*file_size = cur_pos / (long int) sizeof(student_t);
	long int start = fseek(f, 0, SEEK_SET);
	return start;
}

double count_avg(FILE *f)
{
	long int file_size;
	double sum = 0.0;
	double avg;
	student_t student;
	if (size_file(f, &file_size) != 0)
		return SIZE_ERROR;
	for (long int i = 0; i < file_size; i++)
	{
		get_student_by_pos(f, &student, i);
		for (size_t j = 0; j < MARK_LEN; j++)
			sum += student.marks[j];
	}
	avg = sum / (double) (file_size * MARK_LEN);
	return avg;
}

double count_student_avg(FILE *f, long int i)
{
	student_t student;
	get_student_by_pos(f, &student, i);
	double sum = 0.0;
	double avg;
	for (size_t j = 0; j < MARK_LEN; j++)
		sum += student.marks[j];
	avg = sum / MARK_LEN;
	return avg;
}

int delete_students(FILE *f)
{
	student_t student;
	long int i;
	long int file_size;
	long int k = 0;
	double avg = count_avg(f);
	double avg_stud;
	if (size_file(f, &file_size) != 0)
		return SIZE_ERROR;
	for (i = 0; i < file_size; i++)
	{
		get_student_by_pos(f, &student, i);
		avg_stud = count_student_avg(f, i);
		if (avg_stud >= avg)
		{
			put_student_by_pos(f, &student, k);
			k++;
		}
	}
	ftruncate(fileno(f), (long int) sizeof(student_t) * k);
	return EXIT_SUCCESS;
}

int copy_students(FILE *f, FILE *new_f, char *substr)
{
	long int file_size;
	long int write_pos = 0;
	student_t student;
	if (size_file(f, &file_size) != 0)
		return SIZE_ERROR;
	for (long int i = 0; i < file_size; i++)
	{
		get_student_by_pos(f, &student, i);
		if (strstr(student.surname, substr) == student.surname)
		{
			put_student_by_pos(new_f, &student, write_pos);
			write_pos++;
		}
	}
	if (write_pos == 0)
		return COPY_ERROR;
	return EXIT_SUCCESS;
}

int get_student_by_pos(FILE *f, student_t *student, long int ind)
{
	if (fseek(f, (long int) sizeof(student_t) * ind, SEEK_SET) != 0)
		return FSEEK_ERROR;
	if (fread(student, sizeof(student_t), 1, f) != 1)
		return FREAD_ERROR;
	return EXIT_SUCCESS;
}

int put_student_by_pos(FILE *f, student_t *student, long int ind)
{
	if (fseek(f, (long int) sizeof(student_t) * ind, SEEK_SET) != 0)
		return FSEEK_ERROR;
	if (fwrite(student, sizeof(student_t), 1, f) != 1)
		return FWRITE_ERROR;
	return EXIT_SUCCESS;
}
