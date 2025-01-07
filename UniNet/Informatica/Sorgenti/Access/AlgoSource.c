#include <stdio.h>
#include <stdlib.h>

void pointer();

void arr_ptr();

void struct_complex() {
    struct complex {
        double re, im;
    } c, *pc;
    c.re = 1.0;
    c.im = 2.0;
    pc = &c;
    printf("%f %f\n", pc->re, pc->im);
}

int main()
{
    //pointer();
    //arr_ptr();
    struct_complex();
    struct complex {
        double re, im;
    } c, *pc;
    return 0;
}

void arr_ptr(){
    int a[8], *aptr;
    aptr = a;
    printf("%d==%d\n", *(aptr+2), a[2]);
    //return 0;
}

void pointer(){
    int x, *px;
    int *py, *pz, a, b;
    int *pk;
    x = 5;
    px = &x;
    py = &a;
    pz = &b;
    pk = &x;
    pk = pk + 3;
    printf("Accesso Diretto x %d\n", x);
    printf("Accesso Indiretto *px %d\n", *px);
    printf("Indirizzo x %p\n", px);
    printf("Indirizzo diff pointer %d  == %d\n", (&a-&b), (py-pz));
    printf("Indirizzo pk %d & %p, pk+3 =%d & %p\n", px, px, pk, pk);
    //return 0;
}
