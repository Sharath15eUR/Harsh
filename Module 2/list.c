#include <stdio.h>
#include <stdlib.h>
#include "list.h"

#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

void initList(List* list){
    *(list->head) = NULL;
    list->size = 0;
    return;
}

void printList(List* list){
    Node* temp = *(list->head);
    while(temp != NULL){
        printf("%d-->", getData(temp));
        temp = temp->next;
    }
    printf("NULL\n");
    return;
}

void insertData(List* list, int num){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = num;
    newNode->next = NULL;
    if(list->size == 0){
        *(list->head) = newNode;
    }
    else{
        Node* temp = *(list->head);
        while((temp->next) != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    list->size++;
    printf("The list is:\n");
    printList(list);
    return;
}

#endif