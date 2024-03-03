#include <stdio.h>
#include "node.h"

#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

void initNode(Node* node, int data){
    node->data = data;
    node->next = NULL;
}

int getData(Node* node){
    return node->data;
}

int getDataD(DNode* node){
    return node->data;
}

#endif