# Allocazione Dinamica Memoria
Gestione espilicita della memoria, allocazione e rilascio dinamico.
**Se Statica** non è ridimensionabile, inoltre viene allocata al inizio del programma e svuotata al termine.
Vantaggi Dinamica :
 - Allocare solo la memoria necessaria
 - Decidere temporalmente quando allocare, deallocare e reallocare

## mallooc MemoriAllocation
Ritorna un puntatore generico dato in input i Byte da allocare
Necessità di Casting type puntatore 
```c
    void *malloc(dimensione);//void* Puntatore generico
    int *p = (int *)malloc(sizeof(int)*dim);//Essendo 4 Byte per intero o 8Byte double
    char *pa = (char *)malloc(10); //Essendo 1Byte per carattere
    if(p == NULL){
        printf("Memoria non disponibile");
        return -1;
    }
    free(p);free(pa);
```

### Allocazione struct
```c
    typedef struct {
        int val;
        char nome[20];
    } ogg, *pogg;
    pogg p;
    p = (pogg)malloc(sizeof(ogg)*10);//20+4Byte = 24Byte*10
    free(p);
```
## free
Ad ogni malloc -> void free(puntatore). 
Funziona solo con puntatori allocati con malloc

## Inizializzazione
clear alloc : void *calloc(dim);
Iniziallizza tutte le celle Byte a 0 binario
```c
    char *cp = (char *)calloc(10);//tutte celle Ascii 0
```

### Cambiare Dimensione puntatore
re alloc : void *reallc(pointer, dim);
Cambia la dimensione allocata del puntatore in dim
```c
    char *pa = (char *)malloc(10);
    pa = (char *)realloc(pa, 100);//dim pa da 10 a 100 celle
    pa = (char *)realloc(pa, 5);//dim pa da 100 a 5 celle
    p_malloc = (int *)realloc(NULL, 40);//dim pa da 10 a 100 celle
```
### Esempio
Non potendo allocare in runtime es: NO int n = 5 -> M[n] //n non è costante o define
```c
    int n;
    int *pn;
    printf("\nQuati interi servono? :");
    scanf("%d", &n);
    if(n>0 && n<=100){
        pn = (int *)malloc(sizeof(int)*100);
        p[0] = 1;
        if(pn != NULL){
            printf("\nAllocazione avvenuta locazione(%p) pn[0]: %d",pn, pn[0]);
        }else{
            printf("\nMemoria non disponibile");
        }
        free(pn);
    }else{
        printf("Dimensione non valida");
    }
```

## Modello di Memoria
I dati allocati Dinamicamente si trovano in un area diversa di memoria rispetto a quelli dichiarati staticamente. 

Esistono 3 **Sezioni** di **Memoria**
 - **TEXT** : Codice(Istruzioni) + Dati Statici (static)
 - **STACK** : Dati Automatici (normali es. int x)+ Dati Globali (#define) + Traccia Chiamate a Funzione
 - **HEAP** : Dati Allocati Dinamicamente

 ![alt text](img\SezioniMemoria.PNG)

## Possibili Problemi Memoria Dinamica
### Perdita Riferimenti
Memoria allocata ma non si ha più il puntatore a quell'area di memoria -> generazione **garbage**
```c
    int *p1, *p2;
    p1 = (int *)malloc(sizeof(int)*10);
    p1 = p2;//Ho perso il riferimento
```
### Riferimenti Fluttuanti
Riferimenti errati perchè a zone di memoria inesistenti
```c
    int *p1, *p2;
    p1 = (int *)malloc(sizeof(int)*10);
    p2 = p1;
    free(p2);//Ho perso la memoria p1
```
Fai Es File -> Lez 3