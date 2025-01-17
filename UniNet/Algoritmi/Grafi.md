# Grafi
Quando Non sono Rilevanti Solo gli Oggetti,  ma anche le **relazioni tra essi**

Esempi :
- Mappa : Oggetti Città, Relazionati tra loro con strade e distanze
- Reti di Calcolatori : Oggetti Dispositivi Computer e collegati con internet/elettricità/banda
- Pagina e Link
- Circuiti 
  
## Definizioni e Proprietà
### Definizione
Un grafo **G** è una **coppia (V, E)** dove :
- V : Insieme di Vertici (Oggetti)
- E : Insieme di Archi (relazioni tra Vertici)

**Arco :** è una coppia di vertici (v, w) compresi nell'Insieme V

### Varianti
**Grafi orientati :** G(V, E) in cui l'Insieme di Archi E è una Relazione Binaria tra i Vetrici. Le Relazioni hanno una direzione. Cioè (A, D) != (D, A). Può Esistere Anche (F, F).

**Grafi Non Orientati :** G(V, E) l'Insieme di Archi E non è ordinato, arco non ha una direzione. (A, D) == (D, A)

**Incidenza :** se arco 'e(w, v)', Nel grafo Orientato, Si dice che 'e' è incidente dal vertice 'w' al vertice 'v'.
Nel Grafo Non Orientato, si dice che 'e' è incidente sui vertici 'w'e 'v'. 

**Adiacenza :** Un vertice w è adiacente a un vertice v se (v, w) Esiste in E. Si Indica con notazione v->w : **B -> A**.
In un Grafo Non Orietato la Relazione di Adiacenza è Simmetrica : 
A -> B implica B -> A

### Adiacenza vs Incidenza
- Adiacenza : Relazione tra Vertici v e w
- Incidenza : Relazione tra Vertice ed Arco. Vetice v e arco 'e' Sono Incidenti.

### Grado di un Vertice
**Grafo Non Orientato :** Il Grado di un Vertice v è il numero di Archi incidenti ad esso.

**Grafo Orientato :** Numero di archi **entranti** e numero di archi **uscenti**

## Grafi Pesati
Ad Ogni Arco è Associato un Peso w. O tramite funzione w(A, B).
w : E->R . Con R Insieme di Interi o Reali.

Es. c(A,B) = 3 oppure c(D, E) = -2.3 oppure c(A, F) = $\infin$

Se Due Vertici non sono uniti da un arco si assume arco di peso infinito.

## Sottografo
Dato Grafo G=(V, E) è sottografo H=(V*, E*) tale che V* è un sottoinsieme di vertici V ed E* è un sottoinsieme di archi E.

Essendo H un grafo deve valere che Insieme degli archi E* 
è sottoinsime del prodotto cartesiano V* x V*.
Cioè Archi devono essere connessi.

## Sottografo Indotto
Dato un sottoinsieme di vertici V* di V, dei vertici di un Grafo G=(V, E)

Il sottografo di G indotto da V* è il grafo H=(V*, E*) tale che

E* è tutti gli archi appartenenti all'Insieme E i quali uniscano vertici appartenenti a V*.

Cioè scelti gli elementi/vertici mi porto tutti gli archi tra loro.

## Percorso/Cammino
Un Percorso/Cammino in un grafo G=(V, E) è una sequenza di vertici <w1, w2, ..., wn> tale che (wi, wi+1) è un arco del mio Insieme per ogni i. 
Con 1<= i <= n-1.

La Lunghezza di un Cammino : Numero di archi <w1, w2, ..., wn> è n-1

Il grafo G=(V, E) ha un Percorso/Cammino se esiste un Arco (v, w) tale che v e w sono vertici dello stesso grafo

Un cammino tra vertici contiene questi vertici e gli archi tra loro

## Cammino Semplice
Se tutti i vertici sono disgiunti, cioè distinti

## Cilco
Se il primo e l'ultimo vertice coincidono, il cammino è detto **ciclo**

Grafo che non contiene cicli è detto **aciclico**

## DAG
Directed Acyclic Graph. Un Grafo aciclico ed orientato.

## Raggiungibilità
Se esiste un percorso 'p' tra i vertici 'v' e 'w', 
allora 'w' è raggiungibile da 'v' attraverso il percorso 'p' : 
**v -p-> w**

Un Grafo non orientato 'G' è **connesso** se ogni coppia di vertici 
è connessa da un cammino.

Un grafo orientato 'G' è **fortemente connesso** se esiste un percorso 
tra ogni coppia di vertici.

