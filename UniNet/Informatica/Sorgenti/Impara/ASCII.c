#include <stdio.h>

//A<a
char up_down(char a){
    if(a<='Z'){
        return a+('a'-'A');
    }
    return a+('A'-'a');
}

int main(){
    int d_ascii = 'A'-'a', flag;
    char a1 = 'A';
    char a2 = 'a';
    char a3 = getchar();
    printf("A:%c . a:%c . a3:%c\n", up_down(a1), up_down(a2), a3);
    scanf("%d", &flag);
    return 0;
}