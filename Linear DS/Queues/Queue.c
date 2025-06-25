#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 10

struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

void enqueue(struct Queue *q, int value) {
    if (q->rear == MAX_SIZE - 1) printf("\nQueue is full");
    else {
        if (q->front == -1) q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

void display(struct Queue *q) {
    if (q->rear == -1) printf("\nQueue is empty!");
    else {
        printf("\nQueue elements are: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d, ", q->items[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Queue q;
    q.front = q.rear = -1;

    display(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    display(&q);
    
    return 0;
}