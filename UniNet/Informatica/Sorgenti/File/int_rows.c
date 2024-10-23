#include <stdio.h>

int main(){
    FILE *f;
    int k;
    f = fopen("int_rows.txt", "r");
    while(feof(f)==0){
        fscanf(f,"%d", &k);
        printf(" %d ", k);
    }
    fclose(f);
    return 0;
}