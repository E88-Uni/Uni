#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*Esercizi :
2. Disegna un Triangolo Isoscele con il while ed equilatero con il for*/
#define MAX 100

void do_draw(int l){
    int y=0, x1=0, x2=l, i;
    y=l;
    printf("\n");
    while(y--){
        i=0;
        while(i<=l){
            if(i>=x1 && i<=x2){
                printf("*");
            }else{
                printf(" ");
            }
            i++;
        }
        x1++;
        x2--;
        if(x1>x2){
            y=0;
        }
        printf("\n");
    }
}


/*Quanti pixel stampare 
Ad ogni metà 3 volte meno pixel*/
void wait();
int main(){
    int l;
    printf("Lunghezza lato : ");
    scanf("%d", &l);
    do_draw(l);//Isoscele
    //for_draw(l);//equilatero
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