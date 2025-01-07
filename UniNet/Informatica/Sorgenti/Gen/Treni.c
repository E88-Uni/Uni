#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h> 
/*Sorgente gestione treni : Dato un orario ferroviario, si individui tutti i treni che entro due ore dall'ora prefissata raggiungano la meta desiderata. Orario : 
 1. Stazione Partenza : char[]
 2. Stazione Arrivo : char[]
 3. Ora di Partenza : int
 4. Minuto di Partenza : int

Numero totale delle linee : N.
Soluzione : 
 1. Tempo totale : in Minuti cioè 60*Ore + minuti
 2. Confronto e calcoli direttamente con minuti
 3. Stazione di Partenza è quella selezionata?
 4. ->NO-> Linea Sucessiva
 5. ->SI-> Controllo la stazione d'Arrivo? 
 6. ->NO-> Linea Sucessiva
 7. ->SI-> Controllo l'Orario, il treno è nelle 2 ore?
 8. ->NO-> Linea Sucessiva
 9. ->SI-> Salvo il Treno
 10. Non ci sono altre linee sucessive : Do i treni salvati
 11. Se non ci sono treni salvati lo dico
 12. Gestione Orario quando supera le 24.00*/
//strcmp(char *a, char *b) == 0 Equal

#define DIM 100
#define DIMCHAR 20

typedef struct train {
    char SP[DIMCHAR]; //Stazione Partenza
    char SA[DIMCHAR]; //Stazione Arrivo
    int pora, pmin;
    int aora, amin;
}* tr;


void wait();

int int_rnd(int nMin, int nMax){
    int nRandonNumber = rand()%((nMax+1)-nMin) + nMin;
    return nRandonNumber;
}

char *station_list(int i){
    if(i == 0){
        return "Milano";
    } else if(i == 1){
        return "Padova";
    } else { //i == 2
        return "Treviso";
    }
}


void station(tr TR){
    int i = int_rnd(0, 2);
    int i2= int_rnd(0, 2);
    while(i == i2){
        i2 = int_rnd(0, 2);
    }
    
    strcpy(TR->SP, station_list(i));
    strcpy(TR->SA, station_list(i2));
    
    TR->pora = int_rnd(0, 23);
    TR->pmin = int_rnd(0, 59);
    TR->aora = (TR->pora+int_rnd(1, 2));
    TR->aora = (TR->aora> 23)?(TR->aora-24):TR->aora;
    TR->amin = TR->pmin;
    
}

int populate(tr TR){
    int i = 0;
    
    printf("\nInizio Popolamento\n");
    while(i<DIM){
        station(&(TR[i]));
        i++;
    }
    printf("\nFine Popolamento\n");
    return 1;
}

/*
Controllo SP Stazione Arrivo if Milano
Controllo Arrivo se dentro le due ore es: dalle 23.00 (quindi fino alle 1.00) 
*/


void response(tr TR) {
    int i = 0;
    int tini = 19;
    int tend = tini+2;
    printf("Treni in arrivo a Milano nelle prossime 2 ore : %d.00 - %d.00", tini, tend);
    printf("\nStampa i Treni\n");
    while(i<DIM){
        tr TRIi = &(TR[i]);
        int flag_arrivo = (strcmp((TRIi->SA), "Milano")==0);
        int flag_time = (((TRIi->pora*60)+ TRIi->pmin)>=(tini*60))&&((TRIi->aora*60+ TRIi->amin)<=(tend*60))&&((TRIi->aora*60+ TRIi->amin)>=tini*60);
        if(flag_arrivo && flag_time){
            printf("Partenza (%d:%d): %s, Arrivo tra (%d:%d): %s \n", TRIi->pora, TRIi->pmin, TRIi->SP, TRIi->aora, TRIi->amin, TRIi->SA);
        }
        i++;
    }
}


void print_tr(tr TR) {
    int i = 0;
    printf("\nStampa i Treni per Milano\n");
    while(i<DIM){
        tr TRIi = &(TR[i]);
        int flag_arrivo = (strcmp((TRIi->SA), "Milano")==0);
        if(flag_arrivo){
            printf("Partenza (%d:%d): %s, Arrivo tra (%d:%d): %s \n", TRIi->pora, TRIi->pmin, TRIi->SP, TRIi->aora, TRIi->amin, TRIi->SA);
        }
        i++;
    }
}

int main(){
    int is_pop = 0;
    tr TR = (tr)malloc((sizeof(struct train))*DIM);
    srand(time(NULL));
    is_pop = populate(TR);

    if(is_pop){
        printf("\nPopolamento Avvenuto con Sucesso\n");
        print_tr(TR);
    }
    response(TR);
    free(TR);
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