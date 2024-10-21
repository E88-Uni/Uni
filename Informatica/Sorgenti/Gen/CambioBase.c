#include <stdio.h>
#include <stdlib.h>

void converti(){
    char res[32];
    char simb[]="0123456789ABCDEF";
    int i = 0, n, b;
    
    printf("Inserisci numero: ");
    scanf("%d", &n);
    printf("Inserisci base: ");
    scanf("%d", &b);

    printf("\n%d in base %d = ", n, b);

    if(b<2 || b>16){
        printf("Base non consentita");
        return ;
    }

    if(n == 0){printf("0");return ;}
    while(n > 0){
        res[i++] = simb[n % b];
        n = n/b;
    }
    for(i = i-1; i >= 0; i--){
        printf("%c", res[i]);
    }
    printf("\nClose");
    scanf("%d", &i);

}
int main(){
    converti();
    return 0;
    
}