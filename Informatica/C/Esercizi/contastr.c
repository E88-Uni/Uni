#include <stdio.h>
//Conta quante volte è presente la sottostringa
#define DIM 100



int main(){
    char str[DIM], sub[DIM];
    int i = 0, flag, dim=1, middel, sdim=1, j, k, counter=0;
    printf("Inserisci stringa: ");
    scanf("%s", str);
    printf("\nInserisci stringa di ricerca: ");
    scanf("%s", sub);
    while (str[dim]!='\0'){
        dim++;
    }
    while (sub[sdim]!='\0'){
        sdim++;
    }
    for(i=0; i<dim; i++){
        k=i;
        j=0;
        while(i<dim && j<sdim && str[i]==str[j]){
            i++;
            j++;
            if(j+1>=sdim){
                counter++;
            }
        }
        i=k;
    }
    printf("Counter : %d", counter);
    scanf("%d", &flag);
    return 0;
}
