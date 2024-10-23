#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/*Somma (Somma Righe) == Somma (Somma Colonne)*/
#define N 5
#define M 4
int int_rnd(int min, int max){
    return (rand()%(max-min+1))+min;
}

void prin_sum(int Mat[M][N]){
    int i = 0, j, ci = 0, cj = 0;
    for(; i<M; i++){
        for(j=0; j<N; j++){
            int n = Mat[i][j];
            cj+=n;
            printf(" %d ", n);
            if(j == N-1){
                printf(" : %d\n", cj);
                cj = 0;
            }
        }
    }
    for(j=0; j<N; j++){
        for(i=0; i<M; i++){
            int n = Mat[i][j];
            ci+=n;
            if(i == M-1){
                printf(" %d ", ci);
                ci = 0;
            }
        }
    }
}

void wait();
int main(){
    int Mat[M][N];
    int i = 0, j;
    for(; i<M; i++){
        for(j=0; j<N; j++){
            Mat[i][j] = int_rnd(0, 5);
        }
    }
    prin_sum(Mat);
    srand(time(NULL));
    wait();
    return 0;
}
void wait(){
    int flag = 0;
    printf("\n 1 new run");
    scanf("%d", &flag);
    if(flag == 1){
        printf("\n");
        main();
    }
}