#include <stdio.h>
#define N 4
/*Stampa man mano che elabora se primi tra loro oppure no */

typedef struct cop{
    int n1, n2;
} *cp;

//la base sarà 18->2(9)->3(3)->3->1
//9->3->3->1
int next_prime(int n, int b){
    if(n==1){
        return 1;
    }else if(n%b==0){
        return b;
    }else{
        return next_prime(n, b++);
    }
}

void compare(cp C){
    int i;
    for(i=0; i<N; i++){
        int a = C->n1;
        int b = C->n2;
        int ba = 2, bb = 2;
        int pa = next_prime(a, ba);
        int pb = next_prime(b, bb);
        do{
            int 
        }while(a!=b && a != 1);
        
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