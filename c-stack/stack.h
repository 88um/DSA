#ifndef STACK_H
#define STACK_H
#include <stdbool.h>

typedef enum {
    INT,
    CHAR,
    DOUBLE
} DataType;

typedef struct ArrayStack{
    DataType type;
    int size;
    int top;
    void *data;
    
} ArrayStack;

ArrayStack* createStack(DataType type, int size);
void* popStack(ArrayStack *stack);
void* peekStack(ArrayStack *stack);
bool pushStack(ArrayStack *stack, void* item);
bool emptyStack(ArrayStack *stack);
void freeStack(ArrayStack *stack);

#endif