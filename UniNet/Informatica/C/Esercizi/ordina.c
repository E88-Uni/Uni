#include <stdio.h>
// ord = 0 decrescente
// ord = 1 crescente
void ordina(int v[], int len, int ord){
    int i = 0, j;
    for(i=0; i<len-1; i++){
        for(j=0; j<(len-i-1); j++){
            if((ord == 0 && v[j] < v[j+1]) ||(ord == 1 && v[j] > v[j+1])){
                int Temp = v[j];
                v[j] = v[j+1];
                v[j+1] = Temp;
            }
        }
    }
}
int main(){
    int v[] = {1, 32, 13, 4, 25, 6, 17, 8, 9, 10};
    int flag;
    ordina(v, 10, 0);
    printf("Decrescente : \n");
    for(int i=0; i<10; i++){
        printf("%d ", v[i]);
    }
    printf("\nCrescente : \n");
    ordina(v, 10, 1);
    for(int i=0; i<10; i++){
        printf("%d ", v[i]);
    }
    scanf("%d",&flag);
    return 0;
}