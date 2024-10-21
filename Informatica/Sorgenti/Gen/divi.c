// Online C compiler to run C program online
#include <stdio.h>

//div per 3 e 8
int main() {
    int n, b;
    printf("Inserisco n:");
    scanf("%d",&n);
    if((n%3)==0 && (n%8)==0){
         printf("%d div per 3 e 8",n);
    }else{
        printf("Non div per 3 e 8");
    }
    return 0;
}