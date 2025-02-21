# 0 Argomenti

1. C Avanzato - Algoritmi.md
2. Allocazione Dinamica della Memoria - Malloc.md
3. Ricorsione e Programmi Ricorsivi - Ricorsivi.md
4. Programmazione Modulare - Modulare.md
5. Liste Lineari - Liste.md
6. Dati Astratti - Pile&Code.md
7. Dati Astratti - Code a Priorità e Alberi -Dizionari.md
8. Algoritmi Introduzione e Definizioni - AnalisiAlgoritmi.md
9. Analisi di  Complessità - AnalisiAlgoritmi.md
10. Analisi di Programmi Ricorsivi - Ricorrenze - CompleRicorsivi.md
11. Algoritmi di Ordinamento - Sort.md e Sort2.md
12. Insiemi Dinamici e Dizionari - Dizionari.md
13. Alberi Binari di Ricerca - BST.md
14. Tabelle Hash - Hash.md
15. Paradigmi Algoritmici : Programmazione Dinamica - ProgrammazioneDinamica.md
16. Paradigmi Algoritmici : Paradigma Greedy - Greedy.md
17. Paradigmi Algoritmici : Backtracking - Backtracking.md
18. Grafi - Grafi.md
19. Visite di Grafi - Grafi.md
20. Alberi di Copertura Minimi - Algoritmi2.md
21. Percorsi Minimi di un Grafo - PercorsiMinimi.md
22. Teoria della Complessità -  Complessità.md
23. NP Completezza e Algoritmi Approssimati - Problemi.md

TODO : Aggancia file source a capitoli
TODO: Tutorial

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

**Linker :** Collega i file oggetto (compilati) ad altri file oggetto 
contenenti variabili e funzioni definite per l'uso esterno 
- Possono essere librerie standard : #include <math.h>
- Librerie personalizzate :
  - Creo un file .h con funzioni e variabili
  - Creo un file c con implementazioni
  - Lo compilo
  - Chiamo nel funzioni e variabili esterne con #include <mylib.h>

## Modulo Oggetto
Contiene :
1. Codice Binario relativo al modulo Compilato
2. Riferimenti Esterni a Funzioni e Variabili dichiarate in Altri Moduli
3. Funzioni e Variabili utilizzabili da altri moduli

**Regola Progetto: Un solo main**

### Interfacce
Il Modulo può avere funzioni e variabili usabili ma definite altrove
- Variabili : <time.h> srand(time(NULL))
- Funzioni : <string.h> strcpy(str1, str2)
  
Dopo la compilazione si potranno usare solo Variabili e Funzioni definite e Richiamabili dall'esterno 
- rnd_int(min, max); wait();
- DIM_MAX

## Regole Visibilità
### Modularità
Ciascun Modulo :
1. Definisce Funzioni Private e Pubbliche
2. Definisce Variabili Private e Pubbliche
3. Chiama Funzioni e Variabili Esterne

### Funzioni Pubbliche
In C tutte le funzioni sono pubbliche, tranne se hanno **static** prima
Il modulo che usa la funzione deve chiamarla con **extern** così il **linker** farà il collegamento

Nel file.h : non vanno gli static, le variabili devono avere **extern** e
Il file.h si include con " : #include "mylib.h"
```c
/*mylib.h*/
void fprint(int);//Firma funzione
extern int Arr[100];

/*mylib.c*/
#include "mylib.h"
#include <stdio.h>

int Arr[100];
static int err;

void fprint(int info) { printf("%d", info); }
static void err_print() { 
    err = 404; 
    printf("Errore %d", err); 
}


/*main.c*/
#include "mylib.h"
#include <stdio.h>

extern void fprint(int);
extern int Arr[100];
int main() {
    int info = 10;
    fprint(info);
    return 0;
}

//gcc main.c mylib.c -o eseguibile_name
```

Best Practice Variabili Pubbliche, NO define, SI funzione di ritorno :
```c
#define DIM 100 //NO
int get_dim() { return 100; } //SI
```

## Esempio
```c
//complex.h
typedef struct {
    double re, im;
} complex;
complex add(complex, complex);
double mod(complex);
//complex.c
#include "comlex.h"
#include <math.h>
complex add(complex a, complex b) {
    complex temp;
    temp.re = a.re + b.re;
    temp.im = a.im + b.im;
    return temp;
}
double mod(complex x) {
    double z = sqrt(x.re*x.re + x.im*x.im);
    return z;
}
```

