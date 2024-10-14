#include <stdio.h>

int find_max(int a, int b);

int find_mcd(int a, int b);//Max Comun Divisore

int euclide_mcd(int a, int b);
int mcd(int a, int b);
void wait(){
    int flag;
    printf("\nChiusura a Tasto");
    scanf("%d", &flag);
}

int mcm(int a, int b) {
    return (a * b) / mcd(a, b);
}
int main(){
    int a, b, max, mcd, eucl_mcd;
    printf("Inserisci due numeri: ");
    scanf("%d %d", &a, &b);
    max = find_max(a, b);
    mcd = find_mcd(a, b);

    eucl_mcd = euclide_mcd(a, b);
    printf("\nEuclide( %d, %d )MCD = %d\n", a, b, eucl_mcd);

    wait();
    return 0;
}


int find_max(int a, int b) {
    int max;
    max = (a > b) ? a : b;
    printf("Massimo = %d", max);
    return max;
}

//Ciclo da n minore e controllo il resto della divisione
int find_mcd(int a, int b) {
    int mcd;
    mcd = (a < b) ? a : b;
    while(((b%mcd) != 0) || ((a%mcd) != 0)){
        mcd = mcd - 1;
    }
    printf("\n( %d, %d )MCD = %d\n", a, b, mcd);
    return mcd;
}


//Il Resto della divisione è direttamente legato al mcd
int euclide_mcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return euclide_mcd(b, a % b);
}

int mcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}