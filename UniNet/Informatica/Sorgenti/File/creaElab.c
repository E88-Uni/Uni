#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/*Crea file composto da n record 
Ogniuno ha elementi magazzino 3 campi :
Prodotto quantità prezzo(unitario) = str float int

Calcolo il prodotto maggiore (quantità*prezzo)
*/
int rnd(int min, int max){
    return rand() % (max - min + 1) + min;
}

void populate(FILE *f){
    char Product_List[6][20]={"Birra", "Vino", "Caffe", "Pane", "Latte", "Uova"};
    float price;
    int quant;
    for(int i=0; i<5; i++){
        fprintf(f, "%s ", Product_List[i]);
        quant = rnd(1, 10);
        fprintf(f, "%d ", quant);
        price = rnd(1, 100)+0.5;
        fprintf(f, "%.2f \n", price);
    }
}

void max_amount(FILE *f){
    char product[20];
    char max_product[20];
    int quant;
    float price;
    float max = 0.0;
    while(!feof(f)){
        fscanf(f, "%s %d %f", product, &quant, &price);
        if(quant*price > max){
            strcpy(max_product, product);
            max = quant*price;
        }
    }
    printf("Prodotto maggiore %s con quantità %d e prezzo %f = %f\n", max_product, quant, price, max);

} 

int main(){
    FILE *f;
    int flag;
    srand(time(NULL));
    f = fopen("magazzino.dat", "w");
    if(f==NULL){
        printf("Problemi di Apertura file");
    }
    populate(f);
    fclose(f);
    f = fopen("magazzino.dat", "r");
    if(f==NULL){
        printf("Problemi di Apertura file");
    }
    max_amount(f);
    fclose(f);
    scanf("%d", &flag);
    return 0;
}