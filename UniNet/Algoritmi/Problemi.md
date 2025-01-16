# Teoria della Complessità
Infrastruttura per classificare i problemi

La maggior parte degli algoritmi analizzati hanno complessità polinomiale in n : T(n)=O(n<sup>k</sup>), per qualche k costante.

k generalmente piccolo es k <= 3

## Proprietà Polinomiali
Proprietà di **chiusura** degli algoritmi polinomiali :
Un **Polinomio rimane sempre un Polinomio** con somma, moltiplicazione e composizione :
- f(n)+g(n) somma
- f(n)*g(n) moltiplicazione
- f(g(n)) composizione

## Problemi Intrattabili
**Problemi NP Completi :**
- Problemi Esponenziali : con complessità > O(n<sup>k</sup>) o k grandi
- Super-Polimoniali : Problemi che non hanno complessità temporale polinomiale 
- Problemi non risolubili
Se dimostro che un problema è intrattabile è inutile escogitare un algoritmo efficente o esatto

Se è un problema intrattabile si può Tentare :
- Un approssimazzione
- Soluzioni "brute-force"
- Algoritmi Euristici : Efficaci nella maggior parte dei casi

## Problemi di Decisione
Teoria della NP-completezza si applica ai problemi di decisione
-> Problemi con risultato booleano vero o falso

Questo **non è** per forza una **restrizione**, poichè i problemi di ottimizzazione possono facilmente essere convertiti in problemi di decisione

Esempio problema dei percorsi minimi :
Dato un Grafo pesato G(V,E).Dati due vertici (u,v) in V, qual'è il percorso minimo in G tra u e v?
**Trasformazzion in un problema di decisione :**
Dato un Grafo pesato G(V,E).Dati due vertici (u,v) in V, e un intero k>=0, esiste un percorso G tra u e v di lunghezza al più k?

Se possiamo risolvere il problema di ottimizzazione rapidamente, possiamo anche risolvere il problema di decisione corrispondente.
Quindi **viceversa**, Se possiamo provare che un problema di decisione è intrattabile lo stesso si applica al problema di ottimizzazione.

## NonDeterminimo
**Sistema deterministico :** quando dati certi input e una certa operazione la risposta è la stessa!

La transizione tra stati è determinata da un evento base con due soli valori A AND B

Sistema NonDeterministico se si hanno pasaggi mancanti o con risposte multiple e questi eventi non sono ordinati da metodi tipo AND o OR ecc...

L'Implemetazione di un sistema deterministico è sempre fattibile per quanto complessa

Implementare un sistema nondterministico è infattibile. 

NOTA: Tramite computer quantistici o data center con enormi eventi in parallelo si può simulare un sistema nondeterministico.

Sistema/Algoritmo non deterministico
- choice(1,n) ritorna uno indice degli elementi, non è una scelta casuale
- failure() terminazione senza successo
- success() terminazione con successo

```c
NDsearch(a, n, k) {//O(1)
    j = choice(1, n);//O(1)
    if(A[j] == k) {
        print(j);
        success();
    } else {
        print("0");
        failure();
    }
}
```
Sistema/Algoritmo non deterministico :
1. Fase di Scelta
2. Fase di Verifica
Nel mondo nondetermistico alcuni problemi hanno soluzione polinomiale ma non implememntabile in tempo polinomiale con algoritmi detrministici

# Problemi P e NP
Lezione 26 -9min.