Un grafo è **competo** e ogni coppia di vertici ha un arco. 
Con n vertici posso calcolare gli archi (V*V -V)/2

## Alberi
Un **Albero Libero** è un grafo non orientato, connesso e aciclico.

Se un vertice è designato come vertice iniziale-radice l'albero si dice **Albero Radicato** e NON è un albero Liberos

## Rappresentazione dei Grafi
**Due Rappresenetazioni Canoniche :**
1. Matrice di Adiacenza : Memoria occupata O(|V|<sup>2</sup>), utile quando tanti archi e pochi vertici, cioè grafo denso
2. Lista di Adiacenza : Memoria occupata O(|V|+|E|), conveniente per grafi sparsi

![alt text](img\MatriceAdiacenza.JPG)

![alt text](img\ListeAdicenza.JPG)

# ADT Grafo
Grafo come Dato Astratto : 
- Implementazione tramite **Lista di Adiacenza**
- Lista Bidimenionale : [Lista Vertici][Lista Vertici Adiacenti]

```c
/*Vetrici*/
typedef struct graphnode *NodePtr;
typedef struct graphnode {
    char *Name;
    /*Altri Campi*/
    NodePtr Next;
    EdgePtr AdjList;
    /*Predecessore*/
} Node;

/*Archi*/
typedef struct edge *EdgePtr;
typedef struct edge {
    int Weight;
    /*Altri Campi*/
    NodePtr NextNode;
    EdgePtr NextEdge;
} Edge;
```

![alt text](img\EsempioStructGrafo.JPG)

## Primitive

```c
NodePtr SearchNode(NodePtr List, char *Name);
int InsertNode(NodePtr *PList, char *Name);
int InsertEdge(NodePtr List, NodePtr elem, int Weight);
int DeleteNode(NodePtr *PList, char *Name);
int DeleteEdge(NodePtr List, NodePtr elem, int Weight);
```
Non è richieesta nessuna struttura dati speciale per le liste adiacenti.
Tutte le primitive richiedono ricerca/inserimento/cancellazione da una lista bidimenionale.

# Visite
Cioè l'**Attraversamento di Tutti i Vertici**

2 Tipi Partendo da Nodo Sorgente: 
- **Visita in Ampiezza**
- **Visita In Profondità**

## Applicazioni Visite
- Vertici Raggiungibili da un dato vertice
- Verifica dell'esistenza di cicli
- Verifica di Connettività

## Visita in Ampiezza
Scopre tutti i vertici a distanza n. in archi, 
dal nodo sorgente, poi scopre quelli a distanza n+1

## Visita in Profondità
Partendo dal nodo sorgente, scopre tutti i vertici adiacenti, 
al vertice scoperto per ultimo.

# Algoritmo Visita
Algoritmo di Visita **generico**. Classificazione dei vertici.
Bianco : Vertici non scoperti o visitati.
Grigio : Quando è visitato ma i vertici adiacenti non sono stati visitati tutti
Nero : Verice visitato con tutti i suoi vertici adiacenti visitati

**Pre-processing : Inizializzazione dei Nodi**
```c
Inizialize(G) {
    for u : V //Costo O(V)
        color[u] = white
}
```

Logica del predecessore : può essere importante ricordare il vertice 
da cui sono arrivato/partito per scoprire un nuovo vertice.
Associamo un attributo predecessore P[u] ad ogni vertice inizializzato  NULL.

Dopo la funzione Visit(G, s) solo i vertici neri eccetto s, 
hanno predecessore NON nullo

Grafo Connesso, cioè dalla sorgente posso raggiungere tutti i nodi, 
allora la sorgente è l'unico vertice che non ha un predecessore.

Sottografo dei predecessori :  G<sub>p</sub> = (V<sub>p</sub>, E<sub>p</sub>)

V<sub>p</sub> : Tutti i vertici di V che hanno predecessore NON NULLO, più il nodo sorgente/radice. Cioè tutti i vertici neri raggiungibili da s "Sorgente".

E<sub>p</sub> : Archi dall'Insieme E di partenza, Tutti gli archi nell'Insieme che vanno da un predecessore a un vertice di V, per tutti i vertici V tolto il nodo sorgente/radice

G<sub>p</sub> = (V<sub>p</sub>, E<sub>p</sub>). 
G<sub>p</sub> = Albero o Foresta di Alberi 

Se grafo non connesso G<sub>p</sub> = Foresta di Alberi 

Per gestione vertici grigi usiamo struttura dati D 
in cui gli elementi sono ordinati.

