#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNewNode(int data){
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->next = NULL;
    return n;
}

void addToBeginning(struct Node** head, int data){
    struct Node* new_head = createNewNode(data);
    new_head->next = *head;
    *head = new_head;
}

void addToEnd(struct Node* head, int data){
    struct Node* new_tail = createNewNode(data);
    struct Node* tail = head;
    while (tail->next){
        tail = tail->next;
    }
    tail->next = new_tail;
    
}

void printLinkedList(struct Node* head) {
    int index = 0;
    while (head) {
        printf("Index: %d, Value: %d\n", index, head->data);
        head = head->next;
        index++;
    }
}

void freeList(struct Node* head) {
    struct Node* current = head;
    struct Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);  
        current = next;
    }
}


int countNodes(struct Node* head){
    int count = 0;
    while (head){
        count++;
        head = head->next;
    }
    return count;
}

int insertAt(struct Node* head, int index, int data){
    int totalNodes = countNodes(head);
    if (index == 0){
        addToBeginning(&head, data);
    }
    else if (index > totalNodes -1){
        return -1;
    }
    else{
        struct Node* n = createNewNode(data);
        int i = 0;
        while (head->next && i < index - 1){  
            head = head->next;
            i++;
        }
        struct Node* old = head->next;
        head->next = n;
        n->next = old;  
    }
    return 0;
   
}

int main() {
    struct Node* head = createNewNode(0);
    
    if (head == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1; 
    }
    addToEnd(head, 4);
    printLinkedList(head);
    int result = insertAt(head, 1,5);
    printf("%d",result);
    printLinkedList(head);
    freeList(head);
    
    return 0;
}
