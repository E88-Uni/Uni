#include <stdio.h>
/*
Leggere da tastiera numeri !=0
Calcolare la somma dei numeri negativi 
e la somma dei numeri positivi
Prigramma termina dopo N iterazioni o con 0
*/
#define N 10
void wait();
int main() {
    int n, neg=0, pos=0;
    scanf("%d", &n);
    while(n!=0){
        if(n<0){
            neg+=n;
        }
        else{
            pos+=n;
        }
        scanf("%d", &n);
    }
    printf("\nSomma neg: %d", neg);
    printf("\nSomma pos: %d", pos);
    wait();
    return 0;
}
void wait(){
    int n;
    printf("\nClose or 1 reload main");
    scanf("%d", &n);
    if(n==1){
        main();
    }
    printf("\n");
}