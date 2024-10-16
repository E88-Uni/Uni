#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*Esercizi :
3. e^x = 1 + x + x^2/2! + x^3/3! + x^4/4! + ...*/
#define DIM 5

int fact(int n){
    if(n==0){
        return 1;
    }else{
        return n*fact(n-1);
    }
}
float exp_x(int x){
    float e = 1+x;
    int i=2;
    do{
        e+=(pow(x,i)/fact(i));
    }while(i++<DIM);
    return e;
}


void wait();
int main(){
    int n;
    printf("e^x ; Inserisci x :");
    scanf("%d", &n);
    printf("\ne^%d : %f", n, exp_x(n));
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