#include <stdio.h>
/*Cifrario di Cesare 
    1. stringa ->
    2. Chiave criptografica n
    3. All miniuscolo
    3. lettera n posizioni dopo 'z'->'a'
*/
#define DIM 10
char to_lower(char  c){
    if(c>='A' && c<= 'Z'){
        return c+('a'-'A');
    }else{
        return c;
    }
}

char cript(char c, int n){
    if(c>='a' && c<='z'){
        int mod_n=n%('a'-'z'+1);
        int an = c+mod_n;
        if(an>'z'){
            an = an -'z';
            an = 'a'+an;
        }
        return (char)an;
    }else{
        return c;
    }
}

int main(){
    char C[DIM];
    int i = 0, n, flag;
    printf("Inserisci stringa");
    scanf("%s", C);

    printf("\nInserisci n cifratura");
    scanf("%d", &n);
    for(i=0; i<DIM && (C[i]!='\0'); i++){
        C[i]=to_lower(C[i]);
        C[i]=cript(C[i], n);
    }
    printf("\n%s", C);
    scanf("%d", &flag);
    return 0;
}