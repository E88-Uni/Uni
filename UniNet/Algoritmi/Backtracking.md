# Paradigmi Basati su Ricerca
Dove l'**unica opzione** è quella di verificare tutte le possibilità.
Dove non esiste la sottostruttura ottima, bisogna verificare : 
**Lo spazio delle soluzioni**

## Ricerca Esplicita
**Brute-Force** : Enumera Esaustivamente tutti i candicati. 
Costo proporzionale al numero di soluzioni candidate

Esempio calcolare tutti i divisori di n, provo tutti gli interi da 1 a n

## Ricerca Implicita
Si fa una potatura detta **Pruning** dello spazio delle soluzioni basata sulle proprietà di essa

Esempio calcolare tutti i divisori di n, poto/tolgo dai test 
tutti i multitpli di un valore che non è divisore. 
20 ->Testo 3 e Tolgo(3, 6, 9, 12, 15, 18) 

# Spazio delle Soluzioni
Tramite un **Albero di Decisione**, che rappresenta le **Possibili Soluzioni** 
- Radice : Nessuna Decisione
- Nodi Interni : Decisioni
- Foglie : Soluzioni Candidate

Grado dell'albero = Possibili Soluzioni Ad Ogni Passo

## Problema Esempio
Enumerare tutte le parole di 3bit con 2 o più 1
Possibilità : 2^3 = 8


# Backtracking
Paradigma Algoritmico Basato su Ricerca.
**Variante**  dell' algoritmo **brute-force** : 
Spazio delle Soluzioni Sistematicamnete  Esplorato, cioè,  

Vista in preordine dell'albero delle decisioni

##  Algoritmo Backtracking
Soluzione il vettore a(1), a(2), ..., a(n)

Ogni Elemento a(i) è Scelto da un Insieme Ordinato S
### Schema
v : vettore soluzioni inizializzato a vuoto.
 
Ad ogni Passo,
v è esteso con nuovi valori esempio passo k:
v = {a(1), a(2), ..., a(k-1)} -> v = {a(1), a(2), ..., a(k-1), a(k)}

Controllo al passo k se l'Insieme delle soluzioni parziali è accettabile.
Se lo è continuiamo quella via, altrimenti provo un altra soluzione k.

Quando le scelte a(k) sono terminate si fa il **backtrack** e si torna indietro,
alla prossima scelta per a(k-1)
### Pseudocodice
- i : Generico Candidato
- k : Livelli di Ricorsione
- m : num. di candidati ad ogni livello(i = 1, ..., m)
- n : Dimensione della Soluzione (n candidati)

Algoritmo Controlla tutte le possibili soluzioni accettabili e quella Ottima
```c
Backtrack(k){//Parte con k=1
    if(k>n) {
        return;
    }
    i = 0;
    do{
        i++;
        if(accettabile(v)){
            a[k] = Candidato_num(i);//Candidato i-esimo
            insert_vect(v, a[k]);
            Backtrack(k+1);
            if(successo(v)) {
                delete_vect(v, a[k]);
            }
        }

    }while(not_successo(v) && i != m)
}

Backtrack(k){
    for(int i=1; i<=m; i++) {
        a = Candidato_num(i);
        if(accettabile(a)) {
            insert_vect(v, a);
        }
        if(k<n) {
            Backtrack(k+1);
        }else{
            saves(v, ++id);/*memorizzo soluzioni Migliori*/
            print(v);/*memorizzo soluzioni Migliori*/
            idsol = find_best_sol(v);
            if(id == idsol){
                copy(ottima, v[idsol]); 
            }
        }
        delete(v);
    }
}
```
## Uso Backtracking
Si vogliono scrivere tutte le possibili combinazioni di lunghezza n(input n)

## Esempio
Enumerare tutte le Parole di 3bit con 1 o più "1".

n = 3 . m = 2 [0,1] . i = {1, 2}

```c
void gen_words(int n, int *A, int i) {
    if( n==i ){
        for(int j=0; j<n; j++) {
            printf("%d", A[j]);
        }
        printf("\n");
        return;
    }

    for(int j=0; j<=1; j++) {
        A[i] = j;
        if( j==1 || (i>0 && A[i-1]==1)){//Se almeno 1 bit "1"
            gen_words(n, A, i+1);
        }
    }
}
```
