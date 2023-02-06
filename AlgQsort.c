#include <stdlib.h>
#include <string.h>
#include "MyLibrary.h"
int comparatorUpMil(const void* x, const void* y){
    const struct car* k = (const struct car*)x;
    const struct car* m = (const struct car*)y;
    return (int)((k -> mileage) - (m -> mileage));
}
int comparatorDownMil(const void* x, const void* y){
    const struct car* k = (const struct car*)x;
    const struct car* m = (const struct car*)y;
    return (int)((m -> mileage) - (k -> mileage));
}
int comparatorUpBrand(const void* x, const void* y){
    const struct car *k = (const struct car *) x;
    const struct car *m = (const struct car *) y;
    return strcmp(k->brand, m->brand);
}
int comparatorDownBrand(const void* x, const void* y){
    const struct car* k = (const struct car*)x;
    const struct car* m = (const struct car*)y;
    return strcmp(m->brand, k->brand);
}
int comparatorUpName(const void* x, const void* y){
    const struct car* k = (const struct car*)x;
    const struct car* m = (const struct car*)y;
    return strcmp(k->name, m->name);
}
int comparatorDownName(const void* x, const void* y){
    const struct car* k = (const struct car*)x;
    const struct car* m = (const struct car*)y;
    return strcmp(m->name, k->name);
}

void AlgQsort(char *field, char *line, car *arr, int col){
    if((strcmp(field, "mileage") == 0) && (strcmp(line, "up")==0))qsort(arr, col, sizeof(car),comparatorUpMil);
    if((strcmp(field, "mileage") == 0) && (strcmp(line, "down") == 0)) qsort(arr, col, sizeof(car),comparatorDownMil);
    if((strcmp(field, "brand") == 0) && (strcmp(line, "up")==0)) qsort(arr, col, sizeof(car),comparatorUpBrand);
    if((strcmp(field, "brand")==0) && (strcmp(line, "down")==0)) qsort(arr, col, sizeof(car),comparatorDownBrand);
    if((strcmp(field, "name")==0) && (strcmp(line, "up")==0)) qsort(arr, col, sizeof(car),comparatorUpName);
    if((strcmp(field, "name")==0) && (strcmp(line, "down")==0)) qsort(arr, col, sizeof(car),comparatorDownName);
}