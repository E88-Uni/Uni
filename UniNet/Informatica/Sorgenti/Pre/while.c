#include <stdio.h>
#include <stdlib.h>

void media(){
    int i = 0, n;
    float media, ssum=0, ni;
    printf("Inserisci numero cicli: ");
    scanf("%d", &n);
    if(n<1){
        printf("Numero cicli non valido");
        return;
    }
    while(i < n){
        printf("\nNumero[%d]:", i);
        scanf("%f", &ni);
        ssum += ni;
        i++;
    }
    media = ssum / n;
    printf("\nMedia: %f", media);
}

void do_while(){
    float sum=0, max = 500, n;
    do{
        printf("Inserisci n:");
        scanf("%f", &n);
        sum += n;
    }while(n && sum<=max);
    printf("\nSomma: %f", sum);
}

void suc_media(){//successione media
    int i = 0, sum = 0, n;
    float media, ssum;
    printf("Inserisci numero cicli: ");
    scanf("%d", &n);
    if(n<1){
        printf("Numero cicli non valido");
        return;
    }
    while(i < n){
        i++;
        printf("\nNumero: %d", i);
        sum += i;
    }
    ssum = sum;//pre media float e non int
    media = ssum / n;
    printf("\nMedia: %f", media);
}

void max(){
    int i = 0, n, flag = 1;
    float max, ni;
    printf("Inserisci numero cicli: ");
    scanf("%d", &n);
    if(n<1){
        printf("Numero cicli non valido");
        return;
    }
    while(i < n){
        printf("\nNumero[%d]:", i);
        scanf("%f", &ni);
        if(flag){
            max = ni;
            flag=0;
        }
        max = (ni > max )? ni : max;
        i++;
    }
    printf("\nMax: %f", max);
}

int main(){
    int n;
    float sum;
    //suc_media();
    //media();
    //max();
    do_while();
    sum = (float)100/30;
    printf("\nSum: %f", sum);
    scanf("%d", &n);
    return 0;
}