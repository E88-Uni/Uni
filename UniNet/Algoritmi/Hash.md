# Tabelle ad Accesso Diretto
**Dizionari** Se Non è richiesto un ordine è possibile 
implementare le operazioni di base in tempo costante O(1)

Tabelle ad Accesso Diretto : Vettore **T** con un elemento per 
ogni possibile valore di una chiave  

Così posso usare il valore della chiave **k** come indice -> **T[k]**

Chiave Dizionario **k** viene memorizzata in T[k]

# Tabelle Hash

## Notazione
- **Universo :** Insieme di tutte le possibili chiavi **U = {1, ..., m}**
- **Tabella :** Ha dimensione **m = |U|** = Cardinalità di U
- **k** = {1, ...,  n} : Chiavi effettivamente memorizzate
- **n = |k|** il numero di chiavi è la Cardinalità dell'Insieme k

## Operazioni O(1)
- Search() : Accesso Tramite indice
- Insert() / delete() : Ogni chiave ha uno slot riservato, tramite indice.

## Problemi
- Se |U| è grande è impossibile allocare la tabella m = |U|
- n << m : Se Il Numero di Chiavi Usato è molto Minore al Numero di chiavi totali
  - L'utilizzazione della tabella è basso
  - Fattore di carico n/m

Es. gestione Matricole: n << m |U| = T[0, ..., 999999]
Chiavi = Studenti Inscritti n=100
Fattore di carico n/m 100/999999 = 10<sup>-4</sup>

Memorizza una Tabella T con m << |U| posizioni
Si definisce una funzione che definisce un indice h(k) a partire da k
h : U -> {0, ..., m-1}
**h() = funzione di hash**

# Funzioni Hash
Non Possono esere Iniettive
- Iniettivita : Se k1 = k2 allora h(k1) = h(k2)
- Non Iniettivita : Se k1 != k2 allora h(k1) = h(k2)

**Collisione :** Due chiavi possono finire nella stessa posizione
- Collisione non può essere eliminata/evitata
- Posso Ridurre le Collisioni con appropriate funzioni di hash
- Le Collisioni devono essere Gestite

## Requisiti Funzioni di Hash
1. Semplicità : h(k) deve esere calcolabile in O(1)
2. Uniformità : h(k) deve distribuire le chiavi in modo uniforme

### Criterio di Uniformità semplice 
Se le chiavi sono scelte da U secondo una distribuzionee P, 
inoltre k si considera come variabile casuale.

k : h(k) = j . j = 0, 1, ..., m-1

$\sum_j$ P(k) = 1/m

La Sommatoria per tutte le chiavi che hanno valore di hash.
Per la Probabilità che esse appaiano : deve essere 1/m.

## Metodo della Divisione
h(k) = k mod m = k%m . Uso il resto Intero della divisione.

Esempio : h(k) = k mod 100 : h(1254) = 54, h(918) = 18.

**Scelta m** è importante. Per Buona distribuzione Non si usano potenze di 2 o di 10.
Scelta tipica **Numero Primo Non Vicino a Una Potenza di 2**. 

Numero primo per minimizzare i divisori comuni. 
Questo Numro Primo è anche la Dimensione dell Tabella Hash.

# Gestione Collisioni
- Tabella di Dimensione = m -> Chiave di Hash
- Numero di Chiavi = n
- Fattore di Carico $\alpha$ = n/m -> Complessità Fondamentale

## Per Concatenazione
n >= m -> $\alpha$ = n/m >= 1
Elementi che Collidono Memorizzati in Liste di Collisione 
T[i] chiavi con h(k) = i

Ogni Elemento della Tabella Contiene un Puntatore a una **Lista di Collisione**

Gli Elementi che Collidono sono Memorizzati nella Stessa Lista $\alpha$ >= 1

### Analisi Complessità Concatenazione
Mi Baso sulla Distribuzione n/m
- Insert : O(1)
- Search\Delete : O(1+$\alpha$)

Se n=O(m) -> $\alpha$=O(m)/m=O(1) -> Search\Delete O(1)

## Per Indirizzamento Aperto
n <= m -> $\alpha$ = n/m <= 1
Tutti gli Elementi sono Memorizzati nella Tabella.
Se Una Cella è Occupata Viene Ricalcolata una Nuova Posizione.
La nuova posizione deve poter essere ricalcolata.
Non c'è Memoria Esterna

Possibili Algoritmi : Linear Probing, Quadratic Probing, Double Hashing.
Scansione Lineare, Scansione Quadratica, Doppio Hashing

Probing : Tentativo/Scansione

Funzione di hash Dipende dalla Posizione Cercata : h = h(k, i) 

h : U -> {0, ..., m-1}
k = chiave
i = **try** o Numero di Tentativi

Quindi h() Genera una **sequenza di probing** che sarà una 
Permutazione degli Indici <0, 1, 2, ..., m-1> ->

Sequenza di Probing:
<h(k, 0), h(k, 1), h(k, 2), h(k, 3), ..., h(k, m-1)>

### Operazioni
**HashDelete :** Cancellare Porta alla "rottura" della sequenza -> Tabella di ConsUltazione

## Linear Probing
Se la cella è occupata vado a quella dopo e se arrivo in fondo riparto dalla prima cella
Esamina Posizioni Consecutive : 
h(k, i) = (h'(k) + i) mod m

h'(k) : Funzione di Hash Primaria

Es. k(k, i) = (k mod 11 + i)mod 11

Complessità Peggiore è Ricerca Senza Successo : O(1/(1-$\alpha$))

## Doppio Hashing

Lez 17 -2min.
