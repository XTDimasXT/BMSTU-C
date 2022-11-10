#include "../inc/sort.h"

void mysort(void *beg, size_t num, size_t size, int (*compare)(const void *, const void *))
{
    char *p_beg = beg;
    char *p_end = p_beg + size * (num - 1);

    for (char *temp1 = p_beg; temp1 < p_end; temp1 += size)
    {
        for (char *temp2 = p_beg; temp2 < (p_end - (temp1 - p_beg)); temp2 += size)
        {
            if (compare(temp2, temp2 + size) > 0)
                swap(temp2, temp2 + size, size);
        }
    }
}

int compare(const void *arg1, const void *arg2)
{
    return *((int*) arg1) - *((int*) arg2);
}

void swap(char *elem1, char *elem2, size_t size)
{
    char temp;
    while (size > 0)
    {
        temp = *elem1;
        *elem1 = *elem2;
        *elem2 = temp;
        elem1++;
        elem2++;
        size--;
    }
}