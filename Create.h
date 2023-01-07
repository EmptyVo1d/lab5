//
// Created by evgen on 05.01.2023.
//

#ifndef LAB5_CREATE_H
#define LAB5_CREATE_H \
list *createList();
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *brand();
char *name();
double mileage();
FILE *createFile(char *fileIN);
typedef  struct data {
    char *brand;
    char *name;
    double mileage;
    struct data *next;
} data;

typedef struct list {
    int count;
    data *head;
    data *tail;
} list;
list *createList();
void completionLIst(list *lst, char *Pbrand, char *Pname, char *Pname1, char *Pname2, double PFmileage);
void Qsort(list *lst,int col, char *field, char *line);
FILE *outList(list *lst, char *fileOUT);
#endif //LAB5_CREATE_H
