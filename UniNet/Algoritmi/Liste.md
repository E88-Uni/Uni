# Liste
Modo di organizzare Dati e Insiemi Dinamici
## Limitazioni dei Vettori
**Proprietà**
Accesso tramite Indice : Locazione degli elementi automaticamente determinata

**Svantaggi :**
 1. Spazio allocato contiguo : potrebbe non esserci uno spazio sufficente per memorizzarei dati, perchè necessità di uno spazio di memoria non partizionato
 2. Vettori hanno dimensioni Fisse e modificare la dimensione in runtime è poco pratico
 3. Vettori hanno dimensioni Fisse quindi il programma lavora con un eccesso di memoria utilizzata, lavora sempre in caso peggiore
 4. Inadatto a gestire Insiemi Dinamici magari basati su un qualche Ordine : es. Inserire un nuovo elemento sempre come primo (tocca ogni volta far scalare tutti gli elementi)
## Liste Linerai
Implementazione di un Insieme di Oggetti 
 1. Dello Stesso Tipo
 2. Allocati Dinamicamente
 3. Memorizzati in modo non contiguo

**Vantaggi e Svantaggi:**
 - Memoria allocata e liberata elemento per elemento
 - Non c'è l'accesso diretto ma tramite scansione


![alt text](img/MemoriaListe.png)
## Implementazione
Accesso per mezzo di **collegamento all'elemento successivo** realizzato tramite **puntatori**

Necessità uno **struct** per elementi e **Puntatori** per i collegamenti

```c
struct ElemList {
    ElemType info;
    /*Chiave es. int id, char key[20]*/
    struct ElemList *Prox;
};
typedef struct ElemList ElemLista;
typedef ElemLista *PElemLista;

struct {
    ElemType info;
    PElemLista Prox;
};
```
## Varianti di Liste

TODO : Lez. 5 -22 min