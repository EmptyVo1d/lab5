#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "Create.h"

int main(int argc, char *argv[]) {
    srand(time(NULL));
    int arg;
    double PFmileage;
    char *Pmileage;
    char *Pname;
    char *Pname1;
    char *Pname2;
    char *Pbrand;
    char *point;
    char *alg = malloc(81 * sizeof(char));
    char *field = malloc(81 * sizeof(char));
    char *line = malloc(81 * sizeof(char));
    char *fileIN = malloc(81 * sizeof(char));
    char *fileOUT = malloc(81 * sizeof(char));
    if(argc != 10){
        return 1;
    }
    while ((arg = getopt(argc, argv, "z:x:c:")) && arg!= -1) {
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
    list *lst = createList();
    in = fopen(fileIN, "a+");
    if(in == NULL){
        printf("file empty");
        return 1;
    }
    int col = sizeof(in);

    while (!feof(in)) {
        Pbrand = calloc(50, sizeof(char));
        Pname = calloc(50, sizeof(char ));
        Pname1 = calloc(50, sizeof(char ));
        Pname2 = calloc(50, sizeof(char ));
        Pmileage = calloc(100, sizeof(char ));
        PFmileage = atoi(Pmileage);
        fscanf(in, "==========\nbrand: %s\nname: %s %s %s\nmileage: %lf\n", Pbrand, Pname, Pname1, Pname2, &PFmileage);
        completionLIst(lst, Pbrand, Pname, Pname1, Pname2, PFmileage);
    }
    if (!strcmp(alg, "qsort")){
       Qsort(lst, lst->count, field, line);
    }
    FILE *out = outList(lst, fileOUT);
    return 0;
}
