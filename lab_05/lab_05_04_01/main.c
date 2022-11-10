#include "func.h"

int main(int argc, char **argv)
{
	if (argc < 3)
		return ARGS_ERROR;
	if (strcmp(argv[1], "sb") == 0 && argc == 3)
	{
		FILE *f;
		long int file_size;
		student_t student;
		f = fopen(argv[2], "rb+");
		if (f == NULL)
			return OPEN_ERROR;
		if (size_file(f, &file_size) != 0)
			return SIZE_ERROR;
		sort_students_by_surname(f);
		for (long int i = 0; i < file_size; i++)
		{
			get_student_by_pos(f, &student, i);
			printf("%s\n%s\n", student.surname, student.name);
			for (long int j = 0; j < MARK_LEN; j++)
				printf("%"PRIu32" ", student.marks[j]);
			printf("\n");
		}
		fclose(f);
	}
	else if (strcmp(argv[1], "db") == 0 && argc == 3)
	{
		FILE *f;
		f = fopen(argv[2], "rb+");
		if (f == NULL)
			return OPEN_ERROR;
		int res = delete_students(f);
		fclose(f);
		if (res == SIZE_ERROR)
			return SIZE_ERROR;
	}
	else if (strcmp(argv[1], "fb") == 0 && argc == 5)
	{
		FILE *f;
		FILE *new_f;
		long int file_size;
		f = fopen(argv[2], "rb");
		if (f == NULL)
			return OPEN_ERROR;
		if (size_file(f, &file_size) != 0)
			return SIZE_ERROR;
		new_f = fopen(argv[3], "wb");
		if (strlen(argv[4]) > SURNAME_LEN - 1)
			return LEN_ERROR;
		int res = copy_students(f, new_f, argv[4]);
		fclose(f);
		fclose(new_f);
		if (res == SIZE_ERROR)
			return SIZE_ERROR;
		if (res == COPY_ERROR)
			return COPY_ERROR;
	}
	else
		return ARGS_ERROR;
	return EXIT_SUCCESS;
}
