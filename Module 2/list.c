#include <stdio.h>
#include <stdlib.h>
#include "list.h"

#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

void initList(List* list){
    list->head = (Node**)malloc(sizeof(Node*));
    if (list->head == NULL) {
        fprintf(stderr, "Memory allocation failed for head pointer.\n");
        exit(EXIT_FAILURE);
    }
    *(list->head) = NULL;
    list->size = 0;
}

int isEmpty(List* list){
    if(list->size == 0){
        return 0;
    }
    return 1;
}

void printList(List* list){
    Node* temp = *(list->head);
    while(temp != NULL){
        printf("%d-->", getData(temp));
        temp = temp->next;
    }
    printf("NULL\n");
}

void insertData(List* list, int num){
    Node* newNode = (Node*)malloc(sizeof(Node));
    initNode(newNode, num);
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
}

void clearList(List* list){
    printf("Deleting list from memory....\n");
    Node* start = *(list->head);
    while(start->next != NULL){
        Node* adjacent = start->next;
        printf("Cleared %d\n", getData(start));
        free(start);
        start = adjacent;
    }
    printf("Cleared %d\n", getData(start));
    free(start);
    list->head = NULL;
    list->size = 0;
}

#endif