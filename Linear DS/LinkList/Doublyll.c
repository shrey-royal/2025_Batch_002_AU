#include<stdio.h>
#include<stdlib.h>

typedef struct Node node;

struct Node {
    node* prev;
    int data;
    node* next;
};

node* createNode(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    if(newNode == NULL) {
        printf("\nMemory allocation failed!\n");
        return NULL;
    }
    newNode->prev = NULL;
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void insertAtBeginning(node* head, int value) {
    node* newNode = createNode(value);

    if (head != NULL) {
        newNode->next = head;
        head->prev = newNode;
    }
    return newNode;
}

int main() {
    node* head = NULL;

    insertAtBeginning(&head, 10);

    return 0;
}