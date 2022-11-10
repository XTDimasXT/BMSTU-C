#ifndef __PRODUCTS_C__

#define __PRODUCTS_C__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
#define ARR_LEN 15
#define NAME_LEN 26

#define ARGS_ERROR 1
#define SCAN_FAILURE 2
#define OPEN_ERROR 3
#define INCORRECT_PRICE 4

typedef struct
{
	char name[NAME_LEN];
	int price;
} product_t;

int scan_info(FILE *f, product_t *product);
int scan_file(FILE *f, int count, product_t *products);
void print_above_price(product_t *products, int count, int price);
void print_product(product_t product);

#endif // #ifndef __PRODUCTS_C__
