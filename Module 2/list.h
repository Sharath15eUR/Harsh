#include "node.h"

struct list{
    Node** head;
    int size;
};

struct dlist{
    DNode** head;
    DNode** tail;
    int size;
};

typedef struct list List;
typedef struct dlist DList;

int isEmpty(List* list);
void initList(List* list);
void insertData(List* list, int num);
void printList(List* list);
void clearList(List* list);