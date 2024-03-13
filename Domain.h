#pragma once

typedef struct
{
    char* name;
    int price;
    int quantity;
    int concentration;
}Medicine;

char get_name(Medicine medicine);
int get_price(Medicine medicine);
int get_quantity(Medicine medicine);
int get_concentration(Medicine medicine);