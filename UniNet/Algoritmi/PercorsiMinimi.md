# Percorsi Minimi di un Grafo
## Definizioni
Dato un grafo orientato G=(V, E) con una funzione di peso w: E->V

ed un percorso p(v<sub>0</sub>, v<sub>1</sub>, ..., v<sub>k</sub>)

il costo w(p) del percorso è la somma dei pesi corrispondenti

$$
w(p) = \sum^k_{i=1}w(v_{i-1}, v_i)
$$

Percorso minimo tra due vertici **u e v** se esiste un percorso tra loro :
$\delta$(u,  v) = min(w(p) : u -> v) 

Se non esiste un percorso tra loro : $\delta$(u,  v) = $\infin$

Quindi ricerco il percorso minimo tra due vertici u e v : **w(p) = $\delta$(u,  v)**

## Varianti
1. Sorgente Singola : Ricerco il percorso minimo da un vertice sorgente a tutti gli altri vertici
2. Sorgente Multipla : Ricerco tra tutte le coppie di vertici
3. Archi con Peso Negativo : 
    - Può non essere definito un percorso minimo
    - Percorso Minimo Sicuramente non definito in presenza di ciclo a peso negativo

## Algoritmi Percorsi minimi
- BFS : Visita in Apiezza, Archi con stesso Peso unitario O(V + E)
- Algoritmo di Dijkstra : Pesi non negativi
- Algoritmo di Bellman-Ford : Pesi negativi

## Proprietà
Un albero dei percorsi minimi con radice s, quindi calcolo dei percorsi minimi con sogente singola, 

è un sottografo orientato G'(V', E') di G con V' in V e E' in E.
G' : è un albero con radice s
V' : Insieme dei vertici raggiungibili da s

Per ogni vertice v in V' l'unico percorso semplice da s a v è minimo, c'è un unico percorso perchè è un albero

# Rilassamento
**Operazione base di tutti gli algoritmi per il calcolo dei percorsi minimi**

Tutti questi algoritmi sfruttano proprietà :
- Sottostruttura Ottima 
- Usano la speciale operazione del rilassamento
  
## Sottostruttura Ottima 
Scomponiamo un percorso minimo da s ad un vertice v come segue :
s -p'-> u -> v

Peso del cammino minimo da s a v : $\delta$(s, v) = $\delta$(s, u) + w(u, v)

## Rilassamento
Applicato ad un arco  (u,v)

Verifica se è possibile ottenere un percorso minimo tra s e v attraverso u

**Operazione** che tenta di decrementare la stima d[v] del percorso minimo v. Se essa avviene aggiorna anche il predecessore di v ch è p[v]

d[v] : limite superiore per la distanza minima da s a v. Inizialmente = $\infin$

p[v] : predecessore di v nel prcorso minimo attuale da s a v. Inizialmente = NULL

```c
Relax(u, v, w(u, v)) {
    if (d[v] > (d[u] + w(u, v))) {
        d[v] = d[u] + w(u, v);
        p[v] = u;
    }
}
```

# Algoritmo di Dijkstra
Mantiene un Insieme S di vertici le cui distanze minime sono state calcolate : d[u] = $\delta$(s, u)  

- Sceglie in modo **greedy** il vertice u di V-S con minima d[u]
- Aggiunge u ad S
- Rilassa gli archi da u

Visita in Ampiezza dove invece di una coda normale usiamo una coda a priorità Q, la priorità  è il minimo valore della stima. Q memorizza i vertici e usa il valore d[] come chiave

```c
Dijkstra(G, s) {
    inizialize(G,s);//d=infy, p=NULL
    d[s]=0;//Distanza dal veertice 0
    empty_list(S);//Lista Ordinata definitiva
    Q=V(G);//Coda con tutti i vertici
    while (!empty_list(Q)) {
        u = delete_min(Q);
        S = insert(S, u);
        for v adiacenti a u {
            Relax(u, v, w(u, v));
        }
    }
}
```
![alt text](img\dijcastrass.jpg)

Costo O(ElogV) :
- Inizializza $\Theta$(V)
- While $\Theta$(V)
  - delete_min O(logV)
  - for adiacenti : O(E)
    - relax : (d[v],d[u] + w(u,v)) : O(logV)

O(V)+O(VlogV)+O(ElogV) = 
O((V+E)*logV) = O(ElogV)

# Algoritmo di Bellman-Ford
Itera numero di vertici -1 : |V|-1.
Ad ogni passo **applica relax** ad ogni arco.

Uso per pesi negativi
```c
Bellman_Ford(G, s) {
    inizialize(G, s, d);//d=infy, p=NULL
    for i = 1 to |V|-1 {
        foreach arco(u, v) in E {
            relax(u, v, w)
        }
    }
    forach arco(u, v) in E {
        if(d[v]>(d[u]+w(u,v))) {
            return FALSE
        }
        return TRUE
    }
}
```

Costo O(V*E) : |V| per ogni arco O(E)
