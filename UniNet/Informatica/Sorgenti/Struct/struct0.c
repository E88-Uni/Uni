#include <stdio.h>
#include <stdlib.h>

/*Definiscin città
Da tastiera Inserici Città(Nome, Pressione(int))
Calcola la città con pressione massima*/
#define N 5

typedef struct city{
    char name[20];
    int pressure;
} ct;

int main(){
    int i = 0,flag, id_max=0, max = 0;
    ct cities[N];
    for(;i<N;i++){
        printf("\n Inserisci la citta: ");
        scanf("%s", cities[i].name);
        printf("\n Inserisci la pressione: ");
        scanf("%d", &cities[i].pressure);
        if(cities[i].pressure>max){
            max = cities[i].pressure;
            id_max = i;
        }
    }
    printf("\n Citta con pressione massima: %s", cities[id_max].name);
    scanf("%d", &flag);
    return 0;
}