#include "node.h"

struct list{
    struct node* head;
    struct node* tail;
    int size;
};

typedef struct list List;
void insertData(List* list, int num);
void printList(List* list);