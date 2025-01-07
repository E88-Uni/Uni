# ADT
## Coda Priorità

Applicazioni Pratiche e Reali avendo spesso elementi con importanza diversa 
Es. Clienti VIP, Processi di un sistema operativo

**Implementazione :** 
 - Tramite liste
 - Tramite Vettori si usa un **heap** cioè mucchio  
```c
#define elem float
Coda q; elem e;
Inizializza(q);
CodaVuota(q);
Maximum(q);
ExtractMax(q);
Insert(q, e);
//CodaPiena(q); solo con vettore e non con lista
```
### Prelievo in Testa
Inserimento in base alla **priorità**
### Inserimento in Coda
Prelievo in base alla **priorità**
## Heap
Albero Binario(Con 2 rami ad ogni nodo)
Struttura dati con chiavi organizatte in albero binario,
Mantiene inoltre prioprietà legate a valori e struttura dell'albero

**Proprieta heap** : Ordinamento parziale o locale
 - Max heap : i valori del nodo padre è >=
 - Min heap : i valori del nodo padre è <=
**Proprieta Shape** : è un **heap** se l'albero è completo ad ogni livello tranne l'ultimo quello delle foglie, deve essere bilanciato

### Max Heap
 - L'elemento con chiave massima è la radice
 - Ogni nodo ha un valore >= dei suoi discendenti
 - Altezza h = log<sub>2</sub>n, con n elementi

### Heap Vettori
**Il nodo i ha come figlo 2i a sx e 2i+1 a dx**, Con 1 come radice

### Heapify
 - Impone la heap proprerty, applicata a un elemento i
 - Assume che i sottoalberi da i siano heap (i2 e i2+1)


```c
//senza controllo n >= id_r e partendo da radice id=1
void heapify(int *A, int id){
    int id_l = id*2,  id_r = id*2+1;
    int id_max = (A[id_r]>A[id_l])?id_r:id_l;
    if(A[id_max] > A[id]){
        swap(&A[id], &A[id_max]);
        heapify(A, id_max);
    }
}
```
Tramite operazione **BuilHeap** con funzione **heapify:** può essere usata per convertire un vettore A[1,..,n] in un heap

**heapify** tramite vettore A[1,..,n]

**Heapify con A[0, n-1] e controlli**
```c
void heapify(int A[], int n, int id) {
    int id_l = id*2+1, id_r = id*2+2;
    int id_max = (n>id_l && A[id_l]>A[id]) ? id_l : id;
    if(n>id_r){
        id_max = (A[id_r]>A[id_max]) ? id_r : id_max;
    }
    if(id_max!=id){
        swap(&A[id], &A[id_max]);
        heapify(A, n, id_max);
    }
}
```
## Coda a Priotita Heap
```c
//Elimina dalla coda il valore con massima priorità
int ExtractMax(int *A, int n){//A[1,...,n]
    int max;
    if(empty_que(A)){
        printf("\nHeap underflow");
    }
    max = A[1];
    A[1] = A[n];//forzo l'heapify
    heapify(A, n, 1);
    n--;
    return max;    
}

int Parent(i){
    return i/2;
}

void Insert(int *A, int key, int n){
    int i = n+1;
    n++;
    while(i>1 && A[Parent(i)]<key){
        A[i] = A[Parent(i)];
        i = Parent(i);
    }
    A[i] = key;
}
```
## ADT Albero
Informazioni Gerarchiche Organizzate su più Livelli 
Es. Alberi Genealogici, Organigrammi
**Grado Albero :** Quanti discendenti/fogli può avere direttamente un nodo padre, si prende il nodo con **più figli diretti** detto grado massimo

Albero di Grado Binario
```c
typedef struct elemTree {
    elem info;//int key;
    struct elemTree *Sx, *Dx;
} *PTree;
typedef struct elemTree eTree;
```


Albero di Grado N
```c
typedef struct elemTree {
    elem info;//int key;
    struct elemTree Figli[N];
} *PTree;
typedef struct elemTree eTree;
```
### ADT Tree Operazioni
Le operazioni dipendono dalla semantica, dipende dalla relazione che regola la gerarchia.

Infatti se non ho una regola di gerachia definita non posso inserire una chiave o nodo nell'albero

**Definizione Alberi Binari di Ricerca :** 
**Relazione Albero Binari**
 - Nodi Sottoalberi a sx hanno chiavi <=x
 - Nodi Sottoalberi a dx hanno chiavi >=x

Lez. 9 Algoritmi