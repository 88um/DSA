#ifndef QUEUE_H
#define QUEUE_H

#include "node.h"
#include <stdbool.h>

typedef struct Queue {
    int size;
    struct Node* front;
    struct Node* rear;
} Queue;

struct Queue* createNewQueue();
void printQueue(struct Queue* queue);
void peekQueue(struct Queue* q);
int pollQueue(struct Queue* q);
bool offerQueue(struct Queue* q, int data);
bool emptyQueue(struct Queue* q);
void freeQueue(struct Queue* queue);

#endif