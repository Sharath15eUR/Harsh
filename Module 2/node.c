#include "node.h"

#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

int getData(Node* node){
    return node->data;
}
Node* getNextNode(Node* node){
    return node->next;
}

#endif