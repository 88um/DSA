#include "node.h"
#include <stdio.h>
#include <stdlib.h>

struct Node* createNewNode(int data) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    if (n == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    n->data = data;
    n->next = NULL;
    return n;
}

