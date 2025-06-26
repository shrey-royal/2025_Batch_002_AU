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

void dequeue(struct Queue *q) {
    if (q->front == -1) printf("\nQueue is empty");
    else {
        printf("\nDequeue element: %d", q->items[q->front]);
        if (q->front == q->rear) q->front = q->rear = -1;
        else q->front++;
    }
}

int peekFront(struct Queue *q) {
    if (q->front == -1) printf("\nQueue is empty");
    else return q->items[q->front];
}

int peekRear(struct Queue *q) {
    if (q->rear == -1) printf("\nQueue is empty");
    else return q->items[q->rear];
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
    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60);
    enqueue(&q, 70);
    enqueue(&q, 80);
    enqueue(&q, 90);
    enqueue(&q, 200);
    dequeue(&q);
    enqueue(&q, 30);
    display(&q);
    printf("\npf: %d", peekFront(&q));
    printf("\npr: %d", peekRear(&q));
    
    return 0;
}