//
// Created by evgen on 05.01.2023.
//

#ifndef LAB5_MYLIBRARY_H
#define LAB5_MYLIBRARY_H \
list *createList();

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *brand();

char *name();

double mileage();

FILE *createFile(char *fileIN);

typedef struct car {
    char *brand;
    char *name;
    double mileage;
} car;

void AlgQsort(char *field, char *line, car *arr, int col);

void AlgShaker(char *field, char *line, car *arr, int col);

void PairInsertionSort(char *field, char *line, car *arr, int col);

void completionStruct(char *Pstring, car *arr, int col);

#endif //LAB5_MYLIBRARY_H