#include <stdio.h>

int main(){
    FILE *f;
    FILE *fw;
    int x, y;
    f = fopen("estremi.dat", "r");
    fw = fopen("diff.dat", "w");
    if(f==NULL || fw==NULL){
        printf("Problemi di Apertura file");
    }
    while(feof(f) == 0){
        fscanf(f,"%d %d", &x, &y);
        fprintf(fw," %d ", x-y);
    }
     if(fclose(f)!=0){
        printf("Problemi di Chiusura file letto");
    }
    if(fclose(fw)!=0){
        printf("Problemi di Chiusura file scritto");
    }
    return 0;
}