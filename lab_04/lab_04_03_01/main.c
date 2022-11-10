#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define WORD_LEN 16
#define STR_LEN 256
#define STR_LEN_MAX 300

#define STR_INPUT_ERROR 1
#define STR_LENGTH_ERROR 2
#define WORD_LENGTH_ERROR 3
#define RESULT_LENGTH_ERROR 4

size_t str_split(char str[], char delimiters[], char array_words[][WORD_LEN + 1])
{
	size_t arr_len = 0;
	char *word;
	
	word = strtok(str, delimiters);
	if (word == NULL)
		return arr_len;
	if (strlen(word) > WORD_LEN)
		return SIZE_MAX;
	strcpy(array_words[arr_len], word);
	arr_len++;
	word = strtok(NULL, delimiters);
	while (word != NULL)
	{
		if (strlen(word) > WORD_LEN)
			return SIZE_MAX;
		strcpy(array_words[arr_len], word);
		arr_len++;
		word = strtok(NULL, delimiters);
	}
	return arr_len;
}

void search_unique_symbols(char str[], char str2[])
{
	size_t len_str2 = 0;
	for (size_t i = 0; str[i] != '\0'; i++)
		if (str + i == strchr(str, str[i]))
		{
			str2[len_str2] = str[i];
			len_str2++;
		}
	str2[len_str2] = '\0';
}

void get_result(char array_words[][WORD_LEN + 1], size_t len, char tmp_str[])
{
	char *splitter = " ";
	char result[WORD_LEN + 1];
	tmp_str[0] = '\0';
	for (size_t i = len - 1; i > 0; i--)
		if (strcmp(array_words[i - 1], array_words[len - 1]) != 0)
		{ 
			search_unique_symbols(array_words[i - 1], result);
			strcat(tmp_str, result);
			strcat(tmp_str, splitter);
		}
	tmp_str[strlen(tmp_str) - 1] = '\0';
}
	

int main(void)
{
	char str[STR_LEN_MAX];
	char delimiters[] = " ,;:-.!?\n";
	size_t arr_len;
	char array_words[STR_LEN + 1][WORD_LEN + 1];
	char result[WORD_LEN + 1];
	
	if (fgets(str, STR_LEN_MAX, stdin) == NULL)
		return STR_INPUT_ERROR;
	if (strlen(str) > STR_LEN)
		return STR_LENGTH_ERROR;
		
	arr_len = str_split(str, delimiters, array_words);
	if (arr_len == 0 || arr_len == 1)
		return STR_INPUT_ERROR;
	if (arr_len == SIZE_MAX)
		return WORD_LENGTH_ERROR;
	
	get_result(array_words, arr_len, result);
	if (strlen(result) == 0)
		return RESULT_LENGTH_ERROR;
	printf("Result: %s\n", result);
	return EXIT_SUCCESS;
}
