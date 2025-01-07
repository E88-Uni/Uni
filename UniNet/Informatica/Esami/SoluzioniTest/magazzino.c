#include <stdlib.h>
#include <stdio.h>
/*Esame modifica quantità e calcola totale
ES:
Chiodi 0,02 234
Pinze 4,50 22
*/
int strcompare(char *str1, char *str2){
    int i = 0;
    while(str1[i] !='\0'){
        if(str1[i] != str2[i])
            return 0;
        i++;
    }
    return 1;
}

void gestioneMagazzino(FILE *fpr, FILE *fpw){
    int quantita, plusqt,flag=0;
    float price, totale = 0.0, tot = 0.0;
    char prodotto[30], nameprod[30];
    printf("Inserisci il nome del prodotto: ");
    scanf("%s",nameprod);
    printf("Inserisci la quantita: ");
    scanf("%d",&plusqt);

    while(!feof(fpr)){
        fscanf(fpr,"%s %f %d",prodotto, &price, &quantita);

        if(strcompare(nameprod, prodotto) && flag == 0){
            quantita = quantita + plusqt;
            flag = 1;
        }
        fprintf(fpw,"%s %f %d\n",prodotto, price, quantita);

        totale += quantita * price;
        if(quantita > 0){
            tot += quantita * price;
        }
    }
    if(flag == 0){
        printf("Prodotto non trovato\n");
    }
    printf("Totale: %f\n", totale);
    printf("Totale senza negativi: %f\n", tot);

}

int main(){
    FILE *fpr, *fpw;
    char nameFilew[30], nameFiler[30];
    int flag;
    printf("Inserisci il nome del file da leggere: ");
    scanf("%s",nameFiler);
    printf("Inserisci il nome del file da scrivere: ");
    scanf("%s",nameFilew);

    fpr = fopen(nameFiler,"r");
    fpw = fopen(nameFilew,"w");

    gestioneMagazzino(fpr, fpw);

    fclose(fpr);
    fclose(fpw);
    scanf("%d",&flag);
    return 0;
}
