#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define DIM 20
#define TRUE 1
#define FALSE 0

typedef struct point {
    int lat, lon;
    int h;
}* pt;

typedef struct isola {
    struct point I[DIM][DIM];
}* isl;

void wait();

/*
Isola che sta dentro 100m x 100m : ogni blocco ha l'altezza dal livello del mare.
Massimo della colonna è anche masimo della riga? Se si vedo il mare.
Fai da 1 a 4 torri per vedere il mare : max -> 2 torri riga massimo e colonna massimo
 0. Tutto Isola
 1. Altezza Pari permette la visuale
 2. Altezza Pari NON permette la visuale
*/
int int_rnd(int nMin, int nMax){
    int nRandonNumber = rand()%((nMax+1)-nMin) + nMin;
    return nRandonNumber;
}

int populate(isl IS){
    int h = 0, w = 0;
    while(h<DIM){
        while(w<DIM){
            IS->I[h][w].lat=h;
            IS->I[h][w].lon=w;
            IS->I[h][w].h = int_rnd(0,99);
            w++;
        }
        w=0;
        h++;
    }
    return 1;
}

void print_is(isl IS){
    int h = 0, w = 0;
    while(h<DIM){
        while(w<DIM){
            if(IS->I[h][w].h<10){
                 printf(" 0%d ", IS->I[h][w].h);
            }else{
                 printf(" %d ", IS->I[h][w].h);
            }
            w++;
        }
        h++;
        w = 0;
        printf("\n");
    }
}

void find_max(isl IS, pt max){
    int h = 0, w = 0;
    max->lat = 0;
    max->lon = 0;
    max->h = IS->I[0][0].h;
    while(h<DIM){
        while(w<DIM){
            if((IS->I[h][w].h)>(max->h)){
                max->lat = h;
                max->lon = w;
                max->h = IS->I[h][w].h;
            }
            w++;
        }
        h++;
        w = 0;
    }
}

int main(){
    int is_pop = 0;
    pt max =(pt)malloc(sizeof(struct point));
    isl IS = (isl)malloc(sizeof(struct isola));
    srand(time(NULL));
    is_pop = populate(IS);
    if(is_pop){
        printf("Popolamento Avvenuto con Sucesso\n");
        print_is(IS);
    }
    find_max(IS, max);
    printf("\n Torre (lat %d ,lon %d) h : %d\n",max->lat, max->lon, max->h);
    wait();
    return 0;
}

void wait(){
    int flag;
    printf("\nChiusura a Tasto, 1 new run");
    scanf("%d", &flag);
    if(flag==1){
        main();
    }
}