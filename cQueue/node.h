#ifndef NODE_H
#define NODE_H

struct Node;

typedef void (*PrintFunction)(struct Node*);
typedef void (*AddToBeginningFunction)(struct Node**, int);
typedef void (*AddToEndFunction)(struct Node*, int);
typedef void (*FreeFunction)(struct Node*);
typedef int (*CountNodesFunction)(struct Node*);
typedef int (*InsertAtFunction)(struct Node*, int, int);

struct Node {
    int data;
    struct Node* next;
    PrintFunction printLinkedList;
    AddToBeginningFunction addToBeginning;
    AddToEndFunction addToEnd;
    FreeFunction freeList;
    CountNodesFunction countNodes;
    InsertAtFunction insertAt;
};

struct Node* createNewNode(int data);

#endif
