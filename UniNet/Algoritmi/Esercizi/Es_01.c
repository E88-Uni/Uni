#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} *pl;

int rnd_int(int min, int max){
    int r = rand()%(max-min+1)+min;
    return r;
}

int **newM(int n){
    int i;
    int **M;
    if(n>0 && n<100){
        M = (int **)malloc(n*sizeof(int *));
        for(i=0; i<n; i++){
            int k = 0;
            M[i] = (int *)malloc(n*sizeof(int));
            for(; k<n; k++){
                M[i][k] = rnd_int(0, 100);
            }
        }
    }
    return M;
}

void add_tail(pl *p, int data){
    pl q = (pl)malloc(sizeof(struct node));
    q->data = data;
    q->next = NULL;
    if(*p == NULL){
        *p = q;
    }else{
        pl r = *p;
        while(r->next != NULL){
            r = r->next;
        }
        r->next = q;
    }
}

pl copyM(int **M, int n){
    int i, j;
    pl p = NULL;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            add_tail(&p, M[i][j]);
        }
            
    }
    return p;
}

void printl(pl p){
    while(p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }
}

void printM(int **M, int n){
    int i, j;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
}

void add_list(pl p, int n){
    while(p != NULL){
        p->data += n;
        p = p->next;
    }
}

void setM(int **M, int n, pl p){
    int i, j;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            M[i][j] = p->data;
            p = p->next;
        }
    }
}
void freeL(pl p){
    while(p != NULL){
        pl q = p->next;
        free(p);
        p = q;
    }
}
void freeM(int **M, int righe){
    int i;
    for(i=0; i<righe; i++){
        free(M[i]);
    }
    free(M);
}

int main(){
    int flag, n;
    int **M;
    pl L = NULL;
    /* Da Matrice a Lista */
    printf("Inserisci n: ");
    scanf("%d", &n);
    M = newM(n);
    printf("\nMatrice creata");
    printM(M, n);
    L = copyM(M, n);
    printf("\nCopia Eseguita");
    freeM(M, n);
    printl(L);

    /* Da Lista a Matrice con +5 */
    add_list(L, 5);
    printf("\nLista aggiornata");
    printl(L);
    M = newM(n);
    setM(M, n, L);
    printf("\nMatrice aggiornata");
    printM(M, n);
    freeL(L);
    freeM(M, n);
    scanf("%d", &flag);
    return  0;
}