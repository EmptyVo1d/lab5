#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "MyLibrary.h"

void swap(car *x, car *y) {
    car temp = *x;
    *x = *y;
    *y = temp;
}
int comparator1(const void* x, const void* y, char *field, char *line){
    if((strcmp(field, "mileage") == 0) && (strcmp(line, "up")==0)){
        {
            const struct car* k = (const struct car*)x;
            const struct car* m = (const struct car*)y;
            return (int)((k -> mileage) - (m -> mileage));
        }
    }
    if((strcmp(field, "mileage") == 0) && (strcmp(line, "down")==0)) {
        {
            const struct car *k = (const struct car *) x;
            const struct car *m = (const struct car *) y;
            return (int) ((m->mileage) - (k->mileage));
        }
    }
    if((strcmp(field, "brand") == 0) && (strcmp(line, "up")==0)) {
        {
            const struct car* k = (const struct car*)x;
            const struct car* m = (const struct car*)y;
            return strcmp(k->brand, m->brand);
        }
    }
    if((strcmp(field, "brand") == 0) && (strcmp(line, "down")==0)) {
        {
            const struct car* k = (const struct car*)x;
            const struct car* m = (const struct car*)y;
            return strcmp(m->brand, k->brand);
        }
    }
    if((strcmp(field, "name") == 0) && (strcmp(line, "up")==0)) {
        {
            const struct car *k = (const struct car *) x;
            const struct car *m = (const struct car *) y;
            return (int) ((k->name) - (m->name));
        }
    }
    if((strcmp(field, "name") == 0) && (strcmp(line, "down")==0)) {
        {
            const struct car *k = (const struct car *) x;
            const struct car *m = (const struct car *) y;
            return (int) ((m->name) - (k->name));
        }
    }
    return 0;
}
void AlgShaker(char *field, char *line, car *arr, int col){
    int left, right;
    left = 1;
    right = col - 1;
    while (left <= right) {
        for (int i = right; i >= left; --i)
            if (comparator1(arr + i - 1, arr + i, field, line) > 0)
                swap(arr + i - 1, arr + i);
        left++;
        for (int i = left; i <= right; ++i)
            if (comparator1(arr + i - 1, arr + i, field, line) > 0)
                swap(arr + i - 1, arr + i);
        right--;
    }
}