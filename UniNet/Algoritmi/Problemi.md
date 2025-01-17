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
Problemi Polinomiale(P) e NondeterministicoPolinomiale(NP)

Problemi P risolubili in O(n<sup>k</sup>), con k piccolo, da un algoritmo deterministico

Problemi NP, che sono verificabili in tempo polinomiale

Gli Algoritmi deterministici sono un caso speciale di quelli nondeterministici

Ci sono problemi che sono NP ma non sono P, non esiste una soluzione in
tempo polinomiale e quindi è un **Problema intrattabile**

Alcuni problemi NP sono più difficili di altri

## Riducibilità
Dati due problemi A e B, A è riducibilea B se
1. Esiste una funzione f (algoritmo deterministico polinomiale), che trasforma istanze di A in istanze di B
2. La risposta ad A per l'input x è SI solo se la risposta a B per l'input f(x) == SI
### Esempio Riducibilità
A : Date n variabili Booleane x1, x2, ..., xn, esiste almeno una variabile con valore VERO ?
B : Dati n numeri interi, il più grande di essi è positivo?
```c
foreach i in B {
    if(i > 0)    {
        return true;
    }
}
return false;
```
Per trasformare Istanze di A in Istanze di B :
```c
foreach j in B {
    if x[j] == True {
        i[j] = 1;
    }else{
        i[j] = 0;
    }
```

## NP-hard
Un problema A è NP-hard se per ogni altro problema A' in NP.
A' è riducibile ad A
## NP-Completi
Un problema A è NP-Completo se :
1. E' in NP
2. Per ogni altro problema A' in NP, A' è riducibile ad A -> quindi è anche NP-hard

Se qualunque problema nella classe NPC fosse risolubile in tempo polinomiale. 
Allora tutti i problemi NP possono essere risolti in tempo polinomiale.

![alt text](img\problemiNP.jpg)

- Parte gialla deel grafico, problemi non risolvibili in tempo polinomiale
- P : Problemi Facili
- NP : Problemi facili da verificare ma probabilmente difficili da risolvere
- NPC : Problemi più Difficili tra gli NP  

Dimostrazione di NP-Completezza :
1. Si mostra che il problema è in NP, verificabile in tempo polinomiale
2. Un problema noto come NPC può essere ridotto a questo problema : Serve un insieme di NPC noti

**Teorema di Cook** 1971 : Il problema della soddisfacibilità Booleana (SAT) è NPC

Problema SAT : Trovare un'assegnazione di valori (vero o falso) ad un a<sub>i</sub> 
per cui la formula :

a<sub>1</sub> op a<sub>2</sub> op... a<sub>n</sub> è vera . Con 'op' operatore booleano

Esempio problema SAT : x<sub>1</sub> OR x<sub>2</sub> OR ( x<sub>3</sub> AND x'<sub>1</sub> AND x'<sub>2</sub> ) è soddisfacibile?

SI perchè l'assegnazione :(x<sub>1</sub> = False, x<sub>2</sub> = False, x<sub>3</sub> = True) soddisfa la formula 

: 0 or 0 or (1 and 0' and 0') = 0 or (1 and 1 and 1) = 1

Esempio formula non soddisfacibile : x<sub>1</sub> AND x'<sub>1</sub>

### Algoritmo SAT NP
SAT Non Deterministico
```c
NDSat(E, n) {//O(n) ma non deterministico
    for i = 1 to n {
        x[i] = choice(0, 1);/*Scelta true o false*/
    }
    if Expression(x[1], x[2], ..., x[n]) = T {/*Verifica*/
        return success();
    } else {
        return false();
    }
}
```

## NP Completi Classici
Usando la riducibilità partendo da un SAT NP, è stato dimostrato che altri numerosi problemi classici sono NPC

TODO : Googla "lista problemi NPC"

Alcuni esempi classici derivanti da SAT :
- Problema della massima clique (problemma di decisione)
  - Problema della copertura dei vertici
    - Problema del commesso viaggatore (TSP)
- Sottoinsiemi : Problema dello zaino

### Problema della massima clique
Dato un grafo non orientato determinare e contiene un sottografo connesso(clique) di dimensione k

### Problema della copertura dei vertici
Dato un grafo non orientato G=(V,E) ed un intero k. 
Determinare se esista un insieme di k vertici C in V, 
per cui ogni arco (u,v) in E abbia uno dei cue vertici u o v in C

### Problema del commesso viaggatore 
Dato un grafo connesso e pesato G(V,E,w). Esiste un ciclo che visita ogni vertice più di una volta e ha costo pari a d?

### Problema dello zaino
Data una serie di n oggetti, ognuno con il suo peso w e il valore v.
Esiste un insieme di oggetti con peso totale al massimo W e valore totale V?

Non Polinomiale perchè algoritmo che lo risolve ha complessità O(nW) con W non costante. Algoritmo di soluzione detto pseudo-polinomiale
## Algoritmi Pseudo-Polinomiali
Quando il tempo di esecuzione è polinomial nel valore numerico dell'input.
Che però è esponenziale nella lunghezza/dimensione degli input.

Perchè N cifre in base B esse codificano in B<sup>N</sup> valori. es 3^2 = 8 [000, ..., 111]

# Risolvere Problemi NP-Hard
2 Opzioni Algoritmi : Approssimati o Euristici
## Algoritmi Approssimati
Adatti a problemi di ottimizzazione

Garantiscono che una soluzione sia vicina entro una certa % rispetto alla soluzione ottimo
### Copertura dei vertici Approssimata
```c
ApproxVertexCover(G(V,E)) {
    create_empty(C);
    copy(Ei, E);//Copio Tutti gli archi E in Ei
    while not_empty(Ei) {
        e = choice(Ei);//scelgo un arco
        (u, v) di e;
        add((u, v), C);//Aggiungo la coppia di vertici tra l'arco
        list = ogni arco che incide su u o v
        remove(list, Ei);
        
    }
    return C;
}
```
## Algoritmi Euristici
Algoritmi che non hanno una garanzia di qualità.
Algoritmi che si comportano bene in casi specifici detti tipici.

Spesso si scelgono delle Euristiche che sono greedy
