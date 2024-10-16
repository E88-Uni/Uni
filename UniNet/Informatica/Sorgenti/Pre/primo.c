#include <stdio.h>
#include <math.h>
void wait();

int prime(int n){
    int div = n-2;
    if(n==2){
        printf("\nE' primo");
        return 1;
    }
    if(n%2==0 || n==1 || n==0){
        printf("\nNon e' primo");
        return -1;
    }
    while(div>1){
        if(n%div==0){
            printf("\nNon e' primo");
            return -1;
        }
        div = div-2;
    }
    printf("\nE' primo");
    return 1;
}

int is_prime(int num) {
    if (num == 2) {
        return 1; // 2 è primo
    }
    if (num % 2 == 0 || num < 2) {
        return 0; // numeri pari maggiori di 2 non sono primi
    }
    // Controlla i divisori fino alla radice quadrata del numero
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}
int main(){
    int n;
    printf("Inserisci un numero: ");
    scanf("%d", &n);
    prime(n);
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