### Operazioni su D
- create_empty : Crea una struttura dati vuota
- first(D) : Preleva il primo elemento senza modifiche
- add(D, elem) : Aggiunge un nuovo elemento a D
- remove_first(D, elem) : Rimuove il primo elemento da D
- not_empty(D)  : True se D non è vuoto, False altrimenti

## Vista Generica
```c
Inizialize(G) {
    for u : V //Costo O(V)
        color[u] = white
}
Visit(G, s) {
    D = create_empty();
    /*Sorgente colorata di grigio e aggiunta alla struttura dati D*/
    color[s] = gray;
    add(D, s);
    while not_empty(D) {
        u = first(D);
        flag = Esiste un vertice bianco v adiacente a u?
        if(flag) {
            color[v] = gray
            P[v] = u
            add(D, v)
        } else {
            color[u] = black
            remove_first(D)
        }
    }
}
```

# BFS - Visita in Ampiezza
Breadth-First Search

Scopre tutti i vertici a distanza n (n. di archi)
dalla sorgente prima di scoprire quelli a distanza n+1

Usa una **coda** per memorizzare i **vertici**

Calcola la **distanza** in n. di archi di ogni vertice dalla sorgente

Viene generato un **albero di visita**, con s come radice, 
che include tutti i vertici raggiungibili dalla sorgente

Ogni Cammino da s ad un vertice è minimo in n. di archi.

Vertici non collegati hanno distanza infinita.

Costo di tutte le liste di adiacena corrisponde all' numero di archi O(E)

```c
BFS (G, s) {//Costo O(V + E)
    Q = create_empty();//Costo O(V)
    color[s] = grey;
    d[s] = 0;//Distanza 0 da sorgente rispetto a se stessa
    enqueue(Q, s);//Aggiunge in coda
    while not_empty(Q) {//Costo O(E)
        u = head(Q);
        for (ogni v adiacente a u) {
            if color[v] == white {
                color[v] = grey;
                P[v] = u;//Predecessore salvato
                d[v] = d[u] + 1;
                enqueue(Q, v);//Aggiungo alla coda dei vertici grigi
            }
        }
        dequeue(Q);//Elimino perchè vertice diventa nero
        color[u] = black;
    }
}
```
### Proprietà BFS
Detta $\delta$(s,v) la minima distanza cioè n. di archi tra s e v.
Dopo la BFS(G, s) si ha che la distanza tra ogni vertice è uguale alla distanza minima

# DFS - Vista in Profondità
Depth-First Search

Scopre tutti i vertici adiacenti al vertice scoperto per ultimo

Uso uno stack - Coda LIFO - Pila

Il Grafo dei Predecessori può risultare in una **foresta di alberi**.
Visita ripetuta da più sorgenti.
Vertici non collegati vengono esaminati, partendo la ricerca da un altro vertice.

```c
DFS (G, s) {//Costo O(V + E)
    S = create_empty_stack();//Costo O(V)
    color[s] = grey;
    push(S, s);
    while not_empty(S) {//Costo O(E)
        u = top(S);
        for (ogni v adiacente a u) {
            if color[v] == white {
                color[v] = grey;
                P[v] = u;//Predecessore salvato
                push(S, v);//Aggiungo alla coda dei vertici grigi
            }
        }
        pop(S);//Elimino perchè vertice diventa nero
        color[u] = black;
    }
}
```

Visita in Profondità, **somiglianza** con visita in ordine infisso di un albero. Vista in Profondità può essere implementata **ricorsivamente** come nel caso di vista alberi in ordine infisso.


## Etichette Temporali
Implementazione per Vista in Profondità. 
DFS marca ogni vertice con informazioni di tempo :
- d[v] : tempo in cui v viene scoperto (grigio)
- f[v] : tempo in cui v è processato (nero)

Info utili per applicazioni delle DFS. 
Notazione Ogni vertice è etichettato con coppia d[v]/f[v]

# CFC
Componenti fortemente connesse : è un sottografo massimale in cui
esiste un cammino orientato tra ogni sua coppia di nodi

# Applicazioni DFS

## Esempio
Calcolo delle componenti fortemente connesse di un Grafo orientato.
Utilizzando **Algoritmo con uso del Grafo Trasposto**

Dato grafo orientato : G(V, E).
Il grafo trasposto : Gt(V, Et), Ottenuto invertendo il verso degli archi

Et = { (u, v) : (v, u) ∈ E }

Note : Vedi Algoritmo di Kosaraju

```c
CFC(G){
    DFS(G);
    Costruisci Gt;
    DFS(Gt) processando i vertici in ordine inverso di f[v];
    Ritorna i vertici di ogni albero DFS come una CFC distinta;
}
```
![alt text](img/GrafoInverso.JPG)
