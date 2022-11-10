#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *my_strpbrk(char *s, char *s2)
{
	for (size_t i = 0; s[i] != '\0'; i++)
		for (size_t j = 0; s2[j] != '\0'; j++)
			if (s[i] == s2[j])
				return s + i;
	return NULL;
}

size_t my_strspn(char *s, char *s2)
{
	size_t k = 0;
	int flag = 1;
	for (size_t i = 0; s[i] != '\0'; i++)
	{
		flag = 0;
		for (size_t j = 0; s2[j] != '\0'; j++)
			if (s[i] == s2[j])
			{
				flag = 1;
				break;
			}
		if (flag == 0)
			break;
		k++;
	}
	return k;
}

size_t my_strcspn(char *s, char *s2)
{
	size_t k = 0;
	for (size_t i = 0; s[i] != '\0'; i++)
	{
		for (size_t j = 0; s2[j] != '\0'; j++)
			if (s[i] == s2[j])
				return k;
		k++;
	}
	return k;
}

char *my_strchr(char *s, int ch)
{
	size_t i;
	for (i = 0; s[i] != '\0'; i++)
		if (s[i] == ch)
			return s + i;
	if (s[i] == ch)
		return s + i;
	return NULL;
}

char *my_strrchr(char *s, int ch)
{
	size_t i;
	char *temp = NULL;
	for (i = 0; s[i] != '\0'; i++)
		if (s[i] == ch)
			temp = s + i;
	if (s[i] == ch)
		temp = s + i;
	return temp;
}

int strpbrk_tests()
{
	int failed_tests = 0;
	char *s1 = "0123456789";
	char *s2 = "378";
	char *s3 = "miluokilost";
	char *s4 = "gw";
	if (my_strpbrk(s1, s2) != strpbrk(s1, s2))
		failed_tests++;
	if (my_strpbrk(s2, s1) != strpbrk(s2, s1))
		failed_tests++;
	if (my_strpbrk(s3, s4) != strpbrk(s3, s4))
		failed_tests++;
	if (my_strpbrk(s4, s3) != strpbrk(s4, s3))
		failed_tests++;
	return failed_tests;
}

int strspn_tests()
{
	int failed_tests = 0;
	char *s1 = "0123456789";
	char *s2 = "201";
	char *s3 = "sfir3eedkffelfrre";
	char *s4 = "ifsr";
	if (my_strspn(s1, s2) != strspn(s1, s2))
		failed_tests++;
	if (my_strspn(s2, s1) != strspn(s2, s1))
		failed_tests++;
	if (my_strspn(s3, s4) != strspn(s3, s4))
		failed_tests++;
	if (my_strspn(s4, s3) != strspn(s4, s3))
		failed_tests++;
	return failed_tests;
}

int strcspn_tests()
{
	int failed_tests = 0;
	char *s1 = "0123456789";
	char *s2 = "7698";
	char *s3 = "pythonchik";
	char *s4 = "kich";
	if (my_strcspn(s1, s2) != strcspn(s1, s2))
		failed_tests++;
	if (my_strcspn(s2, s1) != strcspn(s2, s1))
		failed_tests++;
	if (my_strcspn(s3, s4) != strcspn(s3, s4))
		failed_tests++;
	if (my_strcspn(s4, s3) != strcspn(s4, s3))
		failed_tests++;
	return failed_tests;
}

int strchr_tests()
{
	int failed_tests = 0;
	char *s1 = "0123456789";
	char ch1 = '4';
	char *s2 = "01234";
	char ch2 = '7';
	char *s3 = "navinavinavi";
	char ch3 = 'a';
	if (my_strchr(s1, ch1) != strchr(s1, ch1))
		failed_tests++;
	if (my_strchr(s2, ch2) != strchr(s2, ch2))
		failed_tests++;
	if (my_strchr(s3, ch3) != strchr(s3, ch3))
		failed_tests++;
	return failed_tests;
}

int strrchr_tests()
{
	int failed_tests = 0;
	char *s1 = "0177456789";
	char ch1 = '7';
	char *s2 = "veve";
	char ch2 = 'a';
	char *s3 = "navinavinavi";
	char ch3 = 'a';
	if (my_strrchr(s1, ch1) != strrchr(s1, ch1))
		failed_tests++;
	if (my_strrchr(s2, ch2) != strrchr(s2, ch2))
		failed_tests++;
	if (my_strrchr(s3, ch3) != strrchr(s3, ch3))
		failed_tests++;
	return failed_tests;
}

int count_failed_tests()
{
	int failed_tests;
	failed_tests = strpbrk_tests();
	failed_tests += strspn_tests();
	failed_tests += strcspn_tests();
	failed_tests += strchr_tests();
	failed_tests += strrchr_tests();
	return failed_tests;
}

int main(void)
{
	int failed_tests = count_failed_tests();
	printf("%d", failed_tests);
	return failed_tests;
}
