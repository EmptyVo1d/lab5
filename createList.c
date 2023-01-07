//
// Created by evgen on 05.01.2023.
//

#include "Create.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

list *createList(){
    list *lst = (list*) malloc(sizeof(list));
    lst->count = 0;
    lst->head = NULL;
    lst->tail = NULL;
    return lst;
}