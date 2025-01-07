#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Date n coppie (n1, n2) ritronda le coppie
 con la somma massima e minima di n1 e n2*/
#define DIM 10
typedef struct coppia{
    int n1, n2;
    int somma;
}* cop;
void wait();

int int_rnd(int min, int max){
    return (rand()%(max-min+1))+min;
}

int populate(cop CP){
    int i = 0;
    while(i<DIM){
        CP[i].n1 = int_rnd(0,100);
        CP[i].n2 = int_rnd(0,100);
        CP[i].somma = CP[i].n1 + CP[i].n2;
        i++;
    }
    return 1;
}

int do_populate(cop CP){
    int i = 0;
    do{
        CP[i].n1 = int_rnd(0,100);
        CP[i].n2 = int_rnd(0,100);
        CP[i].somma = CP[i].n1 + CP[i].n2;
        i++;
    }while(i<DIM);
    return 1;
}

int results(cop CP){
    int i = 0, min = CP[0].somma, max = CP[0].somma;
    while(i<DIM){
        if(CP[i].somma < min){
            min = CP[i].somma;
        }
        if(CP[i].somma > max){
            max = CP[i].somma;
        }
        i++;
    }
    printf("\nCoppie con somma minima: %d\n", min);
    printf("Coppie con somma massima: %d\n", max);
    return 1;
}
int do_results(cop CP){
    int i = 0, min = CP[0].somma, max = CP[0].somma;
    do{
        if(CP[i].somma < min){
            min = CP[i].somma;
        }
        if(CP[i].somma > max){
            max = CP[i].somma;
        }
        i++;
    }while(i<DIM);
    printf("\nCoppie con somma minima: %d\n", min);
    printf("Coppie con somma massima: %d\n", max);
    return 1;
}

void cp_print(cop CP){
    int i = 0;
    do{
        printf("(%d, %d)=%d\n", CP[i].n1, CP[i].n2, CP[i].somma);
        i++;
    }while(i<DIM);
}

void heap_sort(cop CP, int dimHeap);

int main(){
    cop CP = (cop)malloc(sizeof(struct coppia)*DIM);
    int p = populate(CP);
    heap_sort(CP, DIM);
    cp_print(CP);
    srand(time(NULL));
    if(p){
        printf("\nPopolamento Avvenuto con Sucesso\n");
        results(CP);
    }else {
        printf("\nPopolamento Fallito\n");
    }
    
    p = do_populate(CP);
    heap_sort(CP, DIM);
    cp_print(CP);
    srand(time(NULL));
    if(p){
        printf("\nPopolamento Avvenuto con Sucesso\n");
        do_results(CP);
    }else {
        printf("\nPopolamento Fallito\n");
    }
    free(CP);
    wait();
    return 0;
}

void wait(){
    int n;
    printf("\nClose. 1 for reload main");
    scanf("%d", &n);
    if(n==1){
        main();
    }
    printf("\n");
}

void swap(cop CP, int i, int j){
    cop tmp = (cop)malloc(sizeof(struct coppia));

    tmp->n1 = CP[i].n1;
    tmp->n2 = CP[i].n2;
    tmp->somma = CP[i].somma;

    CP[i].n2 = CP[j].n2;
    CP[i].n1 = CP[j].n1;
    CP[i].somma = CP[j].somma;
    
    CP[j].n1 = tmp->n1;
    CP[j].n2 = tmp->n2;
    CP[j].somma = tmp->somma;

    free(tmp);
}

void max_heapify(cop CP, int dim, int idP){
    int k = 2*idP+1;
    if(k<dim){
        int idMax = k + (k+1!=dim && CP[k].somma < CP[k+1].somma);
        if(CP[idMax].somma > CP[idP].somma){
            swap(CP, idMax, idP);
            max_heapify(CP, dim, idMax);
        }
    }
}

void heap_sort(cop CP, int dimHeap){
    int i = dimHeap/2 -1;
    for(; i>=0; i--){
        max_heapify(CP, dimHeap, i);
    }
    for(i = dimHeap-1; i>=0; i--){
        swap(CP, i, 0);
        max_heapify(CP, i, 0);
    }
}