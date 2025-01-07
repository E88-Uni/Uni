#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void structure();
/* File con n numeri random uno per riga e salvari in un array
con dim dinamica, cio� righe*/

int rnd(int min, int max){
    return rand() % (max - min + 1) + min;
}

void createFile(){
    FILE *f;
    int n;
    srand(time(NULL));
    f = fopen("numbers.txt", "w");
    printf("\nInserisci numero righe");
    scanf("%d", &n);
    if(n>0 && n<1000){
        while(n){
            fprintf(f, "%d\n", rnd(0, 200));
            n--;
        }
    }
    fclose(f);
}

void getFile(){
    int flag, dim = 0, i = 0;
    FILE *f;
    int *M;
    printf("\n 1 File Nuovo : ");
    scanf("%d", &flag);
    if(flag==1) {
        createFile();
    }
    f = fopen("numbers.txt", "r");
    while(!feof(f)){
        int val;
        fscanf(f, "%d", &val);
        dim++;
    }
    dim--;
    fclose(f);

    M = (int *)malloc(sizeof(int)*dim);
    f = fopen("numbers.txt", "r");
    while(!feof(f)){
        int val;
        fscanf(f, "%d", &val);
        M[i] = val;
        i++;
    }
    fclose(f);
    printf("\nValori:\n");
    i = 0;
    while(i < dim){
        printf(" %d ", M[i]);
        i++;
    }
    printf("\n");
    free(M);
}

void dinamic_memory(){
    int n;
    int *pn;
    printf("\nQuati interi servono? :");
    scanf("%d", &n);
    if(n>0 && n<=100){
        pn = (int *)malloc(sizeof(int)*100);
        pn[0] = 1;
        if(pn != NULL){
            printf("\nAllocazione avvenuta locazione(%p) pn[0]: %d",pn, pn[0]);
        }else{
            printf("\nMemoria non disponibile");
        }
        free(pn);
    }else{
        printf("Dimensione non valida");
    }
}

int main()
{
    int x = 5, *px;
    px = &x;
    /*printf("Accesso Diretto(x) %d == %d Accesso Indiretto(*px)", x, *px);
    printf("\nIndirizzo x %p == %p", &x, px);
    structure();*//*
    printf("Dimesioni Byte int:%d , char:%d, double:%d", sizeof(int), sizeof(char), sizeof(double));
    dinamic_memory();*/
    getFile();    
    scanf("%d", &x);
    return 0;
}

void structure(){
    struct complex {
        double re, im;
    } c, *pc;
    c.re = 1.0;
    c.im = 2.0;
    pc = &c;
    printf("\n%f %f\n", pc->re, pc->im);
}
