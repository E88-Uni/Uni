#include <stdio.h>
/*Dati 2 vettori ritornare quello con la somma deggli elementi maggiore*/

int tot_A(int A[], int dim){
    if(dim>0){
        dim--;
        return A[dim]+tot_A(A, dim);
    }else{
        return 0;
    }
}

int main(){
    int A[5]={1,2,3,4,5};
    int B[5]={6,7,8,9,10};
    int sumA = tot_A(A, 5);
    int sumB = tot_A(B, 5);
    printf("Somma A : %d .Somma B : %d\n", sumA, sumB);
    scanf("%d", &sumA);
    return 0;
}