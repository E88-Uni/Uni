# 0 Argomenti

1. C Avanzato
2. Allocazione Dinamica della Memoria
3. Ricorsione e Programmi Ricorsivi
4. Programmazione Modulare
5. Liste Lineari 
6. Dati Astratti - Pile e Code
7. Dati Astratti - Code a Priorità e Alberi
8. Algoritmi Introduzione e Definizioni
9. Analisi di  Complessità
10. Analisi di Programmi Ricorsivi - Ricorrenze
11. Algoritmi di Ordinamento
12. Insiemi Dinamici e Dizionari
13. Alberi Binari di Ricerca
14. Tabelle Hash
15. Paradigmi Algoritmici : Programmazione Dinamica
16. Paradigmi Algoritmici : Paradigma Greedy
17. Paradigmi Algoritmici : Backtracking
18. Grafi
19. Visite di Grafi
20. Alberi di Copertura Minimi
21. Percorsi Minimi di un Grafo
22. Teoria della Complessità
23. NP Completezza e Algoritmi Approssimati

TODO : Aggancia file source a capitoli

# 1 C Avanzato
Source : Algoritmi
## Obbiettivi
1. Quali sono le migliori strutture dati da adottare? Che prestazioni hanno?
2. Algoritmi Generali per Problemi Pratici
3. Programmazione Avanzata in C (Lez.1-8)
4. Paradigmi Algoritmici, riutilizzo di strutture dati e processi. Problemi Classici
5. Puntatori e Vettori, stringhe, strutture e tipi aggregati

CodeBlock Piattaforma

## Puntatori
Ogni tipo di variabile ha il suo puntatore perchè l'inidirzzo puntato è diverso in lunghezza/grandezza/struttura. 
- **Accesso** Diretto o Indiretto con operatore di Indirezine '*'
- **Operatore** di Idirizzo '&'
```c
<tipo> '*' <identificatore>
int x, int *px;
double v, double *pv;
px = &x; pv = &v; 
y = x; //Accesso Diretto - Per Variabile
yv = *pv; //Accesso Indiretto - Per Punatore con Operatore di Indirezione
```
- **Stampa Puntatore** %p in esadecimale, %d in decimale
```c
printf("%p == %p != %d", &x, px, px);
```

### Operazioni Puntatori
SI :
Assegnazione a costante non valida;
```c
p = NULL; //Unica Asegnazione a cosstante valida
p++, p+2, p--, p-4;
px-py;
px==py;
```
NO :
```c
p = 3;
px+py;//out of range
px-ppy;//different pointer
```
### Aritmentica dei puntatori
Il punatore se incrementato o decrementato fa i 'salti' a seconda della memoria occupata dalla variabile puntata.
Se vuoi la dimensione puntata fa sizeof(p);
```c
int *px; //1000
px+=3; //1012 : 1000+4*3, sizeof(int) = 4
```
### Accesso
Tramite Indirizzo : A[8]
Tramite Puntatore detto Scostamento o offset : *(A+8)
Mai sovrascrivere puntatore già inizializzato : A+=8 NO
### Stringhe 
```c
char s[] = "Ciao";
char ps* = "Ciao";
//Entrambe con concludono con '\0' 
char sA[5] = {'C', 'i', 'a', 'o', '\0'};
#include <string.h>
strlen(s);//5
strcpy(dest, src);
strcat(dest, src);//Concatenazione
strcmp(s1, s2);//0 se uguali
```
### Struct
Si usa -> per accesso alla struttura da puntatore
Si usa . per accesso alla struttura da variabile
```c
struct complex {
    double re, im;
} c, *pc;
c.re = 1.0; c.im = 2.0;
pc = &c;
printf("%.2f %.2f", pc->re, pc->im);
```

# 2 Allocazione Dinamica della Memoria
Source : Malloc
**Se Statica :** non ridimensionqbile, allocazione all'inizio del programma e svuotata al termine, tra [] solo con costanti o #define.
**Se Dinamica :** ridimensionabile, allocazione solo memoria necessaria e svuotata quando necessario.
    - **free** OBBLIGATORIO
    - IF(pointer == NULL) OBBLIGATORIO

