#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(){
    List* list = (List*)malloc(sizeof(List));
    initList(list);
    int n;
    printf("Enter elements to insert:\n");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int x;
        printf("Enter element:");
        scanf("%d", &x);
        insertData(list, x);
    }
    printList(list);
    free(list);
    return 0;
}