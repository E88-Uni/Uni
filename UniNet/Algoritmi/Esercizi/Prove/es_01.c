#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*n dinamico pr M[n][]
Lista L struttura dati 
Serializza: Copia in L M da ordine righe
Copia in M L da ordine colonna
main chiede n crea M[n][n] e la riempie di interi
    Serializza: stampa -> +5 valori Lista
    Copia Lita in Matrice stampa matrice*/


typedef struct List{
    int e;
    struct List *next;
} *pL;

int rnd_int(int n);

pL new(int e) {
    pL new_l = (pL)malloc(sizeof(struct List));
    new_l->e = e;
    new_l->next = NULL;
    return new_l;
}

pL add(pL L, int e) {
    if(L == NULL) {
        return new(e);
    }else{
        pL new_l;
        new_l = (pL)malloc(sizeof(struct List));
        L->next = new_l;
        new_l->e = e;
        new_l->next = NULL;
        return new_l;
    }
}

int **new_matrix(int n) {
    int **M = (int **)malloc(n*sizeof(int*));
    int i=0, j;
    for(; i<n; i++) {
        M[i] = (int *)malloc(n*sizeof(int));
        for(j=0; j<n; j++) {
            M[i][j] = rnd_int(10);
        }
    }
    return M;
}

pL copyM(int **M, int n) {
    pL root=NULL, L=NULL;
    int i=0, j;
    for(; i<n; i++) {
        for(j=0; j<n; j++) {
            L = add(L, M[i][j]);
            if(i==0 && j==0) {
                root = L;
            }
        }
    }
    return root;
}

void copyL(pL root, int **M, int n) {
    int i = 0, j;
    pL list = root;
    for(;i<n;i++) {
        for(j=0;j<n;j++) {
            M[i][j] = list->e;
            list = list->next;
        }
    } 
}

void printM(int **M, int n) {
    int i=0, j;
    for(; i<n; i++) {
        for(j=0; j<n; j++) {
            printf(" %d ", M[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int flag, n, i=0;
    int **M;
    pL L, root;
    srand(time(NULL));
    printf("Inserisci dimensione matrice: ");
    scanf("%d", &n);
    if(n<1 || n>200) {
        printf("Dimensione non valida\n");
        return 0;
    }
    M = new_matrix(n);
    printM(M, n);
    root = copyM(M, n);
    L = root;
    while(L != NULL) {
        L->e = (L->e)+5;
        L = L->next;
    }
    printf("+5 Avvenuto");
    copyL(root, M, n);
    printM(M, n);
    printf("\nFree Process\n");
    /* Free */
    for(i = 0; i < n; i++) {
        free(M[i]);
    }
    free(M);
    L = root;
    while(L != NULL) {
        pL next = L->next;
        free(L);
        L = next;
    }
    scanf("%d", &flag);
    return 0;
}

int int_rnd(int min, int max){
    int r = rand()%(max-min+1)+min;
    return r;
}

int rnd_int(int n) {
    return int_rnd(0, n);
}