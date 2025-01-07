#include <stdio.h>
#include <time.h>
#include <stdlib.h> 
int rnd_int(int min, int max) {
    return rand()%(max-min+1)+min;
}

double randomDouble(double min, double max) {
    // Genera un numero casuale tra 0.0 e 1.0
    double scale = rand() / (double) RAND_MAX;
    // Ridimensiona il numero casuale tra min e max
    return min + scale * (max - min);
}


double media(double M[][10], int righe, int colonne){
    double somma = 0.0;
    int i=0, j;
    for(;i<righe;i++){
        for(j=0;j<colonne;j++){
            somma += M[i][j];
        }
    }

    printf("\nMedia: %f (%f/%d)\n", somma/(righe*colonne),somma, righe*colonne);

    return somma/(righe*colonne);
}

double populate(double M[][10], int righe, int colonne){
    int i=0, j;
    for(;i<righe;i++){
        for(j=0;j<colonne;j++){
            M[i][j] = randomDouble(0.0, 10.0);
            //M[i][j] = rnd_int(0, 10);
        }
    }
}

void printM(double M[][10], int righe, int colonne){
    int i=0, j;
    for(;i<righe;i++){
        for(j=0;j<colonne;j++){
            printf("%f ", M[i][j]);
        }
        printf("\n");
    }
}

double create(double M[][10], int righe, int colonne){
    populate(M, righe, 10);
    printM(M, righe, 10);
    return media(M, righe, 10);
}

int main(){
    int d1 = 8, d2 = 12, flag;
    double M1[d1][10];
    double M2[d2][10];
    double m1, m2;
    srand(time(NULL));
    m1 = create(M1, d1, 10);
    m2 = create(M1, d2, 10);
    printf("Medie M1 : %f . M2 : %f", m1, m2);
    scanf("%d", &flag);
    return 0;
}