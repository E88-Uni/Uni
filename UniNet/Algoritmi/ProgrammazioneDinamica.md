# Paradigmi Algoritmici
Strategie per risolvere problemi
1. Programmazione Dinamica -> Per Problemi di Ottimizzazione
2. Paradigma Greedy -> Per Problemi di Ottimizzazione
3. Backtracking

**Paradigmi Algoritmici Generali :**   
- Divide and Impera : **Top-Dwown**
- Ricerca ed Enumerazione

Divide and Impera in Certi Casi Non Efficiente Perchè Ignora la Struttura del Problema (Possibili Sotto Problemi e Sotto Soluzioni).
Esempio con Serie di Fibonacci
```c
/* T(n) = T(n-1) + T(n-2) -> T(n) = 2T(n-1) -> O(2^n) */
int fib(int n){
    if(n <= 1){
        return n;
    } else {
        return fib(n-1) + fib(n-2);
    }
}

//T(n) = O(n) S(n) = O(n)
//#define MAX 1000 -> int F[MAX];
int fib(n) { 
    int *F =(int)malloc(sizeof(int)*(n+1));
    int i = 2;
    F[0] = 0; F[1] = 1;
    for(; i<=n; i++){
        F[i] = F[i-1] + F[i-2];
    }
    return F[n];//free(F)
}//Salvo i valori e posso riutilizzarli e infine free(F)

//T(n) = O(n) S(n) = O(1)
int fib(n) { 
    int c = 0, a = 0, b = 1; 
    int i = 2;
    for(; i<=n; i++){
        c = a + b;
        a = b;
        b = c;
    }
    return (n==1)?1:c;
}
```

Evitare di risolvere **lo steso sottoproblema più volte** memorizzando le soluzioni e riutilizzandole


# Progetto di un Algoritmo
**Struttura Problema :** Può guidarci al Progetto dell'Algoritmo

# Programmazione Dinamica
Quando vogliamo ottimizzare l'algoritmo. Esso Presenta :
- Più Soluzioni
- Riutilizzo Soluzioni se sottoproblemi non indipendenti
- Soluzioni hanno un Punteggio
- **Bottom-Up :** Risolvo ogni sottoproblema e memorizzo la soluzione
- Cerco la soluzione con punteggio più alto

## Quando Programmazione Dinamica
- Sottoproblemi Ripetuti
- **Sottostruttura Ottima :**La soluzione Ottima consiste in Soluzioni Ottime ai Sottoproblemi
  
## Come Programmazionee Dinamica
4 Fasi :
1. Caratterizzazione della Struttura di una Soluzione Ottima
2. Definizione Ricorsiva del Valore di una Soluzione Ottima
3. Calcolo **Bottom-Up** del valore della Soluzione Ottima. **Memorizzare** le Soluzioni in una Tabella a **partire dai problemi elementari**.
4. Opzionale - Costruzione di una Soluzione Ottima. Se il Problema Richiede il Calcolo Della Soluzione e non solamente il valore.

## Struttura Programmzione Dinamica
C(p) con p=0 -> 0
C(p) con p!=0 min<sub>i</sub>{1 + C(p-d<sub>i</sub>)}

## Esempio Problema del Cambio
Dato in Intero n>0 che sono i soldi da cambiare.
Un Insieme di Banconote/Monete D con i valori {d<sub>1</sub>, ..., d<sub>m</sub>}. 
Calcolo il Minimo Numero di Banconote da utilizzare per cambiare n.

Fasi :
1. Caratterizazzione della Soluzione Ottima
   1. Sottostrutture Ottimali b = {d1, d2, d3}, n-b={d4, d5}
2. Definizione Ricorsiva della Soluzione Ottima
   1. C(p) = minimo numero di banconote per cambiare p
   2. C(p) con p=0 -> 0 Banconote
   3. C(p) con p!=0 min<sub>i</sub>{1 + C(p-d<sub>i</sub>)}
3. Calcolo **Bottom-Up** della Soluzione Ottima. 

```c
int *change(int D[], int dimD, int n) {
    int *C;
    C[0] = 0;
    int p=1, i = 0;
    int min;
    for(; p<=n; p++) {
        min = INT_MAX;
        for(; i<dimD; i++) {
            if(D[i] < p && (1 + C[p-D[i]]) < min) {
                min = 1 + C[p-D[i]];
                coin = i;/*Salvo quì la lista di monete*/
            }
    }
    C[p] = min;
}
```
### Greedy
Algoritmo più **Intuitivo**.
Scegli d come banconota più grande il cui valore non eccede n.
Presegui con n = n-d. Finchè n=0.

Non Funziona per esempio con n=31 e D={12, 8, 1}
-> 12 * 2 + 7 * 1 = 9 Banconote

Soluzione Migliore Non Trovata 12 + 2 * 8 + 3 * 1 = 6 Banconote
