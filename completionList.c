#include "Create.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void completionLIst(list *lst, char *Pbrand, char *Pname, char *Pname1, char *Pname2, double PFmileage){
    int col1 = strlen(Pname);
    int col2 = strlen(Pname1);
    int col3 = strlen(Pname2);
    int col = col1 + col2 + col3;
    char *Name = calloc(col+3, sizeof(char ));
    strcat(Name, Pname);
    strcat(Name, " ");
    strcat(Name, Pname1);
    strcat(Name, " ");
    strcat(Name, Pname2);
    strcat(Name, "\0");
    data *s = lst->head;
    data *news = (data*) malloc(sizeof(data));
    news->brand = malloc(sizeof(char) * (strlen(Pbrand) + 1));
    strcpy(news->brand, Pbrand);
    news->name = malloc(col * sizeof(char));
    strcpy(news->name, Name);
    news->mileage = PFmileage;
    if (s == NULL) {
        news->next = NULL;
        lst->head = news;
        lst->tail = news;
        lst->count++;
        return;
    }
    s = lst->tail;
    s->next = news;
    news->next = NULL;
    lst->tail = news;
    lst->count++;
}
