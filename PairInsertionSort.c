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

int binarySearch(int a[], int item, int low, int high)
{
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (item == a[mid])
            return mid + 1;
        else if (item > a[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }

    return low;
}

void insertionSort(int a[], int n)
{
    int i, loc, j, k, selected;

    for (i = 1; i < n; ++i) {
        j = i - 1;
        selected = a[i];

        loc = binarySearch(a, selected, 0, j);

        while (j >= loc) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = selected;
    }
}