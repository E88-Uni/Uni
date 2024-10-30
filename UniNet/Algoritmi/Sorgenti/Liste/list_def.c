#include <stdio.h>
#include <stdlib.h>
#define TipoElemento int

typedef struct lista{
    TipoElemento val;
    struct lista *next;
} *pl;

void iniz(pl *p){
    *p = NULL;
}
int ricerca(pl p, TipoElemento x){
    ///...
    return 1;
}