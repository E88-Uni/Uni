#include <stdio.h>
#define N 10
/*
Leggere vettore di N elem e 
*/
int main(){
    int i, v[N], pari = 0, dispari = 0;
    for(i=0; i<N; i++){
        printf("Inserisci elemento %d : ", i);
        scanf("%d", &v[i]);
        ((v[i] % 2) == 0)? pari++ : dispari++;
    }
    printf("Pari : %d Dispari : %d", pari, dispari);
    scanf("%d", &i);
    return 0;
}