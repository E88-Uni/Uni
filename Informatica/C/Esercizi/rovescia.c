#include <stdio.h>
//Input stringa -> rovesca
#define DIM 100

void swap(char *a, char *b){
    char Temp = *a;
    *a = *b;
    *b = Temp;
}

int main(){
    char str[DIM];
    int i = 0, flag, dim=1, middel;
    scanf("%s", str);
    while (str[dim]!='\0'){
        dim++;
    }
    middel = dim/2;//'abc'4/2 =2
    for(i=0; i<middel; i++){
        swap(str+i, (str+dim-1)-i);
    }
    printf("%s", str);
    scanf("%d", &flag);
    return 0;
}
