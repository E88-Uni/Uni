#include <stdio.h>

void f(int n){
    if(n <= 0){
        return;
    }
    f(n-2);
    printf(" %d ", n);
    f(n-1);
}

int main(){
    int flag;

    f(3);

    scanf("%d", &flag);
    return 0;
}