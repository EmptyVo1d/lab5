#include <stdio.h>
#include <stdlib.h>
#include "Create.h"

FILE *outList(list *lst, char *fileOUT){
    FILE *out = NULL;
    if ((out = fopen(fileOUT, "w+")) == NULL) {
        printf("Couldn't open file");
        exit(1);
    }
    data *s = lst->head;
    if (lst->count == 0) {
        fprintf(out, "empty list\n");
        return 0;
    }
    while (s != NULL) {
        fprintf(out, "==========\n");
        fprintf(out, "brand: %s\n", (char*)s->brand);
        fprintf(out, "name: %s\n", (char*)s->name);
        fprintf(out, "mileage: %lf\n", s->mileage);
        s = s->next;
    }
    fprintf(out, "col: %d\n", lst->count);
    fclose(out);
    return out;
}