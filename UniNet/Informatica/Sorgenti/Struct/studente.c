#include <stdio.h>
#include <stdlib.h>

/*Definisci tipo studente
Alloca 10 student
'int ContaInsufficenti(Stude)'
*/
#define N 5// 10

typedef struct {
    char Nome[20];
    int voto;
} Stude;

int ContaInsufficenti(Stude stu[]) {
    int i, num = 18, counter = 0;
    for(i=0;i<N;i++) {
        if(stu[i].voto < 18) {
            counter++;  
        }
    }
    return counter;
}

int main() {
    Stude stu[N];
    int i, flag, counter = 0;
    for(i=0;i<N;i++) {
        printf("\nInserisci il nome: ");
        scanf("%s", stu[i].Nome);
        printf("\nInserisci il voto: ");
        scanf("%d", &stu[i].voto);
    }
    counter = ContaInsufficenti(stu);
    printf("Numero di studenti insufficenti: %d", counter); 
    scanf("%d", &flag);
    return 0;
}