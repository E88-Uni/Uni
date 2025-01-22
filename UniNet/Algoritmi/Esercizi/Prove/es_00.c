#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
void es01(int *M, int dim) {
    int *p;
    int i = 0, somma = 0;
    printf("Inserisci %d numeri interi: ", dim);
    for(; i < dim; i++) {
        scanf("%d", &M[i]);
        p = M+i;
        somma += *p;
    }
    printf("La somma e' %d\n", somma);

}

void es02() {
    int dimN;
    int *M;
    printf("Inserisci la dimnesione vettore: :");
    scanf("%d\n", &dimN);
    M = (int *)malloc(dimN*sizeof(int));
    es01(M, dimN);
    free(M);
}

int int_rnd(int min, int max){
    int r = rand()%(max-min+1)+min;
    return r;
}

int es03(int n) {
    return int_rnd(0, n);
}

void ptintM(int **M, int Y, int W) {
    int i=0, j;
    for(; i<Y; i++) {
        for(j=0; j<W; j++) {
            printf(" %d ", M[i][j]);
        }
        printf("\n");
    }
}

void es04() {
    int Y, W, H;
    int **M;
    int i, j, k, val=0;
    printf("Inserisci altezza e larghezza Matrice: ");
    scanf("%d %d", &Y, &W);
    M = (int **)malloc(Y*sizeof(int*));
    for(i = 0; i < Y; i++) {
        M[i] = (int *)malloc(W*sizeof(int));
        for(j = 0; j < W; j++) {
            M[i][j] = 0;
        }
    }
    printf("\nInserisci Spostamenti: ");
    scanf("%d", &H);
    for(k = 0; k < H; k++) {
        i = es03((Y-1));
        j = es03((W-1));
        val = val+j+i;
        M[i][j] = val;
    }

    ptintM(M, Y, W);
    for(i = 0; i < Y; i++) {
        free(M[i]);
    }
    free(M);
}

int main() {
    int flag, num;
    int M[N];
    srand(time(NULL));
    //es01(M, N);
    //es02();
    num = 100;
    //es03(num);
    es04();
    scanf("%d", &flag);
    return 0;
}