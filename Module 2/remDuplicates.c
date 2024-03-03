#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void removeDuplicates(List* list){
    if(!isEmpty(list)){
        printf("List is empty\n");
        return;
    }
    printf("Removing duplicates..\n");
    Node* current = *(list->head);
    Node* adjacentNext;
    while (current->next != NULL){
        if (getData(current) == getData(current->next)){
           adjacentNext = current->next->next;
           free(current->next);
           current->next = adjacentNext;  
       }
       else{
        current = current->next;
       }
    }
    printList(list);
}

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
    removeDuplicates(list);
    clearList(list);
    return 0;
}