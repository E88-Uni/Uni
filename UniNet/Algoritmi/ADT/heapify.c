#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;  
    *a = *b;
    *b = temp;
}


void heapify(int A[], int n, int id) {
    int id_l = id*2+1, id_r = id*2+2;
    int id_max = (n>id_l && A[id_l]>A[id]) ? id_l : id;
    if(n>id_r){
        id_max = (A[id_r]>A[id_max]) ? id_r : id_max;
    }
    if(id_max!=id){
        swap(&A[id], &A[id_max]);
        heapify(A, n, id_max);
    }
}

int main() {
    int A[] = {4, 10, 3, 5, 1};
    int n = 5, i=0;

    heapify(A, n, 0);

    for(; i<n; i++){
        printf(" %d ", A[i]);
    }
    scanf("%d", &i);
    return 0;
}