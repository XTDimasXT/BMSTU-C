#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define STR_LEN 256
#define STR_LEN_MAX 300

#define STR_INPUT_ERROR 1
#define STR_LENGTH_ERROR 2


char *remove_spaces(char str[], char delimiters[])
{
	char *start = str + strspn(str, delimiters);
	if (strlen(start) == 0)
		return NULL;
	char *end = strpbrk(start, delimiters);
	*end = '\0';
	return start;
}

void symb_append(char str[], char symb)
{
	size_t i = 0;
	for (; str[i] != '\0';)
		i++;
	str[i] = symb;
	str[i + 1] = '\0';
}

int check_part(char temp_str[], size_t *i)
{
	char part[STR_LEN + 1];
	char *digits = "1234567890";
	part[0] = '\0';
	for (; temp_str[(*i)] != '.'; (*i)++)
	{
		if (strchr(digits, temp_str[*i]) == NULL)
			return 0;
		if (temp_str[*i] == '\0')
			return 0;
		symb_append(part, temp_str[*i]);
	}
	if (part[0] == '\0')
		return 0;
	int num = atoi(part);
	if (strlen(part) > 3 || num > 255)
		return 0;
	(*i)++;
	return 1;
}

int check_last_part(char temp_str[], size_t *i)
{
	char part[STR_LEN + 1];
	char *digits = "1234567890";
	part[0] = '\0';
	for (; temp_str[*i] != '\0'; (*i)++)
	{
		if (strchr(digits, temp_str[*i]) == NULL)
			return 0;
		if (temp_str[*i] == '.')
			return 0;
		symb_append(part, temp_str[*i]);
	}
	if (part[0] == '\0')
		return 0;
	int num = atoi(part);
	if (strlen(part) > 3 || num > 255)
		return 0;
	return 1;
}
	
int is_ip(char str[])
{
	char temp_str[STR_LEN + 2];
	size_t i = 0;
	
	temp_str[0] = '\0';
	strcpy(temp_str, str);
	int part1 = check_part(temp_str, &i);
	int part2 = check_part(temp_str, &i);
	int part3 = check_part(temp_str, &i);
	int part4 = check_last_part(temp_str, &i);
	return part1 && part2 && part3 && part4;
}

int main(void)
{
	char str[STR_LEN_MAX];
	char delimiters[] = " \n\t\r\v\f	";
	int result;
	
	if (fgets(str, STR_LEN_MAX, stdin) == NULL)
		return STR_INPUT_ERROR;
	if (strlen(str) > STR_LEN)
		return STR_LENGTH_ERROR;
	
	char *stripped = remove_spaces(str, delimiters);
	if (stripped == NULL)
	{
		printf("NO\n");
		return EXIT_SUCCESS;
	}
	result = is_ip(stripped);
	if (result == 1)
		printf("YES\n");
	else
		printf("NO\n");
	return EXIT_SUCCESS;
}
