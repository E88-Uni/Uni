# Programmazione Modulare
# Gestione Progetti
Non è possibile lavorando con un unico file sorgente costruire programmi complessi o avanzati. Esempio se va modificata solo una parte del sorgente bisognerà **ricompilare** l'intero file, per un sorgente granda l'azione sarà proporzionalmente **lenta**.
 
 - Lenta Compilazione
 - Difficile riutilizzare il codice
 - Difficile tenere traccia delle modifiche

Necessità di creare programmi distribuiti su più file sorgenti

![alt text](img\FileSorgenti.PNG)

Gestione Modulare:
![alt text](img\FileModulari.PNG)

## Modulo Oggetto
Contiene :
 - Il codice binario relativo al modulo Compilazione
 - Riferimenti Esterni a Funzioni e Variabili dichiarate in altri moduli
 - Funzioni e Variabili utilizzabili da altri moduli

Regola : Nel caso di più moduli una sola funzione **main()**
### Interfacce
Modulo può avere funzioni e variabili usate ma definite altrove :
 - Variabili time.h : srand(time(NULL))
 - Funzioni string.h : strcpy(str1, str2)

Una volta Compilato si potranno usare solo Variabili e Funzioni definite e Richiamabili/Utilizzabili dall'esterno
 - rnd_int(min, max); wait();
 - DIM_MAX

### Linker
Collega file oggetto (compilati), ad altri file oggetto contenenti variabili e funzioni definite per l'uso esterno

# Regole Visibilità
## Modularità
Ciascun Modulo :
 1. Definisce Funzioni Private e Pubbliche
 2. Definisce Variabili Private e Pubbliche
 3. Chiama Funzioni e Variabili Esterne
### Funzioni Pubbliche
In C tutte le funzioni sono Pubbliche di default, cioè il modulo non 
deve segnalare che **Esporta** una funzione

Il modulo che utilizza la funzione deve chiamare il prototipo con la 
parola chiave **extern** così il linker farà il collegamento
```c
//Modulo lib
void fun_ex(int , int);
...
void fun_ex(int m, int n){
    printf(" %d %d ",m , n);
}

//Main File
extern void fun_ex(int, int);
...
int main(){
    fun_ex(5, 10);
    return 0;
}
```

### Funzioni Private
Nel caso non si vogliano esportare delle funzioni di un modulo, bisogna **nella definizione inserire static** e NON nel prototipo
```c
    void inser(int[], int, int);
    void delete(int[], int);
    ...
    void inser(int A[], int n, int id){
        A[id] = n;
    }
    static void delete(int A[], int id){
        A[id] = 0;
    }
```
### Variabili Globali
In C tutte le variabili sono Pubbliche di default, cioè il modulo non 
deve segnalare che **Esporta** una variabile.

Devono essere importate con **extern**
```c
//Modulo lib
int n;
double V[100];
static int temp;

//Main File
extern int n;
extern double V[100];
//temp non importabile è privata
```
### Variabili Private
Definite con **static** non possono essere importate

Le variabili locali NON possono essere condivise : es quelle di blocchi( { } ) e procedure (interne a cicli e funzioni)

# File di Intestazione <.h>
**Header File** Si possono usare per raccogliere le definizioni **extern** di **funzioni e variabili pubbliche**

Il Modulo Creato per esportare funzioni e/o variabili è un file .h ; Tutti i moduli che usano tali risorse esportate usano i file .h (#include)
```c
//sort.h
void ordina(int[], int);
void inser(int[], int, int);
extern int n;
extern double V[100];

//sort.c
#include "sort.h"
int n;double V[100];
static int temp;
void ordina(int V[], int dim){};
void inser(int A[], int n, int id){
        A[id] = n;
    }
static void delete(int A[], int id){
    A[id] = 0;
}
```
Utilizzo "sort.h"
```c
#include "sort.h"
int main(){
    int i=0;
    int A[20];
    ordina(A, 20);
    for(;i<n;i++){
        printf(" %d ", V[i]);
    }
}
```
## Include "miofile.h"
Non si usa **#include <my_lib.h>** ma **#include "my_lib.h"**

## Best Prectice
Ricorda che un modulo è meglio che includa il proprio header.h così da avere inizzializzate variabili e funzioni private ed pubbliche e da **conferma al linker**
```c
//sort.h
void ordina(int[], int);
void inser(int[], int, int);
extern int n;
extern double V[100];

//sort.c
#include "sort.h"
int n;double V[100];
static int temp;
void ordina(int V[], int dim){};
void inser(int A[], int n, int id){
        A[id] = n;
    }
static void delete(int A[], int id){
    A[id] = 0;
}
```
### Variabili Pubbliche
Vanno tenute al minimo perchè non è una buona pratica. Usa le funzioni per comunicare variabili es. 
```c
#define N 100 //NO
int get_dim(){
    return 100;//SI
}
```
### Esempio
![alt text](img\strutturaHeader.PNG)
```c
//complex.h
typedef struct {
    double re, im;
} complex;
complex add(complex, complex);
complex sub(complex, complex);
complex mult(complex, complex);
complex quot(complex, complex);
double mod(complex);

//complex.c
#include <math.h>
#include "complex.h"
complex add(complex x, complex y){
    complex temp;
    temp.re = x.re + y.re;
    temp.im = x.im + y.im;
    return temp;
}
double mod(complex x){
    double z = sqrt(x.re*x.re+x.im*x.im);
    return z;
}

```
## Compilazione
```
gcc main.c miofile.c -o programma
```

TODO : Lezione 5 Liste