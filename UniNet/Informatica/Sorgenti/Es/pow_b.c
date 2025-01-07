#include <stdio.h>

float pow_b(int a, int b){
    if(b==0){
        return 1;
    }else if(b>0){
        return a*pow_b(a, --b);
    }else{
        return (1.0/a)*pow_b(a, ++b);
    }
}

int main(){
    int a, b;
    float n;
    printf("Inserisci a alla b :");
    scanf("%d %d", &a, &b);
    n = pow_b(a, b);
    printf("\n %d^%d = %f", a, b, n);
    scanf("%d",&n);
    return 0;
}