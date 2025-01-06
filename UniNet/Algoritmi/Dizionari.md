# Insiemi Dinamici
Insiemi Dinamici cioè che variano nel tempo

Sono Insiemi Dinamici se operano su algoritmi non statici

Elemento : Chiave + Dati "Satellite"

Dati "Satellite" : Perchè ruotano attorno alla chiave

Alcune Operazioni sono significative solo se l'insieme è ordinato 

# Operazioni
- Interrogazioni : Fornisono Informazioni sull'Insieme, senza modificarlo
- Operazioni di Modifica : Modificano l'Insieme

## Search (S, k)
Ritorna un elemento con chiave k in S o NULL

## Insert (S, e)
Aggiunge l'elemento "e" ad S. Ritorna esito inserimento true/false. 

## Delete (S, e)
Cancella l'elemento "e" in S. Ritorna esito cancellazione true/false. 

## IsEmpty (S)
Ritorna true con insieme vuoto altrimenti false.

## Clear (S)
Inizializza l'insieme a vuoto.

## Size (S)
Ritorna la cardinalità dell'insieme, cioè quanti elementi contiene.

## List (S)
Elenca gli elementi del sistema

## Operazioni Insieme Ordinato
### Minimun (S)
Ritorna l'elemento in S con chiave più piccola o NULL con Insieme vuoto.

### Maximun (S)
Ritorna l'elemento in S con chiave più grande piccola o NULL con Insieme vuoto.

### Predecessor (S, k)
Ritorna l'elemento in S con chiave più grande e < k o NULL se non esiste.

### Successor (S, k)
Ritorna l'elemento in S con chiave più piccola e > k o NULL se non esiste.

# Dizionari
Un Insieme Dinamico che fornisce solo le operazioni Search(), Insert() e Delete(), è detto **dizionario**.

Quando l'Insieme è totalmente ordinato si parla di dizionario ordinato.

Dizionari Possono essere inplementati tramite : Vettori(ordinati e non), Liste(ordinati e non), Code, Code a priorità, Stack

## Alberi BST
BTS : Binary Search Tree 

Alberi Binari di Ricerca. Struttura dati ordinata ottimale per Dizionari e complessità funzioni di essi.

### Complessità BST O(h)
Con h altezza dell'albero.
Permette Search(), Insert() e Delete() con complessità O(h)

Nel **caso migliore h = log<sub>2</sub>n**

### Proprietà BST
Per ogni nodo con chiave x, i nodi del sottoalbero a sx hanno chiavi <= x, viceversa sottoalbero a dx ha chiavi >= x.

### Operazioni BST
Struttura ricorsiva quinidi funzioni intrinsecamente ricorsive. Tuttavia spesso implementate iterativamente per ragioni di efficenza.

## Visite BST
Visite BST hanno complessità $\Theta$(n)

Sono Classificate in base all'ordine di visita dei nodi :
- Inorder :  Infisso, stampo al centro
- Preorder : Prefisso, stampo in cima
- Postorder : Postfisso, stampo in coda

```c
void inorder(x) {
    if( x != NULL) {
        inorder(left[x]);
        print key[x];
        inorder(right[x]);
    }
}
void preorder(x) {
    if( x != NULL) {
        print key[x];
        preorder(left[x]);
        preorder(right[x]);
    }
}
void postorder(x) {
    if( x != NULL) {
        postorder(left[x]);
        postorder(right[x]);
        print key[x];
    }
}
```

## Ricerca BST
Ricerca Ricorsiva, con divide et impera e assumendo che l'albero sia perfettamente bilanciato  T(n) = T(n/2) + $\Theta$(1) -> T(n) = O(logn)

**T parte sempre da root**
```c
Search(T, k){
    if(T==NULL) {
        return 0;
    }else if(k = key(T)) {
        return 1;
    }else if(k < key(T)) {
        return Search(left[T], k);
    }else {
        return Search(right[T], k);
    }
}
```
Search BST Iterativo, più perfomante, caso peggiore O(h).
```c
Search(T, k){
    while(T != NULL) {
        if (k = key(T)) {
            return 1;
        }else if(k < key(T)>) {
            T <- left[T];
        }else {
            T <- right[T];
        }
    }
    return 0;
}
```

![alt text](img\impleDizi.png)
