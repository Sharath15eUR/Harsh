#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void sortedInsert(DList* list, int x) {
    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    initNodeD(newNode, x);
    DNode* current;
    DNode* start = *(list->head);
    if(start == NULL) {
        start = newNode;
    } 
    else if(getDataD(start) >= getDataD(newNode)) {
        newNode->next = start;
        newNode->next->prev = newNode;
        start = newNode;
    } else {
        current = start;
        while (current->next != NULL && getDataD(current->next) < getDataD(newNode)) {
            current = current->next;
        }
        newNode->next = current->next;
        if (current->next != NULL) {
            newNode->next->prev = newNode;
        }
        current->next = newNode;
        newNode->prev = current;
    }
    printListD(list);
}

int main(){
    DList* list = (DList*)malloc(sizeof(DList));
    initListD(list);
    int n;
    printf("Enter elements to insert:\n");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int x;
        printf("Enter element:");
        scanf("%d", &x);
        sortedInsert(list, x);
    }
    return 0;
}