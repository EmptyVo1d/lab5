#include <string.h>
#include "MyLibrary.h"

int comparator(const void *x, const void *y, char *field, char *line) {
    if ((strcmp(field, "mileage") == 0) && (strcmp(line, "up") == 0)) {
        {
            const struct car *k = (const struct car *) x;
            const struct car *m = (const struct car *) y;
            return (int) ((k->mileage) - (m->mileage));
        }
    }
    if ((strcmp(field, "mileage") == 0) && (strcmp(line, "down") == 0)) {
        {
            const struct car *k = (const struct car *) x;
            const struct car *m = (const struct car *) y;
            return (int) ((m->mileage) - (k->mileage));
        }
    }
    if ((strcmp(field, "brand") == 0) && (strcmp(line, "up") == 0)) {
        {
            const struct car *k = (const struct car *) x;
            const struct car *m = (const struct car *) y;
            return strcmp(k->brand, m->brand);
        }
    }
    if ((strcmp(field, "brand") == 0) && (strcmp(line, "down") == 0)) {
        {
            const struct car *k = (const struct car *) x;
            const struct car *m = (const struct car *) y;
            return strcmp(m->brand, k->brand);
        }
    }
    if ((strcmp(field, "name") == 0) && (strcmp(line, "up") == 0)) {
        {
            const struct car *k = (const struct car *) x;
            const struct car *m = (const struct car *) y;
            return (int) ((k->name) - (m->name));
        }
    }
    if ((strcmp(field, "name") == 0) && (strcmp(line, "down") == 0)) {
        {
            const struct car *k = (const struct car *) x;
            const struct car *m = (const struct car *) y;
            return (int) ((m->name) - (k->name));
        }
    }
    return 0;
}

int binarySearchName(car *arr, int i, int low, int high, char *line)
{
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (comparator(arr + i, arr + mid, "name", line)==0)
            return mid + 1;
        else if (comparator(arr + i, arr + mid, "name", line) > 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}
int binarySearchMileage(car *arr, int i, int low, int high, char *line)
{
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (comparator(arr + i, arr + mid, "mileage", line)==0)
            return mid + 1;
        else if (comparator(arr + i, arr + mid, "mileage", line) > 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

int binarySearchBrand(car *arr, int i, int low, int high, char *line)
{
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (comparator(arr + i, arr + mid, "brand", line)==0)
            return mid + 1;
        else if (comparator(arr + i, arr + mid, "brand", line) > 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

void PairInsertionSort(char *field, char *line, car *arr, int col){
    int loc, j;
    if(strcmp(field, "name") == 0) {
        char *el;
        for (int i = 1; i < col; ++i) {
            j = i - 1;
            el = arr[i].name;
            loc = binarySearchName(arr, i, 0, j, line);
            while (j >= loc) {
                arr[j + 1].name = arr[j].name;
                j--;
            }
            arr[j + 1].name = el;
        }
    }
    if(strcmp(field, "mileage") == 0) {
        double el;
        for (int i = 1; i < col; ++i) {
            j = i - 1;
            el = arr[i].mileage;
            loc = binarySearchMileage(arr, i, 0, j, line);
            while (j >= loc) {
                arr[j + 1].mileage = arr[j].mileage;
                j--;
            }
            arr[j + 1].mileage = el;
        }
    }
    if(strcmp(field, "brand") == 0) {
        char *el;
        for (int i = 1; i < col; ++i) {
            j = i - 1;
            el = arr[i].brand;
            loc = binarySearchName(arr, i, 0, j, line);
            while (j >= loc) {
                arr[j + 1].brand = arr[j].brand;
                j--;
            }
            arr[j + 1].brand = el;
        }
    }
}