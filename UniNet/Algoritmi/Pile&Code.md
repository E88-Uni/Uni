# ADT
**Abstract Data Type** 
Tipi di Dato Astratti:
 - Insieme di Valori
 - Operazioni su Questi Valori

Es. stringa (char *)  e si può concatenare, troncare, ecc.

Un algoritmo ha diverse prestazioni a seconda delle strutture dati
## Tipi Dati
### Scalari
Tipi Scalari o Base (standard) : Sono quelli forniti dal linguaggio come: int, double, char
### Definti Utente
Tipi definiti dall'utente :  
 - Mediante aggregazioni (**struct**) e/o
 - Indicizzazione di tipi base  (**vettori**)
### ADT
Gli **Abstract Data Type** è un tipo di dato le cui istanze possono essere manipolate con :
 - Modalità che dipendono esclusivamente dalla semantica del dato
 - Non dipendono dalla sua implementazione

ADT Necessita :
 - Definizione usando **typedef**
 - Definizione funzioni corrispondenti alle operazioni

**int** è un ADT? : NO l'Insieme ADT dipende dalla rappresentazione 

### Es. ADT
Contatore
```c
//cont.h
typedef int cont;
void reset(cont *c);
void incr(cont *c);

//cont.c
#include "cont.h"
void reset(cont *c){
    *c=0;
}
void incr(cont *c){
    *c=*c+1;//(*c)++;
}
int main(){
    cont c1, c2;
    reset(&c1);reset(&c2);
    incr(&c1);...
}
```
## Problemi ADT
 - Autodisciplina del porgrammatore es. cont c; c++;
 - Non viene impedito l'accesso diretto, implementazione visibile nella typedef (typedef int cont) : quindi il problema è che chi vede come è implementato il tipo lo usi inpropriamente es. con operazioni su interi

## ADT Pila - Stack
E' un ADT dove inserimento e cancellazione sono **possibili**
Solo in una pecifica posizione detta **top - Cima** dello **stack**
TODO Lez 7 -28
## ADT Stack LIFO
**Last In First Out** : Ultimo elemento inserito è il primo ad essere estratto Es. Pila di Libri
## Operazioni Stack
Puoi impementare uno Stack tramite vettore o lista
```c
void Inizializza(Stack *ps)
int PilaVuota(Stack s)//ci dice se la Pila è vuota
elem Top(Stack s); //Ci dice il primo elemento LIFO senza toglierlo
void Pop(Stack *ps); //Eliminare
void Push(Stack *ps, elem x);//Inserire
int PilaPiena(Stack s);//Può non servire
```
### Stack Vettore
 - N elementi allocati (N dinamico o statico)
 - Parto dall'Indice 0 per inserimento
 - Elemento Nuovo inserito nell prosimo indice disponibile
 - Ad ogni Inserimento e Eliminazione aggiorno **top_id**

```c
#define VUOTO -1
#define N 100
#define elem float

typedef strcut{
    int top;
    elem info[N];//con elem = float e N dim massima
} Stack;

void Inizializza(Stack *ps){
    ps->top = VUOTO;//ulrimo elem -1
}

int emptyStack(Stack s){//PilaVuota
    return (s.top == VUOTO);
}

int isFullStack(Stack s){//PilaPiena
    return (s.top == (N-1));
}

elem Top(Stack s){
    if(!emptyStack(s)){//Se Pila Non Vuota
        return s.info[s.top];
    }else{
        elem empty = 0;
        return empty; 
    }
}

void Pop(Stack *ps){
    if(!emptyStack(s)){//Se Pila Non Vuota
        s->top--;//Non cancello tanto poi la Push sovrascrive
    }
}

void Push(Stack *ps, elem x) {
    if(!isFullStack(*s)){//Se Pila Non Piena
        s->top++;
        s->info[s->top] = x;
    }
}
```
### Stack Lista
 - Non è necessario calcolare la Fine (NO isFullStack())
TODO : Fallo come esercizio

## ADT Coda - Tail
 - ADT In cui Inserimento e Cancellazione sono consentite solo in specifiche posizioni
 - Inserimento inserito solo ad un estremo detto 'retro' **rear**
 - Estrazione solo in 'testa' **font**
## ADT Tail FIFO
**First In First out** : Il Primo Elemento Inserito è il Primo Estratto Es. Coda di Persone
## Operazioni Tail
```c
void Inizializza(Tail *pq)
int CodaVuota(Tail q)//ci dice se la Coda è vuota
elem Front(Tail q); //Ci dice il primo elemento FIFO senza toglierlo
void Dequeue(Tail *pq); //Estrae
void Enqueue(Tail *pq, elem x);//Inserisce in Coda
int CodaPiena(Tail q);//Può non servire
```
### Coda con Vettore
 - Elementi memorizzati in indici **front e rear**
 - Gestire indici in modo circolare per non rimanere 'fuori vettore'
 - Incremento e Decremento modulo N (%N : modulo dimensioni coda) 
   - cioè con indice a N elemento si passa a indice 0
   - 
TODO : Implementa come esercizio sia con Vettore che con Lista(con 2 puntatori : a testa e a coda della lista, Enqueue : inserisce in coda, Dequeue cancella in testa)

dopo il primo todo sopra che ti aiuta

TODO 2 todo Implementazioni poi -> lez.8