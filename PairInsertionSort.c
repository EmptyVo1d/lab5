#include <string.h>
#include "MyLibrary.h"

void swap1(car *x, car *y) {
    car temp = *x;
    *x = *y;
    *y = temp;
}

int comparatorUpMil2(const void *x, const void *y) {
    const struct car *k = (const struct car *) x;
    const struct car *m = (const struct car *) y;
    return (int) ((k->mileage) - (m->mileage));
}

int comparatorDownMil2(const void *x, const void *y) {
    const struct car *k = (const struct car *) x;
    const struct car *m = (const struct car *) y;
    return (int) ((m->mileage) - (k->mileage));
}

int comparatorUpBrand2(const void *x, const void *y) {
    const struct car *k = (const struct car *) x;
    const struct car *m = (const struct car *) y;
    return strcmp(k->brand, m->brand);
}

int comparatorDownBrand2(const void *x, const void *y) {
    const struct car *k = (const struct car *) x;
    const struct car *m = (const struct car *) y;
    return strcmp(m->brand, k->brand);
}

int comparatorUpName2(const void *x, const void *y) {
    const struct car *k = (const struct car *) x;
    const struct car *m = (const struct car *) y;
    return strcmp(k->name, m->name);
}

int comparatorDownName2(const void *x, const void *y) {
    const struct car *k = (const struct car *) x;
    const struct car *m = (const struct car *) y;
    return strcmp(m->name, k->name);
}

int binarySearch(void *arr, int i, int low, int high, size_t size, int (*compare)(const void *, const void *)) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (compare(arr + i*size, arr + mid*size) == 0)
            return mid + 1;
        else if (compare(arr + i*size, arr + mid*size) > 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

void PairInsertionSort(void *arr, int col, size_t size, int (*compare)(const void *, const void *)) {
    int loc, j;
    void *el = malloc(size);
    for (int i = 1; i < col; ++i) {
        j = i - 1;
        memmove(el, arr + 1, size);
        loc = binarySearch(arr, i, 0, j, size, compare);
        while (j >= loc) {
            memmove(arr + j + 1, arr + j, size);
            j--;
        }
        memmove(arr + j + 1, el, size);
    }
}

void AlgPis(char *field, char *line, car *arr, int col) {
    if ((strcmp(field, "mileage") == 0) && (strcmp(line, "up") == 0))
        PairInsertionSort(arr, col, sizeof(car), comparatorUpMil2);
    if ((strcmp(field, "mileage") == 0) && (strcmp(line, "down") == 0))
        PairInsertionSort(arr, col, sizeof(car), comparatorDownMil2);
    if ((strcmp(field, "brand") == 0) && (strcmp(line, "up") == 0))
        PairInsertionSort(arr, col, sizeof(car), comparatorUpBrand2);
    if ((strcmp(field, "brand") == 0) && (strcmp(line, "down") == 0))
        PairInsertionSort(arr, col, sizeof(car), comparatorDownBrand2);
    if ((strcmp(field, "name") == 0) && (strcmp(line, "up") == 0))
        PairInsertionSort(arr, col, sizeof(car), comparatorUpName2);
    if ((strcmp(field, "name") == 0) && (strcmp(line, "down") == 0))
        PairInsertionSort(arr, col, sizeof(car), comparatorDownName2);
}