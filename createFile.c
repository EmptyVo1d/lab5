//
// Created by evgen on 03.01.2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Create.h"
char *brand() {
    const char alf[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ- ";
    size_t size = rand() % (13) + 3;
    char *str = calloc((size + 1), sizeof(char));
    for (int i = 0; i < size; i++) {
        int flag = rand() % (int) (sizeof alf);
        str[i] = alf[flag];
    }
    str[size] = '\0';
    return str;
}

char *name() {
    const char alf1[] = "abcdefghijklmnopqrstuvwxyz";
    const char alf2[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *str = calloc(1,sizeof(char));
    int flag = 0;
    int point = 1;
    for (int i = 0; i < 3; i++){
        size_t size = rand() % (10) + 1;
        point = point + size;
        char *name1 = calloc(size+1, sizeof(char));
        for (int j = 0; j < size; j++) {
            if (i == 0) {
                flag = rand() % (int) (sizeof alf2 - 1);
                name1[j] = alf2[flag];
            } else flag = rand() % (int) (sizeof alf1 - 1);
            name1[j] = alf1[flag];
        }
        str = realloc(str, (point) * sizeof(char));
        str = strcat(str, name1);
        if (i != 2) {
            point++;
            str = realloc(str, (point) * sizeof(char));
            str = strcat(str, " ");
        }
        if(i == 2) str[point] = '\0';
        if(name1 != NULL) free(name1);
    }
    return str;
}

double mileage(){
    double mileage = rand()*rand()/10000+(float)rand()/(float)(RAND_MAX/100);
    return mileage;
}

FILE *createFile(char *fileIN){
    FILE *Fin = NULL;
    int sizeI = rand() % 100;
    if (sizeI) {
        Fin = fopen(fileIN, "w+");
        if (Fin == NULL) {
            printf("error");
            return NULL;
        }
        for (int n = 0; n < sizeI; n++) {
            fprintf(Fin, "==========\nbrand: %s\nname: %s\nmileage: %lf\n", brand(), name(), mileage());
        }
        fclose(Fin);
    }
    return Fin;
}