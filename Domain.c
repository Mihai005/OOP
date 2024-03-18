#include "Domain.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

/*
  Setters and getters for the Medicine struct
*/

Medicine* create_medicine(char* name, int price, int quantity, int concentration)
{
	Medicine* medicine = (Medicine*)malloc(sizeof(Medicine));
	medicine->name = (char*)malloc(sizeof(char) * (strlen(name) + 1));
	strcpy(medicine->name, name);
	medicine->price = price;
	medicine->quantity = quantity;
	medicine->concentration = concentration;
	return medicine;
}

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
	medicine->name = (char*)realloc(medicine->name, sizeof(char) * (strlen(new_name) + 1));
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

void destroy_medicine(Medicine* medicine)
{
	free(medicine->name);
	free(medicine);
}

void testdomain()
{
	Medicine* medicine = create_medicine("Paracetamol", 10, 100, 10);
	assert(strcmp(get_name(medicine), "Paracetamol") == 0);
	assert(get_price(medicine) == 10);
	assert(get_quantity(medicine) == 100);
	assert(get_concentration(medicine) == 10);

	set_name(medicine, "Nurofen");
	set_price(medicine, 20);
	set_quantity(medicine, 50);
	set_concentration(medicine, 5);

	assert(strcmp(get_name(medicine), "Nurofen") == 0);
	assert(get_price(medicine) == 20);
	assert(get_quantity(medicine) == 50);
	assert(get_concentration(medicine) == 5);

	destroy_medicine(medicine);
}
