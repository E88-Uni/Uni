Vedi 'Dizionari.md' per basi sul BTS

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

TODO Dopo lez.16: Inmplementa Dizionari Ordinati e Non e Funzioni Dizionari Tramite Vettori(ordinati e non), Liste(ordinati e non), Code, Code a priorità, Stack. Controlla la complessità come in tabella

![alt text](img\impleDizi.png)

Lez 16
