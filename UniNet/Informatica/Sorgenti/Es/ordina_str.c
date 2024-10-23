#include <stdio.h>
#include <string.h>
#define N 10

void str_swap(char *A, char *B){
    char temp[30];
    strcpy(temp, A);
    strcpy(A, B);
    strcpy(B, temp);
}

void bubble_sort(char A[N][30], int dim){
    int i = 0, j, k;
    for(; i<dim-1;i++){
        for(j=0; j<dim-i-1;j++){
            if(A[j][0]>A[j+1][0]){
                char temp[30];
                strcpy(temp, A+j);
                strcpy(A+j, A+j+1);
                strcpy(A+j+1, temp);
            }else{
                int len = strlen(A[j]);
                for(k=1; k<len; k++){
                    if(A[j][k]>A[j+1][k]){
                        char temp[30];
                        strcpy(temp, A+j);
                        strcpy(A+j, A+j+1);
                        strcpy(A+j+1, temp);
                        k=len;
                    }
                }
            }
        }
    }
}
// '0'->'9' . 'A'->'Z' . 'a'->'z'
char *ordina(char V[N][30], int dim){
    //Bubble Sort con while interno se campi uguali fino a '\0

}

int main(){
    char V[N][30];
    int flag=1, i=0, dim=0;
    for(; i<N &&flag!=0; i++){
        printf("\nInserisci stringa[%d]\n", i);
        scanf("%s", V[i]);
        dim++;
        printf("\n0 per non reinserire: ");
        scanf("%d", &flag);
    }

    for(i = 0; i<dim; i++){
        printf("\ntringa[%d]: %s\n", i, V[i]);
    }

    scanf("%d", &flag);
    return 0;
}