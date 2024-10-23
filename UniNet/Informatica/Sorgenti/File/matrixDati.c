#include <stdio.h>
/*riga con cifra massima
  colonna con cifra minima*/

int dim_c(){
    FILE *f;
    char str[300];
    int i=0, dim = 1;
    f = fopen("dati.txt", "r");

    fgets(str, sizeof(str), f);
    printf("Stringa %s\n", str);

    for(;str[i]!='\0';i++){
        if(str[i]==' '){
            dim++;
        }
    }

    if(fclose(f)!=0){
        printf("Problemi di chiusura file");
    }
    return dim;
}
void min_max(int dim_c){
    FILE *f;
    int r_max, c_min, n, i=0, c=1;
    int dim1 = dim_c;
    int min = -1, max = -1;
    f = fopen("dati.txt", "r");

    while(feof(f)==0){
        fscanf(f, "%d", &n);
        //printf("%d\n", n);
        i++;
        if(min == -1 && max == -1){
            min = n;
            max = n;
            c_min = c;
            r_max = i;
        }
        if(n<min){
            c_min = i;
            min = n;
        }
        if(n>max){
            r_max = c;
            max = n;
        }
        if((i+1)==dim1){
            i=0;
            c++;
        }
    }
    printf("Riga %d(%d) colonna %d(%d)\n", r_max, max, c_min, min);
    if(fclose(f)!=0){
        printf("Problemi di chiusura file");
    }
}

int main(){
    int flag;
    int dim = dim_c()+1;
    printf("Colonne %d\n", dim);
    min_max(dim);
    scanf("%d", &flag);
    return 0;
}