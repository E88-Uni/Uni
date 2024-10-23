#include <stdio.h>
#include <stdlib.h>
#define N 10
/*
Numeri di coppie con samma V[i]+V[i-1]
*/
int main(){
    int i=1, max; 
    int V[N] = {1,2,3,1,2,3,1,2,3,0};
    int M[N];
    int *List;
    for(;i<N; i++){
        M[(i-1)]= V[(i-1)]+V[i];
    }
    max = M[0];
    for(i=1; i<(N-1); i++){
        if(max<M[i]){
            max = M[i];
        }
    }
    List = (int*)malloc(max*sizeof(int));
    for(i=0; i<=max; i++){
        List[i]=0;
    }
    for(i=0; i<(N-1); i++){
        List[M[i]]++;
    }
    for(i=0; i<=max; i++){
        if(List[i]!=0){
            printf("\n Ci sono %d coppie con valore %d", List[i], i);
        }    
    }
    free(List);
    return 0;
}