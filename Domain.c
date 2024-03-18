#include "Domain.h"
#include <string.h>

char* get_name(Medicine* medicine)
{
	return medicine->name;
}

int get_price(Medicine* medicine)
{
	return medicine->price;
}

int get_quantity(Medicine* medicine)
{
	return medicine->quantity;
}

int get_concentration(Medicine* medicine)
{
	return medicine->concentration;
}

void set_name(Medicine* medicine, char* new_name)
{
	strcpy(medicine->name, new_name);
}

void set_price(Medicine* medicine, int new_price)
{
	medicine->price = new_price;
}

void set_quantity(Medicine* medicine, int new_quantity)
{
	medicine->quantity = new_quantity;
}

void set_concentration(Medicine* medicine, int new_concentration)
{
	medicine->concentration = new_concentration;
}
