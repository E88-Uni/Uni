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



Lez 20 -25min.
