struct node{
    int data;
    struct node *next;
};

struct dnode{
    int data;
    struct dnode *next;
    struct dnode *prev;
};

typedef struct node Node;
typedef struct dnode DNode;

void initNode(Node* node, int data);
int getData(Node* node);
void initNodeD(DNode* node, int data);
int getDataD(DNode* node);