#include <stdio.h>
#include <stdlib.h>

// Binary Tree.C

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode != NULL){
        newNode->data = data;
        newNode->left = newNode->right = NULL;
    }
    return newNode;
    
}

void append(Node* root, Node* node) {
    if (node->data >= root->data) {
        if (root->right == NULL) {
            root->right = node;
        } else {
            append(root->right, node);
        }
    } else {
        if (root->left == NULL) {
            root->left = node;
        } else {
            append(root->left, node);
        }
    }
}

void addNode(Node* root, int data) {
    Node* newNode = createNode(data);
    append(root, newNode);
}

void printTree(Node* root) {
    if (root == NULL) {
        return;
    }
    Node* queue[1000]; 
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        int count = rear - front;
        while (count--) {
            Node* currentNode = queue[front++];
            printf("%d ", currentNode->data);
            if (currentNode->left != NULL) {
                queue[rear++] = currentNode->left;
            }
            if (currentNode->right != NULL) {
                queue[rear++] = currentNode->right;
            }
        }
        printf("\n"); 
    }
}


void freeTree(Node* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    
    Node* root = createNode(5);
    addNode(root, 6);
    addNode(root,3);
    addNode(root,7);
    addNode(root,0);
    printTree(root);
    freeTree(root);
    return 0;
}
