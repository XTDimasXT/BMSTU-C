#include "products.h"

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		char temp_count[NAME_LEN];
		product_t products[ARR_LEN];
		FILE *f;
		f = fopen(argv[1], "r");
		if (f == NULL)
			return OPEN_ERROR;
		if (fgets(temp_count, NAME_LEN, f) == NULL)
		{
			fclose(f);
			return SCAN_FAILURE;
		}
		int count;
		if (sscanf(temp_count, "%d", &count) != 1 || count > ARR_LEN)
		{
			fclose(f);
			return SCAN_FAILURE;
		}
		if (scan_file(f, count, products) != 0)
		{
			fclose(f);
			return SCAN_FAILURE;
		}
		int price;
		if (sscanf(argv[2], "%d", &price) != 1 || price <= 0)
		{
			fclose(f);
			return INCORRECT_PRICE;
		}
		print_above_price(products, count, price);
		fclose(f);
	}
	else
		return ARGS_ERROR;
	return EXIT_SUCCESS;
}
