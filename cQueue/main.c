#include "queue.h"
#include <stdio.h>


int main() {
    struct Queue* queue = createNewQueue();
    offerQueue(queue, 10);
    offerQueue(queue, 20);
    offerQueue(queue, 30);
    
    printQueue(queue);
    peekQueue(queue);

    printf("Popped element: %d\n", pollQueue(queue));

    printQueue(queue);
    peekQueue(queue);

    freeQueue(queue);
    
    return 0;
}
