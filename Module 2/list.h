#include "node.h"

struct list{
    struct node** head;
    int size;
};

typedef struct list List;
void initList(List* list);
void insertData(List* list, int num);
void printList(List* list);