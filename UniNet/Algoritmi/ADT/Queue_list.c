#include <stdio.h>
#include <stdlib.h>

#define elem int
/*FIFO : First in First Out Coda*/
typedef struct Node{
    elem info;
    struct Node *next;
} Node;

typedef struct Node *List;

typedef struct que {
    Node *front, *rear;
} que;

typedef struct que *Queue;

Queue createQueue() {
    Queue q = (Queue)malloc(sizeof(que));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void enqueue(Queue q, elem x) {
    List pl = (List)malloc(sizeof(Node));
    pl->info = x;
    pl->next = NULL;
    if(q->rear == NULL) {
        q->front = pl;
        q->rear = pl;
        return;
    } 
    q->rear->next = pl;
    q->rear = pl;
}

elem dequeue(Queue q) {
    List temp = q->front;
    elem x;
    if(temp == NULL) {
        printf("Queue underflow\n");
        return -1;
    }
    x = temp->info;
    q->front = q->front->next;
    if(q->front == NULL){
        q->rear = NULL;
    }
    free(temp);
    return x;
}

void printQueue(Queue q) {
    List temp = q->front;
    printf("\n");
    while(temp != NULL) {
        printf(" %d ->", temp->info);
        temp = temp->next;
    }
    printf("\n");
}