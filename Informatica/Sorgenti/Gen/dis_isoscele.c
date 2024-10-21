#include <stdio.h>
#include <stdlib.h>
/*
Leggere da tastiera numeri !=0
Calcolare la somma dei numeri negativi 
e la somma dei numeri positivi
Prigramma termina dopo N iterazioni o con 0
*/
#define DIM 50
typedef struct coppia{
    int a, b;
}* cp;
void wait();
int check_isoscle(cp A, cp B, cp C){
    int l1,l2,l3;
    printf("(%d, %d), (%d, %d), (%d, %d)\n", A->a, A->b, B->a, B->b, C->a, C->b);
    l1=(A->a-B->a)*(A->a-B->a)+(A->b-B->b)*(A->b-B->b);
    l2=(B->a-C->a)*(B->a-C->a)+(B->b-C->b)*(B->b-C->b);
    l3=(C->a-A->a)*(C->a-A->a)+(C->b-A->b)*(C->b-A->b);
    if(l1==l2 || l2==l3 || l1==l3){
        printf("Il Triangolo e' isoscele\n");
        return 1;
    }else{
        printf("Il Triangolo non e' isoscele\n");
        return 0;
    }
}
/*
int find_x(int y, int x1, int y1, int x2, int y2){
    int max =(x1>x2)?x1:x2;
    int min =(x1<x2)?x1:x2;
    float line = (float)(((y-y1))/(y2-y1)*(x2-x1))+x1;
    float out = line/((int)line);
    int l = (int)((out>0.5)?line:line-1);
    if(max>=line && line>=min){
        return l;
    }else{
        return -1;
    }
} 

void dis_iso(cp A, cp B, cp C){
    int y, x1, x2, x3, j;
    for(y=DIM; y>=0; y--){
        x1 = find_x(y, A->a, A->b, B->a, B->b);
        x2 = find_x(y, A->a, A->b, C->a, C->b);
        x3 = find_x(y, B->a, B->b, C->a, C->b);
        printf("xs : %d %d %d\n", x1, x2, x3);
        for(j=0; j<DIM; j++){
            char c = (j==x1 || j==x2 || j==x3)? '*': ' ';
            printf("%c", c);
        }
        printf("\n");
    }
}
*/
void dis_point(cp A, cp B, cp C){
    int y1=A->a, x1=A->b, y2=B->a, x2=B->b, y3=C->a, x3=C->b;
    int i, j;
    for(i=DIM; i>=0; i--){
        for(j=0; j<DIM; j++){
            if(y1==i && x1==j){
                printf("X");
            }else if(y2==i && x2==j){
                printf("X");    
            }else if(y3==i && x3==j){
                printf("X");
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
}
//TODO: Genera 2 punti casuali e uniscili come isoscele

int main() {
    cp C = (cp)malloc(sizeof(struct coppia)*3);
    int l1, l2, l3, is_iso;
    printf("Primo Punto");
    scanf("%d", &C[0].a);
    scanf("%d", &C[0].b);
    printf("Secondo Punto Successivo");
    scanf("%d", &C[1].a);
    scanf("%d", &C[1].b);
    printf("Terzo Punto Successivo");
    scanf("%d", &C[2].a);
    scanf("%d", &C[2].b);
    //Check Isoscele
    is_iso=check_isoscle(C, C+1, C+2);
    if(is_iso==1){
        dis_point(C, C+1, C+2);
        //dis_iso(C, C+1, C+2);
    }
    wait();
    return 0;
}
void wait(){
    int n;
    printf("\nClose or 1 reload main");
    scanf("%d", &n);
    if(n==1){
        main();
    }
    printf("\n");
}