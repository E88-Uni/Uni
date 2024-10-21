#include <stdio.h>
#include <time.h>
#include <stdlib.h>
/*
Data Una matrici ritornare colonna e riga con numero pari maggiore
*/
#define N 5
#define M 4
int int_rnd(int min, int max){
    return (rand()%(max-min+1))+min;
}

void prin_sum(int Mat[M][N]){
    int i = 0, j, ci = 0, cj = 0, ci_max=0, cj_max=0;
    for(; i<M; i++){
        for(j=0; j<N; j++){
            int n = Mat[i][j];
            cj = cj + ((n%2)==0);
            printf(" %d ", n);
            if(j == N-1){
                printf(" : %d\n", cj);
                cj_max = (cj>cj_max)?cj:cj_max;
                cj = 0;
            }
        }
    }
    for(j=0; j<N; j++){
        for(i=0; i<M; i++){
            int n = Mat[i][j];
            ci = ci + ((n%2)==0);
            if(i == M-1){
                printf(" %d ", ci);
                ci_max = (ci>ci_max)?ci:ci_max;
                ci = 0;
            }
        }
    }
    printf("\n");
    ci = 0;
    cj = 0;
    for(i=0; i<M; i++){
        for(j=0; j<N; j++){
            int n = Mat[i][j];
            cj = cj + ((n%2)==0);
            if(j == N-1){
                if(cj == cj_max){
                    printf(" Riga max : %d\n", i+1);
                }
                cj = 0;
            }
        }
    }
    for(j=0; j<N; j++){
        for(i=0; i<M; i++){
            int n = Mat[i][j];
            ci = ci + ((n%2)==0);
            if(i == M-1){
                if(ci == ci_max){
                    printf(" Colonna max : %d\n", j+1);
                }
                ci = 0;
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
            Mat[i][j] = int_rnd(0, 5);
        }
    }
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