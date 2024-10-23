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
Altezza Pari NON permette la visuale
*/
int int_rnd(int nMin, int nMax){
    int nRandonNumber = rand()%((nMax+1)-nMin) + nMin;
    return nRandonNumber;
}

/*da -1 a -10 nei bordi e procedo fino a -1 per il mare attorno all'isola */
int populate(isl IS){
    int h = 0, w = 0, d = DIM - 1, flag = -100, min;
    //Inizializzo l'isola
    while(h<DIM){
        while(w<DIM){
            IS->I[h][w].lat=h;
            IS->I[h][w].lon=w;
            IS->I[h][w].h = 0;
            w++;
        }
        w=0;
        h++;
    }
    h=0;
    //4 Bordi
    while(h<DIM){
        IS->I[h][0].h = int_rnd(-5,-1);
        IS->I[h][d].h = int_rnd(-5,-1);
        IS->I[0][h].h = int_rnd(-5,-1);
        IS->I[d][h].h = int_rnd(-5,-1);
        h++;
    }
    //Pulisco Angoli
    IS->I[0][0].h=(IS->I[1][0].h<IS->I[0][1].h)?IS->I[1][0].h:IS->I[0][1].h; 
    IS->I[d][0].h=(IS->I[d][1].h<IS->I[(d-1)][0].h)?IS->I[d][1].h:IS->I[(d-1)][0].h;
    IS->I[0][d].h=(IS->I[1][d].h<IS->I[0][(d-1)].h)?IS->I[1][d].h:IS->I[0][(d-1)].h;
    IS->I[d][d].h=(IS->I[d][(d-1)].h<IS->I[(d-1)][d].h)?IS->I[d][(d-1)].h:IS->I[(d-1)][d].h;
    //Inerisco il mare attorno
    h = 1, w = 1;
    while(h<d){
        min = 1;
        while(w<d){
            min = (IS->I[h-1][w].h<IS->I[h][w-1].h)?IS->I[h-1][w].h:IS->I[h][w-1].h;
            min = (IS->I[h+1][w].h<min)?IS->I[h+1][w].h:min;
            min = (IS->I[h][w+1].h<min)?IS->I[h][w+1].h:min;
            IS->I[h][w].h = min+1;
            w++;
        }
        w=1;
        h++;
    }
    h = d, w = d;
    while(h>0){
        min = 1;
        while(w>0){
            min = (IS->I[h-1][w].h<IS->I[h][w-1].h)?IS->I[h-1][w].h:IS->I[h][w-1].h;
            min = (IS->I[h+1][w].h<min)?IS->I[h+1][w].h:min;
            min = (IS->I[h][w+1].h<min)?IS->I[h][w+1].h:min;
            IS->I[h][w].h = min+1;
            w--;
        }
        w=d;
        h--;
    }
    //Interno Isola
    h = 0, w = 0;
    while(h<DIM){
        while(w<DIM){
            if(IS->I[h][w].h>0){
                IS->I[h][w].h = int_rnd(0,90);
            }
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
            if(IS->I[h][w].h<10 && IS->I[h][w].h>-1){
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

void find_max_nord_ovest(isl IS, pt max){
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

void find_max_sud_est(isl IS, pt max){
    int h = DIM, w = DIM;
    max->lat = 0;
    max->lon = 0;
    max->h = IS->I[(DIM-1)][(DIM-1)].h;
    while(h>0){
        h--;
        while(w>0){
            w--;
            if((IS->I[h][w].h)>(max->h)){
                max->lat = h;
                max->lon = w;
                max->h = IS->I[h][w].h;
            }
        }
        w = DIM;
    }
}

void tower(isl IS) {
    pt nord_ovest =(pt)malloc(sizeof(struct point));
    pt sud_est =(pt)malloc(sizeof(struct point));
    find_max_nord_ovest(IS, nord_ovest);
    find_max_sud_est(IS, sud_est);
    if(nord_ovest->lat == sud_est->lat && nord_ovest->lon == sud_est->lon){
        printf("\n Torre Nord-Est-Sud-Ovest (lat %d ,lon %d) h : %d\n",sud_est->lat, sud_est->lon, sud_est->h);
    }else{
        printf("\n Torre Sud-Est (lat %d ,lon %d) h : %d\n",sud_est->lat, sud_est->lon, sud_est->h);
        printf("\n Torre Nord-Ovest (lat %d ,lon %d) h : %d\n",nord_ovest->lat, nord_ovest->lon, nord_ovest->h);
    }
    free(nord_ovest);
    free(sud_est);
}

int main(){
    int is_pop = 0;
    isl IS = (isl)malloc(sizeof(struct isola));
    srand(time(NULL));
    is_pop = populate(IS);
    if(is_pop){
        printf("Popolamento Avvenuto con Sucesso\n");
        print_is(IS);
    }
    tower(IS);
    free(IS);
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