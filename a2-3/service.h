#pragma once
#include "Domain.h"
#include "DynamicArray.h"

void printMenu();
int deleteMedicine(DynamicArray* MedicineList, char* name, int concentration);
int addMedicine(DynamicArray* MedicineList, char* name, int concentration, int quantity, int price);
void clear_input_buffer();
int updateMedicineName(char* name, int concentration, char* new_name, DynamicArray* MedicineList);
int updateMedicineConcentration(char* name, int concentration, int new_concentration, DynamicArray* MedicineList);
int updateMedicineQuantity(char* name, int concentration, int new_quantity, DynamicArray* MedicineList);
int updateMedicinePrice(char* name, int concentration, int new_price, DynamicArray* MedicineList);
void searchMedicineByName(DynamicArray* MedicineList, char* name, DynamicArray* searchList);
void sortMedicineListByName(DynamicArray* searchList);
void searchMedicineBySupply(DynamicArray* MedicineList, int supply, DynamicArray* searchList);
