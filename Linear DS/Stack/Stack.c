#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 100

int stack[MAX];
int top = -1;

bool isEmpty() {
    return (top == -1);
}

bool isFull() {
    return (top == MAX - 1);
}

void push(int value) {
    if (isFull()) {
        printf("\nStack Overflow!\n");
    } else {
        stack[++top] = value;
        printf("\n%d pushed into the stack\n", value);
    }
}

void pop() {
    if (isEmpty()) {
        printf("\nStack Underflow!\n");
    } else {
        printf("\n%d popped from the stack\n", stack[top--]);
    }
}

int peek() {
    if (isEmpty()) {
        printf("\nStack Underflow!\n");
        return 0;
    } else return stack[top];
}

int getSize() {
    return top + 1;
}

void display() {
    if (isEmpty()) {
        printf("\nStack is Underflow.\n");
    } else {
        printf("Stack Elements: ");
        for (int i = top; i >= 0; i--) {
            printf("%d, ", stack[i]);
        }
        printf("\n");
    }
}

// 1 1 1 2 1 3 1 4 1 5 1 6 1 7 1 8 1 9 1 10
int main() {
    int choice, value;

    do {
        system("cls");
        display();
        printf("\n\nStack Operations: ");
        printf("\n1. Push()");
        printf("\n2. Pop()");
        printf("\n3. Peek()");
        printf("\n4. isEmpty()");
        printf("\n5. isFull()");
        printf("\n6. size()");
        printf("\n7. display()");
        printf("\n0. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the value to push into the stack: ");
                scanf("%d", &value);
                push(value);
                system("pause");
                break;

            case 2:
                pop();
                system("pause");
                break;

            case 3:
                printf("\nPeek Element from the stack is %d.\n", peek());
                system("pause");
                break;

            case 4:
                printf("\n-> Is stack empty? : %s\n", isEmpty()?"True":"False");
                system("pause");
                break;

            case 5:
                printf("\n-> Is stack full? : %s\n", isFull()?"True":"False");
                system("pause");
                break;

            case 6:
                printf("\nSize of the stack is %d.\n", getSize());
                system("pause");
                break;

            case 7:
                display();
                system("pause");
                break;
            
            case 0:
                break;
                
            default:
                printf("\nInvalid Choice!\n");
        }
    } while(choice != 0);
}