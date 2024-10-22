#include <stdio.h>
//Cancella caratteri duplicati
#define DIM 100

void swap(char *a, char *b){
    char Temp = *a;
    *a = *b;
    *b = Temp;
}

void delete(char str[], char c, int id, int dim){
    int i=id+1, j;
    for(; i<dim; i++){
        if(str[i]==c){
            for(j=i; j<dim; j++){
                swap(str+j, str+j+1);
            }
        }
    }
}

int main(){
    char str[DIM];
    int i = 0, dim=1, j, flag;
    printf("Inserisci stringa: ");
    scanf("%s", str);
    while (str[dim]!='\0'){
        dim++;
    }
    for(i=0; i<dim; i++){
        char c = str[i];
        delete(str, c, i, dim);
    }
    printf("\nStringa pulita : %s", str);
    scanf("%d", &flag);
    return 0;
}
