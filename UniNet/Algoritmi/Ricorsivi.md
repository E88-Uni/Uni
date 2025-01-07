# Ricorsivi
Programmi non iterativi, possono non essere efficenti

E' una **funzione** che all'interno della propria definizione contiene 
direttamente o indirettamente **una chiamata a se stessa***;

Una **algoritmo ricorsivo** è basato su funzioni ricorsive.

### Ricorsione Diretta
```c
f(){
    ...
    f();
    ...
}
```

### Ricorsione Indiretta
```c
f(){...
    g();...
}
g(){...
    f();...
}
```

## Definizione
Soluzione ad un problema S applicato ai dati di D, 
è ricorsiva :
 - Se si può esprimere : S(D) = f (S(D'))
 - Condizione di terminazione S(D<sub>0</sub>) = S<sub>0</sub>
 - D !=D<sub>0</sub>
 - D' è un insieme più piccolo di D
 - D<sub>0</sub> è l'insieme di dati minimo e S<sub>0</sub> è la sua soluzione detta elementare

## Motivazioni
 - La formulazione ricorsiva permette di esprimere un insieme infinito per mezzo di un'istruzione finita
 - Essenziale gestire il problema della terminazione 
 - Natura Problemi Reali Ricorsiva
 - Eleganza matematica della soluzione

### Schema Generale
```c
P(n){
    if(C){
        return;/*Caso Terminale*/
    }else{
        ...;/*Operazioni*/
        P(n');/*Una o più chiamate ricorsive*/
        /*Con (n'<n);*/
    }
}
```
### Approccio Ricorsivo
Sviluppo della sequenza delle chiamate
 1. Top-Down. Attraverso **Albero** di ricorsione, esso ha come radice il valore corrispondente alla prima chiamata
 2. Bottom-Up. Si parte dai casi elementari

### Esempio1
```c
void f(int n){
    if(n <= 0){
        return;
    }
    f(n-2);
    printf(" %d ", n);
    f(n-1);
}
```
**TOP-DOWN**
Problema dei sottoproblemi identici ripetuti più volte

![alt text](img\alberoTopDown.PNG)

Soluzione lettura albero da sx verso dx : 1 3 2 1

**BOTTOM-UP**
Si parte dai Casi Terminali o Sottoproblemi Elementari :
 1. Li Risolvo una sola volta
 2. Li Uso per Calcolare le Soluzioni di Dimensione più grande

![alt text](img\BottomDown.PNG)

### Esempio2
```c
void f(int n){
    if(n > 0){
        f(n-60);
        printf("%d", n);
        f(n-30);
    }
}
```
**BOTTOM-UP**
Relativamente svantaggioso perchè casi base da f(0) a f(30)

Meglio sapere n è usare un **TOP-DOWN**

## Efficenza
Ad ogni chiamata a funzione viene allocato un **frame** sullo **stack** detto **record di attivazione** contiene le informazioni riguardanti la chiamata a funzione.

Frame minimo solo il record di attivazione della funzione main

### Frame dello Stack
Dinamicamente cresce o/e si svuota a seconda delle funzioni già usate e da usare.
Variabili automatiche + funzione :
 1. Parametri Fondamentali
 2. Variabili Locali
 3. Indirizzi di ritorno : indica il punto in cui tornare
 4. Indirizzo del codice della funzione : puntatore alla prima istruzione

**Singolo Frame Funzione :**

![alt text](img\STackComponent.PNG)

### Stack Overflow
Può succedere per ricorsioni profonde perchè ad ogni chiamata a funzione corrisponde un Frame ed esse riempono lo stack -> Spesso per Funzioni Impropriamente ricorsive.

Es Funzione Impropriamente ricorsiva
```c
int fatt(int n){
    /* BestPractice : Prima i casi base*/
    if(n<=1){
        return 1;
    }else{
        return n*fatt(n-1);
    }
}
```
La Ricorsione dal punto di vista teorico ha sempre una soluzione **iterativa**

### Uso Ricorsività
 - Quando una funzione invoca se stessa più di una volta
 - Si opera su una struttura dati ricorsiva
Lez. 3 -10
