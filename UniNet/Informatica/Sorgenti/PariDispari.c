#include <stdio.h>
#include <stdlib.h>
void wait();
//Isoscele se 2 lati con la stessa lunghezza e quindi lo stesso angolo con la base
int main() {
    int a, pari=0, dispari=0;
    printf("Premi 0 per chiudere l'inserimento");
    scanf("%d",&a);
    while(a != 0){
        if((a%2)==0){
            pari++;
        }else{
            dispari++;
        }
        scanf("%d",&a);
    }
    printf("Hai inserito %d dispari, %d pari, totale:%d",dispari,pari,dispari+pari);
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