# 5 Liste Lineari
Source : Liste

E' Insieme Dinamico per ordinare Dati

## Vettori - Array
Vantaggio : Accesso O(costante) tramite indice, locazione memoria automaticamente determinata
**Svantaggi :**
1. Spazio allocato contiguo non partizionato, potrebbe essere eccessivo o insufficente
2. Vettori hanno dimenioni fisse, ridimenionare in runtime poco pratico
3. Anche se Vettori hanno memoria sufficente, sempre caso peggiore di memoria 
4. Inadatto a gestire insiemi dinamici con logiche es. se ordinati, perchè tocca far 'scalare' tutti i valori nei casi peggiori, con inserimento con complessita n cioè lineare.

## Liste Lineari
Implementazione di un Insieme di Oggetti :
1. Dello stesso tipo
2. Alocati Dinamicamente
3. Memorizzati in modo non contiguo

**Vantaggi e Svantaggi:**
- memoria allocata e liberata elemento per elemento
- Non c'è accesso diretto ma tramite scansione

## Implementazione
Accesso tramite puntatore alla struttura dati **Testa Heap** e all'elemento successivo ***next**.
Necessità di definire struttura e puntatore ad essa

```c
typedef struct list {
    ElemType info;
    struct list *next;
} *plist;

plist Head = NULL; //First elem
plist Tail = NULL; //Last elem
```
**Tail** punatatore all'ultimo elemento, facoltativo
### Varianti Lite
Bidirezionali, con , Liste Ordinate
- Tipo e Numero dei collegamenti tra elementi
- Rappresentazione head e tail
- Relazione tra i valori
### Liste Bidirezionali
A doppio punatatore
```c
typedef struct dlist {
    int val;
    struct dlist *next;
    struct dlist *prev;
} *pdlist;
```
### liste con Sentinella
Testa e Coda specificate nella lista o esternamente
```c
typedef struct list {
    int val;
    struct list *next;//Pinter to Head or Tail
} *plist;

typedef struct listinfo{ //Sentinella esterna
    plist head;
    plist tail;
} *plistinfo;
```

### Lite ordinate
La lista viene riordinata ad ogni Inserimento, Cancellazione e Modifica.
## Codice Implementazione Lite
Vedi Tutorial

# 6 Dati Astratti - Pile e Code
Source : Pile&Code

## ADT - Abstract Data Type
Tipi di Dato Astratti : Insieme di Valori + Operazioni su Essi.
Necessitano di definizione **typedef** o **struct**, 
e necessitano di funzioni custom corripondenti alle operazioni.

Es. Stringa (char *), si può concatenare, troncare, ...

Un Algoritmo ha diverse prestazioni a seconda delle strutture dati e funzioni relative

Importanza ADT è autodisciplina per usare le funzione adatte e non scorciatoie.Es. per inizializzare o inserire o cancellare. 
Non usare accesso diretto hai dati se non è previsto. Es. reset(counter) e NON counter = 0;

## Tipi di Dati
1. Scalari o Base-Standard : Sono i tipi forniti dal linguaggio come : int, double, char
2. Definiti dall'utente : 
   - **struct** Mediante Aggregazioni
   - **vettori** Indicizzazione di tipi base
 
### Esempio Contatore ADT
```c
//count.h
typedef int count; void reset(count *c); void incr(count *c);
//count.c
#include "count.h"
void reset(count *c) { *c = 0; }
void incr(count *c) { *c = *c + 1; }

//main.c
#include "count.h"
int main() {
    count c;
    reset(&c);
    incr(&c);
    return 0;
}
```
## AST Pila - Stack
Vedi Tutorial Implementabile Tramite Vettore o Lista(Stack Pila)
LIFO (Last In First Out) : Pila Libri
Inserimento e Cancellazione possibili sono in Cima : Top dello Stack

- Vettore : 
  1. N dinamico/statico
  2. Parto da id = 0, uso top_id
  3. Inserisco e elimino in ultimo id top_id
- Lista Stack Pila: 
 1. N Dinamico, solo nodi usati
 2. Inserisco e elimino in testa alla lista
   
## AST Coda - Tail
Vedi Tutorial
FIFO : First In First Out : Coda Persone
Inserimento in coda detta **rear**
Esstrazione solo in testa detta **font**
### Coda con Vettore
- Memorizza indici **font e rear**
- Gestisci indici circolarmente per non andare fuori vettore, da N a 0
- Inserimento e Cancellazzione id = rear%N o font%N  

