#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Matrice 6*5
Verifica Somma colonna = SommaColonna-1 + SommaColonna-2*/
int main() {
    int flag, i=0,j, id=0;
    int *sums = (int *)malloc(5*sizeof(int));
    int **M = (int **)malloc(6*sizeof(int*));

    for(; i<6; i++) {
        M[i] = (int *)malloc(5*sizeof(int));
        for(j=0; j<5; j++) {
            M[i][j] = ++id;
        }
    }

    for(i=0; i<5; i++) {
        sums[i] = 0;
    }

    for(j=0; j<5; j++) {
        for(i=0; i<6; i++) {
            sums[j] += M[i][j];
        }
    }

    printf("\n\n");
    for(i=0; i<6; i++) {
        for(j=0; j<5; j++) {
            printf(" %d ", M[i][j]);
        }
        printf("\n");
    }

    printf("\n\n");
    for(i=0; i<5; i++) {
        printf(" %d ", sums[i]);
        if(i>1 && sums[i] != (sums[i-1] + sums[i-2])) {
            printf("\n\nFalse");
            scanf("%d", &flag);
            return 0;
        }
    }

    printf("\n\nTrue");

    free(sums);
    for(i=0; i<6; i++) {
        free(M[i]);
    }
    free(M);

    scanf("%d", &flag);
    return 0;
}