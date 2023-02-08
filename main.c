#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "MyLibrary.h"

int main(int argc, char *argv[]) {
    srand(time(NULL));
    car *arr = malloc(1 * sizeof(car));
    int arg = 0;
    char *alg = malloc(81 * sizeof(char));
    char *field = malloc(81 * sizeof(char));
    char *line = malloc(81 * sizeof(char));
    char *fileIN = malloc(81 * sizeof(char));
    char *fileOUT = malloc(81 * sizeof(char));
    int col = 0;
    if (argc != 10) {
        return 1;
    }
    while ((arg = getopt(argc, argv, "z:x:c:")) && arg != -1) {
        switch (arg) {
            case 'z':
                sscanf(optarg, "%s", alg);
                if ((strcmp(alg, "shaker")) && (strcmp(alg, "pis")) && (strcmp(alg, "qsort"))) {
                    printf("error\n");
                    return 1;
                }
                break;
            case 'x':
                sscanf(optarg, "%s", field);
                if ((strcmp(field, "brand")) && (strcmp(field, "name")) && (strcmp(field, "mileage"))) {
                    return 1;
                }
                break;
            case 'c':
                sscanf(optarg, "%s", line);
                if ((strcmp(line, "up")) && (strcmp(line, "down"))) {
                    return 1;
                }
                break;
            case '?':
                printf("error: %c\n", optopt);
                return 1;
        }
    }
    sscanf(argv[optind], "%s", fileIN);
    optind++;
    sscanf(argv[optind], "%s", fileOUT);
    FILE *in = createFile(fileIN);
    in = fopen(fileIN, "a+");
    if (in == NULL) {
        printf("file empty");
        return 1;
    }
    while (!feof(in)) {
        char *end = "";
        char *Pstring = calloc(81, sizeof(char));
        Pstring[0] = '\0';
        arr = (car *) realloc(arr, sizeof(car) * (col + 1));
        if (arr == NULL) {
            printf("Error\n");
            return 1;
        }
        fscanf(in, "%[^\n]", Pstring);
        arr[col].brand = strdup(Pstring);
        fscanf(in, "%*[\n]");
        fscanf(in, "%[^\n]", Pstring);
        fscanf(in, "%*[\n]");
        arr[col].name = strdup(Pstring);
        fscanf(in, "%[^\n]", Pstring);
        fscanf(in, "%*[\n]");
        arr[col].mileage = strtod(Pstring, &end);
        col++;
        free(Pstring);
    }
    if (strcmp(alg, "qsort") == 0) AlgQsort(field, line, arr, col);
    if (strcmp(alg, "shaker") == 0) AlgShaker(field, line, arr, col);
    if (strcmp(alg, "pis") == 0) PairInsertionSort(field, line, arr, col);
    for (int i = 0; i < col; i++)
        printf("=========\nbrand: %s\nname: %s\nmileage: %lf\n", arr[i].brand, arr[i].name, arr[i].mileage);
    fclose(in);
    free(in);
    return 0;
}
//⠄⠄⠄⢰⣧⣼⣯⠄⣸⣠⣶⣶⣦⣾⠄⠄⠄⠄⡀⠄⢀⣿⣿⠄⠄⠄⢸⡇⠄⠄
//⠄⠄⠄⣾⣿⠿⠿⠶⠿⢿⣿⣿⣿⣿⣦⣤⣄⢀⡅⢠⣾⣛⡉⠄⠄⠄⠸⢀⣿⠄
//⠄⠄⢀⡋⣡⣴⣶⣶⡀⠄⠄⠙⢿⣿⣿⣿⣿⣿⣴⣿⣿⣿⢃⣤⣄⣀⣥⣿⣿⠄
//⠄⠄⢸⣇⠻⣿⣿⣿⣧⣀⢀⣠⡌⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠿⠿⣿⣿⣿⠄
//⠄⢀⢸⣿⣷⣤⣤⣤⣬⣙⣛⢿⣿⣿⣿⣿⣿⣿⡿⣿⣿⡍⠄⠄⢀⣤⣄⠉⠋⣰
//⠄⣼⣖⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⣿⣿⣿⣿⣿⢇⣿⣿⡷⠶⠶⢿⣿⣿⠇⢀⣤
//⠘⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣽⣿⣿⣿⡇⣿⣿⣿⣿⣿⣿⣷⣶⣥⣴⣿⡗
//⢀⠈⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠄
//⢸⣿⣦⣌⣛⣻⣿⣿⣧⠙⠛⠛⡭⠅⠒⠦⠭⣭⡻⣿⣿⣿⣿⣿⣿⣿⣿⡿⠃⠄
//⠘⣿⣿⣿⣿⣿⣿⣿⣿⡆⠄⠄⠄⠄⠄⠄⠄⠄⠹⠈⢋⣽⣿⣿⣿⣿⣵⣾⠃⠄
//⠄⠘⣿⣿⣿⣿⣿⣿⣿⣿⠄⣴⣿⣶⣄⠄⣴⣶⠄⢀⣾⣿⣿⣿⣿⣿⣿⠃⠄⠄
//⠄⠄⠈⠻⣿⣿⣿⣿⣿⣿⡄⢻⣿⣿⣿⠄⣿⣿⡀⣾⣿⣿⣿⣿⣛⠛⠁⠄⠄⠄
//⠄⠄⠄⠄⠈⠛⢿⣿⣿⣿⠁⠞⢿⣿⣿⡄⢿⣿⡇⣸⣿⣿⠿⠛⠁⠄⠄⠄⠄⠄
//.⠄⠄⠄⠄⠄⠄⠉⠻⣿⣿⣾⣦⡙⠻⣷⣾⣿⠃⠿⠋⠁⠄⠄⠄⠄⠄⢀⣠⣴
//⣿⣿⣿⣶⣶⣮⣥⣒⠲⢮⣝⡿⣿⣿⡆⣿⡿⠃⠄⠄⠄⠄⠄⠄⠄⣠⣴⣿⣿⣿