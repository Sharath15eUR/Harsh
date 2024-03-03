#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// Assuming it is a sorted list
void remDups(List* list) {
    Node* current = *(list->head);
    if (list->size == 0){
        printf("List is empty!!!");
        return;
    }
    printf("The duplicates are being removed...\n");
    while (current->next != NULL) {
        if (getData(current) == getData(current->next)) {
            Node* nextAdjacent = current->next->next;
            free(current->next);
            current->next = nextAdjacent;
        } else {
            current = current->next;
        }
    }
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
    remDups(list);
    printList(list);
    free(list);
    fflush(stdout);
    return 0;
}