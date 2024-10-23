// Online C compiler to run C program online
#include <stdio.h>
void wait();
//Isoscele se 2 lati con la stessa lunghezza e quindi lo stesso angolo con la base
int main() {
    float a, b, c;
    printf("Inserisci la lunghezza dei 3 lati");
    scanf("%f %f %f",&a, &b, &c);
    if(a==b || b==c || a==c){
        printf("Il Triangolo è isoscele");
    }else{
        printf("Il Triangolo non è isoscele");
    }
    wait();
    return 0;
}

void wait(){
    int flag;
    printf("\nChiusura a Tasto, 1 new run");
    scanf("%d", &flag);
    if(flag==1){
        main();
    }
}