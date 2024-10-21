#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Copia v1 e v2 in v3
Ordina in decrescente
*/

int rnd_int(int min, int max){
    return rand()%(max-min+1)+min;
}

int populate(int *A, int dim){
    int i = 0;
    for(; i<dim; i++){
        A[i] = rnd_int(0, 5);
    }
    return 1;
}

int *merge(int A[], int dimA, int B[], int dimB){
    int i, dimC = dimA+dimB;
    //int C[dimC]; Perchè Array locale viene svuotato alla chiusura della funzione
    int *C;
    C = (int *)malloc(sizeof(int)*dimC);
    for(i=0; i<dimA; i++){
        C[i] = A[i];
    }
    for(i=0; i<dimB; i++){
        C[(i+dimA)] = B[i];
    }
    return C;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int *A, int dim){
    int i, j;
    for(i=0; i<dim-1; i++){
        for(j=0; j<dim-i-1; j++){
            if(A[j]<A[j+1]){
                swap(A+j, A+j+1);
            }
        }
    }
}
void wait();
void print_A();

int main(){
    int dimA = 10, dimB = 8;
    int A[10], B[8], *C;
    srand(time(NULL));
    populate(A, dimA);
    populate(B, dimB);
    print_A(A, dimA);
    print_A(B, dimB);
    C = merge(A, dimA, B, dimB);
    print_A(C, dimA+dimB);
    bubble_sort(C, dimA+dimB);
    print_A(C, dimA+dimB);
    free(C);
    wait();
    return 0;
}

void wait(){
    int c;
    printf("\nClose. 1 Reload Main");
    scanf("%d", &c);
    if(c==1){
        main();
    }
}
void print_A(int *A, int dim){
    int i = 0;
    printf("\n");
    for(;i<dim; i++){
        printf(" %d ", A[i]);
    }
    printf("\n");
}