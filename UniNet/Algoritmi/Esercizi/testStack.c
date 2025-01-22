#include <stdio.h>
#include <stdlib.h>
#define elem float
#define N 100
typedef struct {
    int top;
    elem info[N];
} Stack;

void push(Stack *s, elem x) {
    s->info[s->top] = x;
    s->top++;   
}

int main(){
    int flag, i;
    float e = 0.0;
    Stack *ps = (Stack *)malloc(sizeof(Stack));
    ps->top = 0;
    for(i=0; i<10; i++){
        e = e + 3.0;
        push(ps, e);
    }
    for(i=0; i<10; i++){
        printf("%f\n", ps->info[i]);
    }
    free(ps);
    scanf("%d", &flag);
    return 0;
}