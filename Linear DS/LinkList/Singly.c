#include<stdio.h>
#include<stdlib.h>

typedef struct Node node;

struct Node {
    int data;
    node* next;
};

node* createNode(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    if(newNode == NULL) {
        printf("\nMemory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void insertAtBeginning(node** head, int data) {
    node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void printList(node* head) {
    printf("\nList: ==> ");
    while(head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    node* head = NULL;

    printList(head);
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);
    insertAtBeginning(&head, 40);
    insertAtBeginning(&head, 50);
    insertAtBeginning(&head, 60);

    printList(head);

    return 0;
}