#include <stdio.h>

int main(){
    FILE *f;
    char str[81];
    f = fopen("multi_rows.txt", "r");
    while(fgets(str, 80, f)!=NULL){
        printf(" %s ", str);
    }
    fclose(f);
    return 0;
}