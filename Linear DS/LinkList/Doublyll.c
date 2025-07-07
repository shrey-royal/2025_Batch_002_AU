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

int getLength(node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

void insertAtBeginning(node** head, int value) {
    node* newNode = createNode(value);

    if (*head != NULL) {
        newNode->next = *head;
        (*head)->prev = newNode;
    }
    *head = newNode;
}

void insertAtEnd(node** head, int value) {
    node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        node* temp = *head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void insertAtPosition(node** head, int value, int position) {
    if (head == NULL || position == 1) {
        insertAtBeginning(head, value);
    } else if ((position < 0) || (getLength(*head) < position)) {
        printf("Insertion at %d position is not possible!", position);
    } else {
        node* newNode = createNode(value);
        node* temp = *head;
        for (int i = 1; i < position - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next->prev = newNode;
        newNode->prev = temp;
        temp->next = newNode;
    }
}

void printList(node* head) {
    printf("\nList > \tNULL <-> ");
    while(head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n\n");
}

int main() {
    node* head = NULL;

    // insertAtBeginning(&head, 10);
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);
    insertAtEnd(&head, 60);

    insertAtPosition(&head, 999, 3);

    printList(head);

    return 0;
}