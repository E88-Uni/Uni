#include <stdio.h>

void populate(int v[], int dim){
    int i = 0; 
    printf("\nInserisci il vettore: ");
    for(;i<dim;i++){
        scanf("%d", &v[i]);
    }
    printf("\n");
}

void v_sum(int v1[], int v2[], int vsum[], int dim){
    int i = 0;
    for(;i<dim;i++){
        vsum[i] = v1[i] + v2[i];
    }
}

void stampa(int v[], int dim){
    int i = 0; 
    printf("\n");
    for(;i<dim;i++){
        printf(" %d ", v[i]);
    }
    printf("\n");
}
void wait();

int main(){
    int dim, i, flag;
    int v1[100], v2[100], vsum[100];
    printf("Inserisci la dimensione dei vettori: ");
    scanf("%d", &dim);
    if(dim<0 || dim>100){
        printf("Dimensione non valida");
        wait();
        return 0;
    }
    populate(v1, dim);
    populate(v2, dim);
    v_sum(v1, v2, vsum, dim);

    stampa(v1, dim);
    stampa(v2, dim);
    stampa(vsum, dim);

    wait();
    return 0;
}

void wait(){
    int flag;
    printf("\n1 for reload");
    scanf("%d", &flag);
    if(flag == 1){
        main();
    }
}