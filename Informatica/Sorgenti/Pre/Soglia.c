#include <stdio.h>
/*Data una soglia s1<->s2
Inserisci n numeri da tastiera
Ritorna quanti numeri sono compresi nella soglia
Utilizza while e do-while*/
#define DIM 10
int main(){
    int s1, s2, i=0, c1=0, c2=0, n;
    printf("\nSoglia minima:");
    scanf("%d", &s1);
    printf("\nSoglia massima:");    
    scanf("%d", &s2);
    while(i<DIM){
        printf("\nInserisci un numero : ");
        scanf("%d", &n);
        if(s1<=n && n<=s2){
            c1++;
        }
        i++;
    }
    printf("\nNumeri compresi: %d", c1);
    i=0;
    do{
        printf("\nInserisci un numero : ");
        scanf("%d", &n);
        if(s1<=n && n<=s2){
            c2++;
        }
        i++;
    }while(i<DIM);
    printf("\nNumeri compresi: %d", c2);
    scanf("%d", &i);
    return 0;
}