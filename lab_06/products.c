#include "products.h"
 
int scan_info(FILE *f, product_t *product)
{
	char buf[NAME_LEN + 1];
	if (fgets(buf, NAME_LEN + 1, f) == NULL)
		return SCAN_FAILURE;
	if (strlen(buf) == 1 || buf[strlen(buf) - 1] != '\n')
		return SCAN_FAILURE;
	strcpy(product->name, buf);
	product->name[strlen(product->name) - 1] = '\0';
	if (fgets(buf, NAME_LEN, f) == NULL)
		return SCAN_FAILURE;
	if (sscanf(buf, "%d", &product->price) != 1)
		return SCAN_FAILURE;
	if (product->price <= 0)
		return INCORRECT_PRICE;
	return EXIT_SUCCESS;
}

int scan_file(FILE *f, int count, product_t *products)
{
	for (int i = 0; i < count; i++)
		if (scan_info(f, &products[i]) != 0)
			return SCAN_FAILURE;
	return EXIT_SUCCESS;
}

void print_above_price(product_t *products, int count, int price)
{
	for (int i = 0; i < count; i++)
		if (products[i].price < price)
			print_product(products[i]);
}

void print_product(product_t product)
{
	printf("%s\n%d\n", product.name, product.price);
}
