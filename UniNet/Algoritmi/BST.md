# Binary Search Tree
Vedi 'Dizionari.md' per basi sul BST

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
## Inserimento BST 
**u: nodo** che vogliamo , è sempre inserito come **foglia**, per non ristrutturare l'albero.

Complessità O(h)
1. Ricerca del nodo **v** che diventerà **genitore di u**
2. Inserimento **u**

```c
void tree_insert(T, u) {
    /*1. Cerco nodo padre*/
    y = NULL;
    x = root(T);
    while(x != NULL) {
        y = x;
        if(key[u] < key[x]) {
            x = left[x];
        } else {
            x = right[x];
        }
    }
    v = y;/*Nodo Padre Assegnato*/
    /*2. Inserisco u come figlio di v*/
    if(v == NULL) {
        root[T] = u;//Caso Base*/
    } else {
        if(key[u] < key[v]) {
            left[v] = u;
        } else {
            right[v] = u;
        }
    }
}
```

## Cancellazione BST
Cancellare un **nodo x** dell'albero T. Casi :
1. x Non ha figli : Eliminazione Diretta
2. x Ha un solo figlio : Si connette il genitore del nodo eliminato al suo unico figlio
3. x Ha due figli :
   1. Cerco il successore/predecessore del nodo da elminare
   2. Cancello il successore/predecessore
   3. Copio la chiave del succesore o predecessore nel nodo da eliminare. Richiede di calcolare il **massimo e minimo** di un BST per identificare successore o predecessore.

La Funzione di Cancellazione in un BST tramite sostituzione con successore o predecessore **non richiede confronti**, però questi valori potrebbero non esistere, se per esempio devo cancellare il nodo minimo(punto a left) o massimo(punto a right).
```c
/*Calcolo minimo BST O(h)*/
void tree_min(T) {
    while (left[T] != NULL) {
        T = left[T];
    }
    return T;
}

/*Calcolo massimo BST O(h)*/
void tree_max(T) {
    while (right[T] != NULL) {
        T = right[T];
    }
    return T;
}
```

### Cancellazione con Successore
Se x ha un figlio destro, il succesore è la chiave più piccola del sotto albero destro

Se x non ha un figlio destro, allora attraverso l'albero finchè non trovo un nodo che sia figlio sinistro del suo genitore

```c

```

## Caso Peggiore BST
**Cancellazzione Caso Peggiore T(n) = O(h)**

**Primitive BST tutte O(h)** :
- Caso Migliore se albero perfettamente bilanciato **h = logn**
- Caso Peggiore **h = n** -> O(h) = O(n)

Se le chiavi sono inserite in ordine crescente o decrescente albero completamente sbilanciato perchè solo figli a destra(crescente) o solo a sinistra(decrescente), quindi la complssità h diventa n.

TODO Dopo lez.16: Inmplementa Dizionari Ordinati e Non e Funzioni Dizionari Tramite Vettori(ordinati e non), Liste(ordinati e non), Code, Code a priorità, Stack. Controlla la complessità come in tabella

![alt text](img\impleDizi.png)
