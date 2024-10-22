#include <stdio.h>
#include <stdlib.h>
/*1. Binario -> Decimale*/
/*2. input N float -> media*/
void media(){
    float n = 0, i=0;
    float tot = 0;
    int flag;
    printf("0 Chiude il Programma\n");
    do{
        printf("Inserisci numero: ");
        scanf("%f", &n);
        flag = ((int)n)!=0;
        if(flag){
            tot += n;
            i++;
        }
    }while(flag);
    if(tot!=0){
        printf("Media: %f", tot/i);
    }else{
        printf("Media: 0");
    }
    
}
void bin(){
    int i, id, b2=1, n=0;;
    char bin[16];
    scanf("%[^\n]%*c", bin);
    for(id=0; bin[id]!='\0'; id++){}
    printf("Lunghezza: %d", id);
    for(i=id-1; i>=0; i--){
        n=n+(bin[i]-'0')*b2;
        b2 *= 2;
    }
    printf("\n%s = %d", bin, n);
}
void wait();
int main(){
    //media();
    bin();
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