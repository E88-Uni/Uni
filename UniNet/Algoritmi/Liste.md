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


![alt text](img/MemoriaListe.jpg)
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
### Head
Lo **Stato** della lista è mantenuto tramite un esplicito puntatore
All'Inizio **Testa Head** della lista

### Tail
Riferimento all'ultimo elemento della lista Coda Tail, può non servire

**Iniziallizzazione :** 
```c
    PElemLista Head = NULL;
    PElemLista Tail = NULL;//Può non eserci/servire
```
![alt text](img/InserimentoListe.jpg)

## Varianti di Liste
 - Tipo e Numero dei collegamenti tra elementi
 - Rappresentazione head e tail
 - Relazione tra i Valori
### Liste Bidirezionali
A doppio puntatore
```c
typedef struct dlist {
    int val;
    struct dlist *next;
    struct dlist *prec;
} *pdlist;
```
### Liste con Sentinella
Testa e coda specificate in un elemento
Esempio blocco di fine o inizio ha come valore puntatore ad head o tail
oppure:
```c
typedef struct list {
    int val;
    struct list *next;//punta a head o tail
} *plist;
//oppure sentinella esterna
typedef struct{
    plist head;
    plist tail;

} infolist;
```
### Liste Ordinate
Le chiavi vengono usate per ordinre la lista ad ogni update(modifica, inserimento, cancellazzione)

# Impementazioni
## Inizializza e Ricerca
```c
typedef struct list {
    int val;
    struct list *next;
} *plist;

plist Head;

void Inizializza(plist p){
    *p=NULL;
}
Inizializza(Head);

int ricerca(plist p, int x){
    plist q = p;
    while(q!=NULL){
        if(q->val == x){
            return 1;
        }
        q = q->next;
    }
    return 0;
}

plist p_ricerca(plist p, int x){
    plist q = p;
    while(q!=NULL){
        if(q->val == x){
            return q;
        }
        q = q->next;
    }
    return NULL;
}
```
## Visita
```c
void stampal(){
    plist q = *Head;
    printf("/n");
    while(q!=NULL){
        printf(" %d ", q->val);
        q = q->next;
    }
    printf("/n");
}
void stampal(plist p){
    plist q = p;
    printf("/n");
    while(q!=NULL){
        /*Operazione es : (q->val%2==0)? pari++; : dispari++;*/
        printf(" %d ", q->val);
        q = q->next;
    }
    printf("/n");
}
```
## Inserimento
 1. Crea cella
 2. Sistema puntatori
```c
void ins_head(plist *p, int x){
    plist q = (plist)malloc(sizeof(struct list));
    q->val = x;
    q->next = *p;
    *p = q;
}
ins_head(&head, x);
```
![alt text](img/pHead.jpg)

## Cancellazzione
Necessita sapere il puntatore prima dell'elemento da cancellare
 1. Ricerca
 2. Sistema puntatori (p->prox = q->prox)
 3. Svuota cella

Gestione a due velocità :
 - Puntatore prima
 - Puntatore attuale

```c
//h head
int delete(plist *h, TypeElem val) {
    plist p, q;
    p = *h;
    q = *h;
    if(p->val== val){
        *h=p->next;
        free(p);
        return 1;
    }
}

int delete(plist *h, TypeElem val) {
    plist p=*h, q=*h;
    while(q != NULL){
        p=q;
        q=q->next;
        if(q->val == val) {
            p->next = q->next;
            free(q);
            return 1;
        }
    }
    return 0;
    //p è prima e q è attuale
}
```

# Code List
## Struttura
```c
typedef struct Nodo {
    int n;
    struct Nodo *next;
}* pl;

pl testa = NULL;
```
## New
```c
pl inizializza(){
    return NULL;
}

pl new(int val){
    pl newl =(pl)malloc(sizeof(struct Nodo));
    newl->n = val;
    newl->next = NULL;
    return newl;
}
```
## Inserimento
```c
void ins_head(pl* head, int val){
    pl newp = new(val);
    newp->next = *head;
    *head = newp;
}

void ins_tail(pl* head, int val){
    pl newp = new(val);
    pl temp = *head;
    if(temp == NULL){
       *head = newp;

    }else{
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newp;
    }
}
```
## Delete
```c
void delete(pl *head, int val){
    pl temp = *head;
    pl prev = NULL;
    if(temp != NULL && temp->n == val){
        *head = temp->next;
        free(temp);
        return;
    }
    while(temp != NULL && temp->n != val){
        prev = temp;
        temp = temp->next;
    }
    if(temp != NULL){
        prev->next = temp->next;
        free(temp);
    }
}

```
## Print
```c
void stampa(pl nodo){    
    printf("\n");
    while(nodo != NULL){
        printf(" %d ", nodo->n);
        nodo = nodo->next;
    }
    printf("\n");
}   
```
