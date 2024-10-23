#include <stdio.h>
/*
Dato un vettore
Calcola media e varianza
1. Media 
2. Somma+=(xi-media)^2
3. Varianza = Somma/dim
*/

float varianza(int A[], int dim, float *media){
    float m = 0.0, sum = 0.0; 
    int i=0;
    for(; i<dim; i++){
        m += A[i];
    }
    m = m/dim;
    *media = m;
    for(i=0; i<dim; i++){
        sum += ((A[i]-m)*(A[i]-m));
    }
    return sum/dim;
}

int main(){
    int A[5] = {10, 12, 23 , 23, 16};
    float media = 0;
    int flag;
    float varz = varianza(A, 5, &media);
    printf("media : %f, varianza %f", media, varz);
    scanf("%d", &flag);
    return 0;
}