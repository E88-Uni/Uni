#include <stdio.h>
#include <string.h>
/*
input stringa
Numero adiacenze c1 e c2 
numero singole lettere
*/
int main(){
    char str[30];
    char c1, c2;
    int coppia = 0, flag, dim, i, j;
    printf("Inserisci stringa : ");
    scanf("%s", str);
    printf("\n c1:");
    scanf("%c", &c1);
    printf("\n c2:");
    scanf("%c", &c2);

    dim = strlen(str);
    for(i=0; i<dim;i++){
        if((str[i]==c1 && str[i+1]==c2)||(str[i]==c2 && str[i+1]==c1)){
            coppia++;
        }
    }
    printf("Coppie(%c,%c):%n", c1, c2, coppia);

    for(i=(int)'a'; i<=(int)'z'; i++){
        int counter = 0;
        char c = (char)i;
        for(j=0;j<dim;j++){
            int diff = 'a'-'A';
            if(str[j]==c || str[j]==(char)(i+diff)){
                counter++;
            }
        }
        if(counter != 0){
            printf("\n%c : %d", c, counter);
        }
    }

    scanf("%d", &flag);
    return 0;
}