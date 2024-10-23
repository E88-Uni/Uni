#include <stdio.h>
#include <stdlib.h>
/*Esercizi :
1. Creare la Serie di Fibonacci*/
#define MAX 100
long long int fib(int n){
    long long int N[MAX], i=2;
    N[0]=0;
    N[1]=1;
    for(; i<=n; i++){
        N[i]=N[i-1]+N[i-2];
    }
    return N[n];

}

int rico_fib(int n){
    if(n==0 || n==1){
        return n;
    }else{
        return fib(n-1)+fib(n-2);
    }
}
void wait();
int main(){
    int n, i;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        printf("%lli ", fib(i));
    }
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