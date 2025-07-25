#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    int height;
    struct Node* left;
    struct Node* right;
} node;

int getHeight(node* n) {
    return n ? n->height : 0;
}

int max(int a, int b) {
    return (a>b) ? a : b;
}

node* createNode(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

int main() {
    node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    printf("Inorder Traversal of AVL Tree: ");
    inorder(root);
    
    return 0;
}