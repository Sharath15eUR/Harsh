#include <stdio.h>
#include <stdlib.h>
#include "list.h"

#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

void printList(List* list){
    Node* temp = list->head;
    while(temp != NULL){
        printf("%d-->", getData(temp));
        temp = getNextNode(temp);
    }
    printf("NULL\n");
}

void insertData(List* list, int num){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = num;
    newNode->next = NULL;
    if(list->size == 0){
        list->head = newNode;
        list->tail = newNode;
    }
    else{
        (list->tail)->next = newNode;
        list->tail = newNode;
    }
    list->size++;
    printf("The list is:\n");
    printList(list);
}

#endif