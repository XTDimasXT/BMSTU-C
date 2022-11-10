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

size_t str_split(char str[], char delimiters[], char array_words[][WORD_LEN + 1])
{
	size_t arr_len = 0;
	size_t word_len = 0;
	char word[WORD_LEN + 1];
	for (size_t i = 0; str[i] != '\0'; i++)
		if (strchr(delimiters, str[i]) == NULL)
		{
			if (word_len + 1 > WORD_LEN)
				return SIZE_MAX;
			word[word_len] = str[i];
			word_len++;
		}
		else if (word_len > 0)
		{
			word[word_len] = '\0';
			int flag = 0;
			for (size_t j = 0; j < arr_len; j++)
				if (strcmp(word, array_words[j]) == 0)
				{
					flag = 1;
					break;
				}
			if (flag == 0)
			{
				strcpy(array_words[arr_len], word);
				arr_len++;
			}
			word_len = 0;
		}
	return arr_len;
}

void sort_dict_order(char array_words[][WORD_LEN + 1], size_t len)
{
	char temp[WORD_LEN + 1];
	for (size_t i = 0; i < len; i++)
		for (size_t j = i + 1; j < len; j++)
			if (strcmp(array_words[i], array_words[j]) > 0)
			{
				strcpy(temp, array_words[i]);
				strcpy(array_words[i], array_words[j]);
				strcpy(array_words[j], temp);
			}
}

void arr_output(char array_words[][WORD_LEN + 1], size_t len)
{
	for (size_t i = 0; i < len; i++)
		printf("%s ", array_words[i]);
}


int main(void)
{
	char str[STR_LEN_MAX];
	char delimiters[] = " ,;:-.!?\n";
	size_t arr_len;
	char array_words[STR_LEN + 1][WORD_LEN + 1];
	
	if (fgets(str, STR_LEN_MAX, stdin) == NULL)
		return STR_INPUT_ERROR;
	if (strlen(str) > STR_LEN)
		return STR_LENGTH_ERROR;
	arr_len = str_split(str, delimiters, array_words);
	if (arr_len == SIZE_MAX)
		return WORD_LENGTH_ERROR;
	if (arr_len == 0)
		return STR_LENGTH_ERROR;
		
	sort_dict_order(array_words, arr_len);
	printf("Result: ");
	arr_output(array_words, arr_len);
	return EXIT_SUCCESS;
}
