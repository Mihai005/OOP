#pragma once

typedef struct
{
    char* name;
    int price;
    int quantity;
    int concentration;
}Medicine;

char* get_name(Medicine* medicine);
int get_price(Medicine* medicine);
int get_quantity(Medicine* medicine);
int get_concentration(Medicine* medicine);
void set_name(Medicine* medicine, char* new_name);
void set_price(Medicine* medicine, int new_price);
void set_quantity(Medicine* medicine, int new_quantity);
void set_concentration(Medicine* medicine, int new_concentration);