#include <stdio.h>
#include <stdlib.h>

#define elem int
/*LIFO : Last in First Out Pila Libri*/
typedef struct Node{
    elem info;
    struct Node *next;
} Node;

typedef struct Node *Stack;

Stack newNode(elem data){
    Stack ps = (Stack)malloc(sizeof(Node));
    ps->info = data;
    ps->next = NULL;
    return ps;
}

void push(Stack *top, elem x){
    Stack ps = newNode(x);
    ps->next = *top;
    *top = ps;
}

elem pop(Stack *top){
    Stack temp = *top;
    elem data;
    if(temp == NULL){
        printf("Stack underflow\n");
        return -1;
    }
    data = (*top)->info;
    *top = (*top)->next;
    free(temp);
    return data;
}

void printStack(Stack top){
    Stack temp = top;
    printf("\n");
    while(temp != NULL){
        printf(" %d ->", temp->info);
        temp = temp->next;
    }
    printf("\n");
}