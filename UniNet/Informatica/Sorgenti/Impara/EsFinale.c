#include <stdio.h>
#include <stdlib.h>
/*Gestire prenotazione Posti di una sala cinematografica 
Numero variabile di file
Ogni fila con define NP poltroncine
Info scritta in un fle 'dati.txt'
    - Riga file con NP caratteri
    - 'L' posto libero 
*/
#define NP 10


int check(FILE *f, int x, int y, int dimR){
    int i, j;
    char flag;
    for(i = 0; i < dimR; i++){
        for(j = 0; j <= NP; j++){
            fscanf(f, "%c", &flag);
            if(flag != '\n' && j == x-1 && i == y-1){
                printf("Status Posto (%d, %d):%c\n", x, y, flag);
                if(flag == 'L'){
                    return 1;
                }else{
                    return 0;
                }
            }
            
        }
    }
    
}

void fill(int x, int y, int dimR){
    int i, j;
    char flag;
    FILE *f;
    int M[NP][dimR];
    f = fopen("dati.txt", "r");
    for(i = 0; i < dimR; i++){
        for(j = 0; j <= NP; j++){
            fscanf(f, "%c", &flag);
            if(flag != '\n'){
                if(flag == 'L'){
                    M[i][j] = 1;
                }else{
                    M[i][j] = 0;
                }
            }
        }
    }
    fclose(f);
    f = fopen("dati.txt", "w");
    for(i = 0; i < dimR; i++){
        for(j = 0; j < NP; j++){
            if(M[i][j] == 0 || (j == x-1 && i == y-1)){
                fprintf(f, "O");
            }else{
                fprintf(f, "L");
            }
        }
        fprintf(f, "\n");
    }
    fclose(f);
}

int prenota(int NF){
    int y, x, p;
    FILE *f;
    printf("\nInserisci il Posto la colonna da 1 a 10 : ");
    scanf("%d", &x);
    printf("\nInserisci la Fila da 1 a %d : ", NF);
    scanf("%d", &y);

    f = fopen("dati.txt", "r");
    if(f == NULL){
        printf("\nErrore Lettura file");
    }
    if(x < 1 || x > 10 || y < 1 || y > NF){
        printf("\nPosto Non Esistente");
        return 0;
    }
    p = check(f, x, y, NF);
    fclose(f);
    if(p == 0){
        printf("\nPosto Occupato");
        return 0;
    }else{
        fill(x, y,NF);
        return 1;
    }
}

void wait();

void m_prenota(int NF){
    int n;
    printf("\nInserisci numero di posti da prenotare : ");
    scanf("%d", &n);
    while(n > 0){
        if(prenota(NF) == 1){
            n--;
        }
    }
    wait();
}

int main(){
    int flag, i, NF, j;
    FILE *f;
    printf("\nInserisci 0 per riavviare : ");
    scanf("%d", &flag);
    if(flag == 0){
        printf("\nInserisci numero file max 1000:");
        scanf("%d", &NF);
        f = fopen("dati.txt", "w");
        for(i = 0; i < NF; i++){
            for(j = 0; j < NP; j++){
                fprintf(f, "L");
            }
            fprintf(f, "\n");
        }
        fclose(f);
    }
    if(flag !=0){
        int dimR = 0;
        char close = ' ';
        f = fopen("dati.txt", "r");
        while(feof(f) == 0){
            fscanf(f, "%c", &close);
            if(close == '\n'){
                dimR++;
            }
        }
        NF = dimR-1;
        printf("Numero di righe : %d", dimR-1);
        fclose(f);
    }
    m_prenota(NF);
    printf("\nInserisci 0 per terminare : ");
    wait();
    return 0;
}

void wait(){
    int flag;
    printf("\nClose. 1 Reload Main");
    scanf("%d", &flag);
    if(flag == 1){
        main();
    }
}
