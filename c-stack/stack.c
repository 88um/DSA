#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


ArrayStack* createStack(DataType type, int size) {
    ArrayStack* stack = (ArrayStack*)malloc(sizeof(ArrayStack));
    if (stack == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    stack->type = type;
    stack->size = size;
    stack->top = -1;
    
    
    switch (type) {
        case INT:
            stack->data = malloc(size * sizeof(int));
            break;
        case CHAR:
            stack->data = malloc(size * sizeof(char));
            break;
        case DOUBLE:
            stack->data = malloc(size * sizeof(double));
            break;
        default:
            fprintf(stderr, "Invalid data type\n");
            free(stack);
            exit(EXIT_FAILURE);
    }
    if (stack->data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        free(stack);
        exit(EXIT_FAILURE);
    }
    return stack;
}


void* popStack(ArrayStack *stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return NULL;
    }
    void* element;
    switch (stack->type) {
        case INT:
            element = (int*)stack->data + stack->top;
            break;
        case CHAR:
            element = (char*)stack->data + stack->top;
            break;
        case DOUBLE:
            element = (double*)stack->data + stack->top;
            break;
        default:
            fprintf(stderr, "Invalid data type\n");
            exit(EXIT_FAILURE);
    }
    stack->top--;
    return element;
}


void* peekStack(ArrayStack *stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return NULL;
    }
    void* element;
    switch (stack->type) {
        case INT:
            element = (int*)stack->data + stack->top;
            break;
        case CHAR:
            element = (char*)stack->data + stack->top;
            break;
        case DOUBLE:
            element = (double*)stack->data + stack->top;
            break;
        default:
            fprintf(stderr, "Invalid data type\n");
            exit(EXIT_FAILURE);
    }
    return element;
}


bool pushStack(ArrayStack *stack, void *item) {
    if (stack->top == stack->size - 1) {
        printf("Stack is full\n");
        return false;
    }
    stack->top++;
    switch (stack->type) {
        case INT:
            *((int*)stack->data + stack->top) = *((int*)item);
            break;
        case CHAR:
            *((char*)stack->data + stack->top) = *((char*)item);
            break;
        case DOUBLE:
            *((double*)stack->data + stack->top) = *((double*)item);
            break;
        default:
            fprintf(stderr, "Invalid data type\n");
            exit(EXIT_FAILURE);
    }
    
    return true;
}



bool emptyStack(ArrayStack* stack){
    return stack->top ==-1;
}

void freeStack(ArrayStack *stack) {
    if (stack == NULL) {
        return;
    }
    free(stack->data);  
    free(stack);        
}
