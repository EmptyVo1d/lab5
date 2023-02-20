#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MyLibrary.h"

char *brand() {
    const char alf[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ- ";
    int len = 1 + rand() % (13) + 3;
    char *str = calloc((len + 1), sizeof(char));
    for (int i = 0; i < len; i++) {
        int flag = rand() % (int) (sizeof alf - 1);
        str[i] = alf[flag];
    }
    str[len] = '\0';
    return str;
}

char *name() {
    const char alf[] = "abcdefghijklmnopqrstuvwxyz";
    const char ALF[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *str = malloc(100 * sizeof(char));
    char *temp;
    int len = 0;
    for (int i = 0; i < 3; i++) {
        len = rand() % (10) + 3;
        temp = malloc((len + 1) * sizeof(char));
        if (len) {
            for (int n = 0; n < len; n++) {
                if(n != 0) {
                    int col = rand() % (int) (sizeof alf - 1);
                    temp[n] = alf[col];
                }
                else {
                    int col = rand() % (int) (sizeof ALF - 1);
                    temp[n] = ALF[col];
                }
            }
            temp[len] = '\0';
            if (i != 0) str = strcat(str, " ");
            else {
                str = strcpy(str, temp);
                if (temp != NULL) free(temp);
                continue;
            }
            str = strcat(str, temp);
        }
        if (temp != NULL) free(temp);
    }
    return str;
}

double mileage() {
    double mileage = rand() * rand() / 10000 + (float) rand() / (float) (RAND_MAX / 100);
    return mileage;
}

FILE *createFile(char *fileIN) {
    FILE *Fin = NULL;
    int sizeI = rand() % 100;
    if (sizeI) {
        Fin = fopen(fileIN, "w+");
        if (Fin == NULL) {
            printf("error");
            return NULL;
        }
        for (int n = 0; n < sizeI; n++) {
            char *b = brand();
            char *na = name();
            fprintf(Fin, "%s\n%s\n%.4lf\n", b, na, mileage());
            if(b != NULL) free(b);
            if(na != NULL) free(na);
        }
        fclose(Fin);
    }
    return Fin;
}