```c
    int dim = 10;
    int *p = (int *)malloc(dim*sizeof(int));
    if(p == NULL) { printf("Memoria non disponibile"); return; }
    free(p);

    typedef struct {
        int val;
        char nome[20];
    } ogg, *pogg;
    pogg p = (pogg)malloc(sizeof(ogg));
    if(p == NULL) { printf("Memoria non disponibile"); return; }
    free(p);
```
### calloc
Inizializza tutte le celle a 0
```c
    int *p = (int *)calloc(100, sizeof(int));
```
### realloc
Cambia dimensione allocata per il punatore
```c
    char *pa = (char *)malloc(sizeof(char)*10);
    pa = (char *)realloc(pa, sizeof(char)*5); //Dim : 10->5
    pa = (char *)realloc(pa, sizeof(char)*50); //Dim : 5->50
```
### Esempio
```c
int n, *pn;
printf("Dimensione: "); scanf("%d", &n);
if(n>0 && n<=100) {
    pn = (int *)malloc(n*sizeof(int));
    if(pn != NULL) {
        printf("Allocazione Avvenuta");
    }
}
```
## Modello di Memoria
I dati allocati dinamicamente stanno in un area di memoria diversa da
quelli allocati staticamente.

**Esistono 3 Sezioni di Memoria :**
1. **TEXT :** Codice(Istruzioni) + Dati Statici(static)
2. **STACK :** Dati Automatici ('normali' es. int x) + Dati Globali (#define) + Traccia Chiamate a Funzione. Memoria che parte dall'alto in discesa 
3. **HEAP :** Dati Allocati Dinamicamente. Memoria che parte dal basso in salita

## Problemi Memoria Dinamica
### Perdita Riferimenti
Se si perde il riferimento alla memoria. Impossibile free -> generazione **garbage**

### Riferimenti Fluttuanti
Quando il puntatore di memoria punta a un area che è stata deallocata

```c
p1 = (int *)malloc(sizeof(int)*10);
p2 = NULL; p1 = p2;//Perdita Riferimenti

p1 = (int *)malloc(sizeof(int)*10);
p2 = p1; free(p2);//Riferimenti Fluttuanti
```

# 3 Ricorsione e Programmi Ricorsivi
Source : Ricorsivi

- Ricorsione Diretta : f(){ f(); }
- Ricorsione Indiretta : f(){ g(); } g(){ f(); }
## Motivazioni
- Esprimere un insieme infinito per mezzo di un'istruzione finita
- Essenziale gestire la terminazione
- Problemi Reali e in Natura spesso ricorsivi
- Elegnza Matematica della Soluzione 
- Quando una funzione invoca più volte se stessa
- Si Opera su Strutture Dati Ricorsive

## Schema
Caso base + n' < n
```c
f(n){
    int case = ...;
    if(case) { 
        return; /*Caso Terminale*/
    }else {
        /*Operazioni*/
        f(n'); /*Con n' < n */
        /* f(n'') ... f(n''') Possibili più chiamate ricorsive */
    }
}
```
## Approccio Ricorsivo
1. Top-Down : Albero con radice corrispondente alla prima chiamata
2. Bottom-Up : Si parte dai casi elementari
```c
int fib_top_down(int n) {
    if(n<=1) { return n;
    }else{
        return fib_top_down(n-1) + fib_top_down(n-2);
    }
}

int fib_bottom_up(int n, int a, int b) {
    if (n == 0){ return a;
    } else if(n == 1){ return b;
    } else { 
        return fib_bottom_up(n-1, b, a+b);
    }
}
int init_bottom_up(int n) {
    return fib_bottom_up(n, 0, 1);
}
```
## Efficenza - Frame
Ad ogni chiamata a funzione viene allocato un **frame** sullo **stack** 
detto **record di attivazione** contiene le info rigiuardanti le chiamate a funzione.

Frame minimo solo il record di attivazione della funzione main

### Frame dello Stack
Si svuota e si riempe dinamicamente a seconda di Variabili Automatiche e Funzioni :
1. Parametri Fondamentali
2. Variabili Locali
3. Indirizzo di Ritorno : Gestisce 'salti' nel codice
4. Innidirizzo del codice della funzione : Puntatore alla prima istruzione della funzione

Funzioni Impropriamente ricorsive possono riempire lo stack, perchè ad ogni chiamata corrisponde un frame.
```c
int fatt(int n) {
    if(n<=1) { return 1;
    }else{
        return n*fatt(n-1);
    }
}
``` 

Una soluzione ricorsiva ha sempre una corrispettiva iterativa.

# 4 Programmazione Modulare
Source : Modulare

## Gestione Progetti
NO FILE UNICO :
- Lenta Compilazione
- Difficile riutilizzare il codice
- Difficile tenere traccia delle modifiche

**Linker :** Collega i file .h all'eseguibile
- Possono essere librerie standard : #include <math.h>
- Librerie personalizzate :
  - Creo un file .h con funzioni e variabili
  - Creo un file c con implementazioni
  - Lo compilo
  - Chiamo nel funzioni e variabili esterne con #include <mylib.h>

