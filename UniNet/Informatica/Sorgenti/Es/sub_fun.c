#include <stdio.h>

int read(int min, int max);

int main(){
    int x, y;
    x = read(50, 100);
    y = read(1, 10);
    printf("\n x : %d,  y: %d", x, y);
    scanf("%d", &x);
    return 0;
}

int read(int min, int max){
    int n;
    if(min>max){
        return read(max,min);
    }
    printf("\nInserisci un numero tra %d e %d", min, max);
    scanf("%d", &n);
    printf("\n");
    if(n<=max && n>=min){
        return n;
    }else{
        printf("Non valido\n");
        return read(min, max);
    }
}