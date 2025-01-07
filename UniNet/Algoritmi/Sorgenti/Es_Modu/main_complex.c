#include "complex.h"
#include <stdio.h>


void operations(){
    double re, im;
    complex v1, v2, v3;
    printf("\n Inserisci 1° variabile re:");
    scanf("%lf", &re);
    printf("\n Inserisci 1° variabile im:");
    scanf("%lf", &im);
    v1 = new(re, im);
    printf("\n Inserisci 2° variabile re:");
    scanf("%lf", &re);
    printf("\n Inserisci 2° variabile im:");
    scanf("%lf", &im);
    v2 = new(re, im);

    v3 = add(v1, v2);
    printf("\nOperazioni Add:%lf i*%lf",v3.re, v3.im);
}
int main(){
    int flag;
    operations();
    scanf("%d", &flag);
    return 0;
}

/*
complex add(complex, complex);
complex sub(complex, complex);
complex mult(complex, complex);
complex quot(complex, complex);
double mod(complex);

 */
