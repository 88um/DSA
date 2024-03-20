#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

struct Queue* createNewQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    if (q == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    q->size = 0;
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void printQueue(struct Queue* queue) {
    printf("Queue elements: ");
    struct Node* current = queue->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void peekQueue(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
    } else {
        printf("Front element: %d\n", q->front->data);
    }
}

int pollQueue(struct Queue* q) {
    int data = -1;
    if (q->front == NULL) {
        printf("Queue is empty\n");
    } else {
        struct Node* temp = q->front;
        data = temp->data;
        q->front = q->front->next;
        free(temp);
        q->size--;
    }
    return data;
}

bool offerQueue(struct Queue* q, int data) {
    struct Node* newNode = createNewNode(data);
    if (q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
    return true;
}

bool emptyQueue(struct Queue* q) {
    return q->front == NULL;
}

void freeQueue(struct Queue* queue) {
    if (queue == NULL) {
        return; 
    }
    struct Node* current = queue->front;
    struct Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(queue);
}