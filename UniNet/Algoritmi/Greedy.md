# Paradigma Greedy
Caratterizzato per prendere la decisione che è **localmente Ottima**.
Algoritmi che Scelgono l'Ottimo Locale senza valutare l'ottimo Globale.
Per problema di ottimizzazione.
Adatto a Pochi Problemi anche se Intuitivo.

**Euristiche** Per Problemi Complessi, cioè con complessità accettabile.

## Soluzione Greedy
Insieme di Oggetti con Costo Associato. 
Ottenuta in modo incrementale scegliendo in ogni passo l'oggetto con costo minore compatibile con la soluzione attuale.

## Schema Greedy 1
I costi sono {a1, a2, ..., an} e non sono modificati dalle scelte.

```c
int *Greedy1(int A[], int dimA){
    int *S;
    int idS = 0;
    sortCrescente(A, dimA);
    for(int i=0; i<dimA; i++) {
        if(possibile_aggiunta(S, A[i])) {
            S[idS++] = A[i];
        }
    }
    return S;
}
```

## Schema Greedy 2
I costi sono {a1, a2, ..., an} sono modificati dalle scelte.

```c
int *Greedy2(int A[], int dimA){
    int *S;
    int idS = 0;
    while(isNotEmpty(A)) {
        int a = scegliCostoMinore(A, dimA);
        if(possibile_aggiunta(S, a)) {
            S[idS++] = a;
            aggiornaCosti(A, dimA, a);//Delete 1 volta 'a'
        }
    }
    return S;
}
```

# Esempi Algo Greedy
## Problema dello Zaino
Caricare il massimo valore senza eccedere il peso massimo W.
n : Oggetti; w<sub>1</sub> : Peso; c<sub>1</sub> : Valore.

Se **oggetti** si possono prendere **solo interamente**, il problema 
NON si risolve con algoritmo Greedy ma **con Programmazione Dinamica**

**Valore unitario :** c<sub>i</sub>/w<sub>i</sub>
Es oggetto 1 : 60 € per 10 kg : Valore Unitario 6€/kg

### Zaino continuo o frazionario
Assumiamo che sia possibile prendere frazioni di ogni oggetto

**Greedy1 :**
1. **Ordiniamo gli oggetti per valore unitario**
2. Scegliamo in ordine fino a saturare il peso

## Selezione di Attività
Date N attività in S = {1, 2, ..., N}
In Competizione tra loro per l'utilizzo di una certa risorsa

Determinae il massimo sottoinsieme di attività per l'utilizzo della risorsa senza conflitti.

Attività i in S : 
- s<sub>i</sub> : tempo di inzio
- f<sub>i</sub> : tempo di fine
- s<sub>i</sub> <= f<sub>i</sub>

**Compatibilità** di due attività i e j se : f<sub>i</sub> <= s<sub>j</sub> o f<sub>j</sub> <= s<sub>i</sub>

```c
/*Ordino Attività in Crescente per Tempo di Inizio
Tempo di Inizio S
Tempo di Fine F*/
void Activity_Selection(int S[], int F[], int N){
    int A[];
    int idA = 1;
    int j = 1;
    A[0] = 1;
    for(int i=2; i<N; i++) {
        if(S[i] >= F[j]) {
            A[idA++] = i;
            j = i;
        }
    }
}
```
# Programmazione

## Quando SI Greedy
1. Sottostruttura Ottima Come nella Programmazione Dinamica
2. Proprietà della Scelta Greedy : Ottimo Globale corrisponde alla Sequenza di Scelte Localmente Ottime

Note sulla Scelta :
1. Non è necessario a differenza della Programmazione Dinamica che i sottoproblemi si ripetano
2. La Scelta di un Algoritmo Greedy può essere perchè si è scelto in precedenza di lavorare così 
3. Non dipende da Tutte le soluzioni del sottoproblema
4. Dopo aver preso una decisione questa non viene mai riconsiderata

Difficoltà non è scegliere l'algoritmo greedy o implementarlo ma dimostrare che fornisca la soluzione ottimale

**Programmazzione Dinamica e Algorimi Greedy**
