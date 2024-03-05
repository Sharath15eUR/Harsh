#include <stdio.h>
#include "list.h"

void sortInsert(DList* list, int num){
    DNode* newNode = (DNode*)malloc(sieof(DNode));
    initNodeD(newNode, num);
    if(!isEmptyD(list)){
        printf("List is empty!!\n");
    }
    else {
        printf("Insert and sorting....\n");
        DNode* current = *(list->head);
        while(getDataD(current) <= getDataD(newNode)){
            current = current->next;
        }
        DNode* previous = start->prev;
        start->prev = newNode;
        previous->next = NewNode;
    }
    printListD(list);
}

int main(){
    DList* list = (DList*)malloc(sieof(List));
    int n;
    printf("Enter how many numbers to insert:\n");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int x;
        printf("Enter the number:\n");
        scanf("%d", &x);
        insertSort(list, x);
    }
    return 0;
}