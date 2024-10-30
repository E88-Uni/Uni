#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
 1. Chiedere (#define N 5) numeri interi all’utente e memorizzarli in un vettore 'x'.
    Crea Puntatore p al vettore x fai la somma con *(p+i)  
 2. Chiedere N con malloc
 3. Valore casuale tra 0 e N 
 4. Matrice con dimensioni dinamiche, iniziallizata a 0
    Puntatore a (0,0) -> Puntatore(rnd_int(0,RIghe),rnd_int(0,Colonne))
    Esegure H volte da input utente
    Ogni cambio puntatore incrementare la cella puntata di (i+j)
    Stampa la matrice
 */
#define N 5

void es1();
void es2();

int int_rnd(int min, int max){
    int r = rand()%(max-min+1)+min;
    return r;
}

void printMatrix(int **p, int righe, int colonne){
    int i, j;
    for(i=0; i<righe; i++){
        for(j=0; j<colonne; j++){
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
}

void freeM(int **p, int righe){
    int i;
    for(i=0; i<righe; i++){
        free(p[i]);
    }
    free(p);
}

void es3(){
    int righe, colonne, i, j, H;
    printf("Inserisci numero righe: ");
    scanf("%d", &righe);
    printf("Inserisci numero colonne: ");
    scanf("%d", &colonne);
    int **p = (int **)malloc(righe*sizeof(int *));
    for(i=0; i<righe; i++){
        p[i] = (int *)calloc(colonne, sizeof(int));
    }
    printf("Inserisci numero iterazioni: ");
    scanf("%d", &H);
    for(i=0; i<H; i++){
        int a = int_rnd(0, righe-1);
        int b = int_rnd(0, colonne-1);
        p[a][b] = p[a][b]+a+b;
    }
    printMatrix(p, righe, colonne);
    freeM(p, righe);
}

int main() {
    int flag;
    //es1();es2();
    srand(time(NULL));//srand: s-'eed'-rand'om'
    //printf("Numero random: %d", int_rnd(0, 100));
    es3();
    scanf("%d", &flag);
    return 0;
}

void es1(){
    int x[N];
    int *p = x;
    int i, somma = 0;
    for (i = 0; i < N; i++) {
        printf("Inserisci un numero intero: ");
        scanf("%d", &x[i]);
        somma += *(p + i);
    }
    printf("La somma e': %d\n", somma);
}

void es2(){
    int *x, *p;
    int i, somma = 0, dim;
    printf("Inserisci dimensione: ");
    scanf("%d", &dim);
    if(dim > 0 && dim < 100){
        x = (int *)malloc(dim * sizeof(int));
    }
    p = x;
    for (i = 0; i < dim; i++) {
        printf("Inserisci un numero intero: ");
        scanf("%d", &x[i]);
        somma += *(p + i);
    }
    printf("La somma e': %d\n", somma);
    free(x);
}