#include <stdio.h>
#include <string.h>
void str_min_max(char *v, int *min, int *max){
    int dim = strlen(v), i=0;
    *min = 0; *max=0;
    for(; i<dim; i++){
        int c = v[i];
        if(c>='A' && c<='Z'){
            *max=*max+1;
        }
        if(c>='a' && c<='z'){
            *min=*min+1;
        }
    }

}

int main(){
    int flag, min, max;
    char v[30];
    printf("Inserisci stringa :\n");
    scanf("%s", v);
    str_min_max(v, &min, &max);
    printf("\n%s\n Minuscole : %d . Maiuscole : %d", v, min, max);
    scanf("%d", &flag);
    return 0;
}