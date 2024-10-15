#include <stdio.h>
#include <math.h>

void wait();

void solve(int a, int b, int c){
    int delta2;
    float delta, x1, x2; 
    if(a == 0){
        if(b == 0){
            printf("\nEquazione non valida\n");
        }else{
            printf("\nEquazione di primo grado");
            printf(" x = %d\n", -c/b);
        }  
    }else{
        delta2 = (b*b) - (4*a*c);
        if(delta2 < 0){
            printf("\nL'Equazione non ha soluzioni Reali\n");
        }else{
            if(delta2 == 0){
                x1 = (-b)/(2*a);
                printf("\nSoluzione Unica x = %9.6f", x1);
            }else{
                delta = sqrt(delta2);
                x1 = (-b + delta)/(2*a);
                x2 = (-b - delta)/(2*a);
                printf("x1 = %9.6f, x2 = %9.6f", x1, x2);
            }
        }
    }
    printf("\nClose");
}
int main(){
    int a, b, c;
    printf("Con ax^2 + bx + c = 0, Inserisci i tre numeri: ");
    scanf("%d %d %d", &a, &b, &c);
    solve(a, b, c);

    wait();
    return 0;
}

void wait(){
    int flag;
    printf("\nChiusura a Tasto");
    scanf("%d", &flag);
}