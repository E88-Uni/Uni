#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertionSort(int A[], int n){
    int i, j;
    for(i=1; i<n; i++){
        int temp = A[i];
        j = i-1;
        while(j>=0 && A[j]>temp){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = temp;
    }
}

int main(){
    int A[5] = {4, 10, 3, 5, 1};
    
    int flag;
    scanf("%d", &flag);
    return 0;
}