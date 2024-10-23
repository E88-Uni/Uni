#include <stdio.h>
#include <time.h>
#include <stdlib.h>
/*
Data Una matrici ritornare colonna e riga con numero pari maggiore
*/
#define N 10
#define M 12
int int_rnd(int min, int max){
    return (rand()%(max-min+1))+min;
}

void printA(int Mat[M][N]){
    int i = 0, j;
    for(; i<M; i++){
        for(j=0; j<N; j++){
            printf(" %d ",Mat[i][j]);
        }
        printf("\n");
    }
}

void prin_sum(int Mat[M][N]){
    int i = 0, j, ci = 0, cj = 0, ci_max=0, cj_max=0;
    for(; i<M-1; i++){
        for(j=0; j<N-1; j++){
            int sum = Mat[i][j]+Mat[i+1][j]+Mat[i][j+1]+Mat[i+1][j+1];
            if(sum == 0){
                printf("\nIndici (%d, %d)", i, j);
                printf("\n %d %d \n %d %d\n", Mat[i][j],Mat[i][j+1],Mat[i+1][j],Mat[i+1][j+1]);
            }
        }
    }
}

void wait();
int main(){
    int Mat[M][N];
    int i = 0, j;
    srand(time(NULL));
    for(; i<M; i++){
        for(j=0; j<N; j++){
            Mat[i][j] = int_rnd(-3, 3);
        }
    }
    printA(Mat);
    prin_sum(Mat);
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