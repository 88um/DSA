#include "stack.h"
#include <stdio.h>

int main() {

    ArrayStack* intStack = createStack(INT, 5);
    int elements[] = {10, 20, 30, 40, 50};
    for (int i = 0; i < 5; i++) {
        pushStack(intStack, &elements[i]);
    }
    int* topElement = (int*)peekStack(intStack);
    printf("Top element: %d\n", *topElement);
    printf("Popped elements: ");
    while (!emptyStack(intStack)) {
        int* poppedElement = (int*)popStack(intStack);
        printf("%d ", *poppedElement);
    }
    printf("\n");
    freeStack(intStack);

    return 0;
}
