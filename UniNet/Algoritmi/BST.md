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


## Caso Peggiore BST
**Cancellazzione Caso Peggiore T(n) = O(h)**

**Primitive BST tutte O(h)** :
- Caso Migliore se albero perfettamente bilanciato **h = logn**
- Caso Peggiore **h = n** -> O(h) = O(n)

Se le chiavi sono inserite in ordine crescente o decrescente albero completamente sbilanciato perchè solo figli a destra(crescente) o solo a sinistra(decrescente), quindi la complssità h diventa n.

TODO  Inplementa Dizionari Ordinati e Non e Funzioni Dizionari Tramite Vettori(ordinati e non), Liste(ordinati e non), Code, Code a priorità, Stack. Controlla la complessità come in tabella

![alt text](img\impleDizi.png)

# Codice BST
Leggi file 'BSTCode.txt'

```c
typedef struct Nodo {
    int val;
    struct Nodo* sx;
    struct Nodo* dx;
} Nodo;
Nodo * cancellaNodo(Nodo *root, int valore) {
    if(root == NULL) { /*Albero vuoto*/
        return root;
    }
    if(val < root->val) { /*Cerca nodo da eliminare*/
        root->sx = cancellaNodo(root->sx, val);
    } else if(val > root->val) {
        root->dx = cancellaNodo(root->dx, val);
    } else { /*Nodo Trovato*/
        if(root->sx == NULL) {/*Caso 1-2, un solo figlio dx o nessuno*/
            Nodo *temp = root->dx;
            free(root);
            return temp;
        } else if(root->dx == NULL ) {/*Caso 2, solo un figlio sx*/
            Nodo *temp = root->sx;
            free(root);
            return temp;
        }
        /*Caso 3 : 2 Figli, Trovo succesore : nodo più piccolo del sottoalbero destro*/
        Nodo *successore = tree_min(root->dx);
        /*Copia valore del successore*/
        root->val = successore->val;
        /*Cancella successore*/
        root->dx = cancellaNodo(root->dx, successore->val);
    }
    return root;
}
```
