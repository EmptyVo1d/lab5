#include "Create.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
double cmp(const void *a, const void *b) {
    return *(double *)a - *(double *)b;
}

void Qsort(list *lst,int col, char *field, char *line){
    if (!strcmp(field, "mileage")) {
        data *s = lst->head;
        double Tdata;
        data *TdataN;
        int i = 0;
        int temp[col];
        while (s != NULL){
            s->brand;
            s->name;
            s->mileage;
            s = s->next;
            i++;
        }
        if (!strcmp(line, "up"))
            qsort(s, col, sizeof(double), (int (*)(const void *, const void *)) cmp);
        else {
            qsort(s, col, sizeof(struct data), strcmp);
    }
        data *s2 = lst->head;
        int j = 0;
        while (s2 != NULL) {
            s2->brand;
            s2->name;
            s2->mileage;
            s2 = s2 ->next;
            j++;
        }
    }
}