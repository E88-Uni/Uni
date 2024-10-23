#include <stdio.h>
#include <time.h>
#include <stdlib.h>
/*
Data Una matrici ritornare colonna e riga con numero pari maggiore
*/
#define NA 8
#define NB 10

float random_float(float min, float max) {
    float scale = rand() / (float) RAND_MAX; // Generate a random float between 0 and 1
    return min + scale * (max - min); // Scale it to the desired range
}

void printA(double V[], int dim){
    int i = 0;
    printf("\n");
    for(; i<dim; i++){
        printf(" %lf ",V[i]);
    }
    printf("\n");
}

double media(double v[], int len){
    double media = 0.0;
    int i = 0;
    for(; i<len; i++){
        media +=v[i];
    }
    return media/len;
}

void wait();
int main(){
    double A[NA];
    double B[NB];
    int i, mediA, mediB;
    srand(time(NULL));
    for(i=0; i<NA; i++){
        A[i] = random_float(0.0, 5.0);
    }
    for(i=0; i<NB; i++){
        B[i] = random_float(5.0, 10.0);
    }
    printA(A, NA);
    printA(B, NB);

    printf("Medie A : %lf . B : %lf", media(A, NA), media(B, NB));

    wait();
    return 0;
}
void wait(){
    int flag = 0;
    printf("\n 1 new run");
    scanf("%d", &flag);
    if(flag == 1){
        printf("\n");
        main();
    }
}