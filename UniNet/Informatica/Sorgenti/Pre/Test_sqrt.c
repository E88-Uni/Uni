#include <stdio.h>
#include <math.h>

void wait();

int main(){
    float a;
    test();//togli
    printf("Inserisci a ");
    scanf("%f", &a);
    printf("\n Sqrt a = %9.6f", sqrt(a));
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