#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(){
    List* list = (List*)malloc(sizeof(List));
    list->head = NULL;
    list->size = 0;
    insertData(list, 1);
    insertData(list, 2);
    insertData(list, 2);
    insertData(list, 3);
    insertData(list, 4);
    free(list);
    return 0;
}