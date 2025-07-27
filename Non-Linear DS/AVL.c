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

int getBalance(node* n) {
    return n ? getHeight(n->left) - getHeight(n->right) : 0;
}

node* rightRotate(node* unBalancedNode) {
    node* newRoot = unBalancedNode->left;
    node* rightSubtreeOfNewRoot = newRoot->right;

    // perform rotation
    newRoot->right = unBalancedNode;
    unBalancedNode->left = rightSubtreeOfNewRoot;

    // Update heights
    unBalancedNode->height = max(getHeight(unBalancedNode->left), getHeight(unBalancedNode->right)) + 1;
    newRoot->height = max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;

    return newRoot;
}

node* leftRotate(node* unBalancedNode) {
    node* newRoot = unBalancedNode->right;
    node* leftSubtreeOfNewRoot = newRoot->left;

    // perform rotation
    newRoot->left = unBalancedNode;
    unBalancedNode->right = leftSubtreeOfNewRoot;

    // Update heights
    unBalancedNode->height = max(getHeight(unBalancedNode->left), getHeight(unBalancedNode->right)) + 1;
    newRoot->height = max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;

    return newRoot;
}

node* insert(node* root, int value) {
    if(root == NULL) return createNode(value);
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if(value > root->data) {
        root->right = insert(root->right, value);
    } else {
        return root;
    }

    // Update heights
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // check balance
    int balance = getBalance(root);

    if (balance > 1 && value < root->left->data) {  // LL
        return rightRotate(root);
    }
    if (balance < -1 && value > root->right->data) {    // RR
        return leftRotate(root);
    }
    if (balance > 1 && value > root->left->data) {  // LR
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && value < root->right->data) {    // RL
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inorder(node* root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void printTree(node* root, int space) {
    if (root == NULL) {
        return;
    }
    space += 4;
    printTree(root->right, space);
    for (int i = 4; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);
    printTree(root->left, space);
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
    printf("\n");

    printTree(root, 0);
    
    return 0;
}