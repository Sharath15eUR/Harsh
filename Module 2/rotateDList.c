#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void rotateN(DList* list, int pos){ 
    if(!isEmptyD(list)){
        printf("List is empty\n");
        return;
    }

    printf("Rotating list by %d ....\n", pos);
    if(pos == 0){
        printListD(list);
        return;
    }
    if(pos < 0){
        pos = abs(pos);
        DNode* start = *(list->head);
        DNode* end = *(list->tail);
        end->next = start;
        start->prev = end;
        int count = 1;
        while (count <= pos) {
            start = start->prev;
            end = end->prev;
            count++;
        }
    
        end->next = NULL;
        start->prev = NULL;
        *(list->head) = start;
        *(list->tail) = end;
        printListD(list);
        return;
    }
    DNode* start = *(list->head);
    DNode* end = *(list->tail);
    end->next = start;
    start->prev = end;
    int count = 1;
    while (count <= pos) {
        start = start->next;
        end = end->next;
        count++;
    }
    
    end->next = NULL;
    start->prev = NULL;
    *(list->head) = start;
    *(list->tail) = end;
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
        insertDataD(list, x);
    }
    rotateN(list, 2);
    rotateN(list, 3);
    rotateN(list, 0);
    rotateN(list, -1);
    return 0;
}