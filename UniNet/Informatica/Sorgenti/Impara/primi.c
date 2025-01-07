#include <stdio.h>
#include <stdlib.h>
/*Usa sottofunzione per controllare se una 
se una coppia di numeri è prima
Date N coppie in input */

#define N 40

typedef struct cop{
    int a, b;
}* cp;


int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int are_coprime(int a, int b) {
    return gcd(a, b) == 1;
}


void populate(cp C, int dim);

void printC(cp C, int dim){
    int i = 0;
    for(; i<dim; i++){
        int prim = are_coprime(C[i].a, C[i].b);
        printf("\n (%d, %d)=%d", C[i].a, C[i].b, prim);
    }
}

int main(){
    int d;
    cp C = (cp)malloc(sizeof(struct cop)*N);
    populate(C, N);
    printC(C, N);
    scanf("%d", &d);
    free(C);
    return 0;
}

void populate(cp C, int dim){
    int i = 0, j=0;
    for(; j<dim; j++){
        C[j].a = i;
        C[j].b = (i+2);
        i += 3;
    }
}