#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MyLibrary.h"
#define DELIM ","
void completionStruct(char *Pstring, car *arr, int col){
    char *end = "";
    arr[col].brand = strtok(Pstring, DELIM);
    arr[col].name = strtok(NULL, DELIM);
    arr[col].mileage = strtod(strtok(NULL, "\n"), &end);
}
