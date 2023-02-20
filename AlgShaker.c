#include <string.h>
#include "MyLibrary.h"

void swap(void* i, void* j, size_t size) {
    char* tmp = malloc(size);
    memcpy(tmp,i,size);
    memcpy(i,j,size);
    memcpy(j,tmp,size);
    free(tmp);
}

int comparatorUpMil1(const void *x, const void *y) {
    const struct car *k = (const struct car *) x;
    const struct car *m = (const struct car *) y;
    return (int) ((k->mileage) - (m->mileage));
}

int comparatorDownMil1(const void *x, const void *y) {
    const struct car *k = (const struct car *) x;
    const struct car *m = (const struct car *) y;
    return (int) ((m->mileage) - (k->mileage));
}

int comparatorUpBrand1(const void *x, const void *y) {
    const struct car *k = (const struct car *) x;
    const struct car *m = (const struct car *) y;
    return strcmp(k->brand, m->brand);
}

int comparatorDownBrand1(const void *x, const void *y) {
    const struct car *k = (const struct car *) x;
    const struct car *m = (const struct car *) y;
    return strcmp(m->brand, k->brand);
}

int comparatorUpName1(const void *x, const void *y) {
    const struct car *k = (const struct car *) x;
    const struct car *m = (const struct car *) y;
    return strcmp(k->name, m->name);
}

int comparatorDownName1(const void *x, const void *y) {
    const struct car *k = (const struct car *) x;
    const struct car *m = (const struct car *) y;
    return strcmp(m->name, k->name);
}

void AlgShakerProg(void *arr, int col, size_t size, int (*compare)(const void *, const void *)) {
    int left, right;
    left = 1;
    right = col - 1;
    while (left <= right) {
        for (int i = right; i >= left; --i)
            if (compare(arr + i - 1, arr + i) > 0)
                memcpy(arr + i - 1, arr + i, size);
        left++;
        for (int i = left; i <= right; ++i)
            if (compare(arr + i - 1, arr + i) > 0)
                memcpy(arr + i - 1, arr + i, size);
        right--;
    }
}

void AlgShaker(char *field, char *line, car *arr, int col) {
    if ((strcmp(field, "mileage") == 0) && (strcmp(line, "up") == 0))
        AlgShakerProg(arr, col, sizeof(car), comparatorUpMil1);
    if ((strcmp(field, "mileage") == 0) && (strcmp(line, "down") == 0))
        AlgShakerProg(arr, col, sizeof(car), comparatorDownMil1);
    if ((strcmp(field, "brand") == 0) && (strcmp(line, "up") == 0))
        AlgShakerProg(arr, col, sizeof(car), comparatorUpBrand1);
    if ((strcmp(field, "brand") == 0) && (strcmp(line, "down") == 0))
        AlgShakerProg(arr, col, sizeof(car), comparatorDownBrand1);
    if ((strcmp(field, "name") == 0) && (strcmp(line, "up") == 0))
        AlgShakerProg(arr, col, sizeof(car), comparatorUpName1);
    if ((strcmp(field, "name") == 0) && (strcmp(line, "down") == 0))
        AlgShakerProg(arr, col, sizeof(car), comparatorDownName1);
}
