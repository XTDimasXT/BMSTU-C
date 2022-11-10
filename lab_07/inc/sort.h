#ifndef __SORT_H__
#define __SORT_H__

#include <stdio.h>
#include <stdlib.h>

int compare(const void *arg1, const void *arg2);
void mysort(void *beg, size_t num, size_t size, int (*compare)(const void *, const void *));
void swap(char *elem1, char *elem2, size_t size);

#endif // __SORT_H__