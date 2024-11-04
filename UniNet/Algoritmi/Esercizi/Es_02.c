#include <stdio.h>
#include <stdlib.h>
/* Matrie 6x5 ritorna false se 
   somma colonna j != somma colonna(j-1)+somma colonna(j-2) */

int **newMatrix(int righe, int colonne){
    int i, j, n;
    int **M = (int **)malloc(righe*sizeof(int *));
    for(i=0; i<righe; i++){
        M[i] = (int *)malloc(colonne*sizeof(int));
        for(j=0; j<colonne; j++){
            printf("\nInserisci [%d][%d]: ", i, j);
            scanf("%d", &n);
            M[i][j] = n;
        }
    }
    return M;
}

void printM(int **M, int righe, int colonne){
    int i, j;
    for(i=0; i<righe; i++){
        for(j=0; j<colonne; j++){
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
}

int checkMatrix(int **M, int righe, int colonne){
    int i, j;
    int sum0, sum1, sum2;
    for(j=2; j<colonne; j++){
        sum0 = 0; sum1 = 0; sum2 = 0;
        for(i=0; i<righe; i++){
            sum0 += M[i][j-2];
        }
        for(i=0; i<righe; i++){
            sum1 += M[i][j-1];
        }
        for(i=0; i<righe; i++){
            sum2 += M[i][j];
        }
        if(sum2 != (sum0+sum1)){
            return 0;
        }
    }
    return 1;
}
void freeM(int **M, int righe){
    int i;
    for(i=0; i<righe; i++){
        free(M[i]);
    }
    free(M);
}
int main(){
    int flag, result;
    int **M = newMatrix(6, 5);
    printM(M, 6, 5);
    result = checkMatrix(M, 6, 5);
    freeM(M, 6);
    if(result == 0){
        printf("\nCondizione non valida");
    }else{
        printf("\nCondizione valida");
    }
    scanf("%d", &flag);
    return 0;
}