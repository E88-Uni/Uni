# Ordinamento
Problema Informatico più studiato, poichè comprende il 25% del lavoro medio dei calcolatori
## Definizioni
Ordine : con Relazione $\R$ su un insieme S tale che dati **a, b, c € S**. 

Con Proprietà :
- Simmetrica a $\R$ a
- Transitiva a $\R$ b AND b $\R$ c <-> a $\R$ c 
- AntiRiflessiva a $\R$ b AND b $\R$ a <-> a = b

Esempio la Relazione $\R$ $\=<$ o <= è valida. 

Ma < e basta non è valida come $\R$ perchè non è AntiRiflessiva. 

## Assunzioni
Data una sequenza di n valori : A=(a<sub>1</sub>, ..., a<sub>n</sub>)

Calcola una permutazione A'=(a'<sub>1</sub>, ..., a'<sub>n</sub>) tale che a'<sub>1</sub> <= a'<sub>2</sub> <= ... <= a'<sub>n</sub> 

Altre Assunzioni :
- O(1) : Accesso ad un elemento
- O(n) : Dimensione del vettore
- Ordinamento senza duplicazione cioè **Ordinamento in Loco** non fa copie aggiuntive degli elemento, si lavora sul vettore di input. 

### Esempio
n = 6 -> A = (2, 5, 1, 3, 0, 9) -> 
A' = (0, 1, 2, 3, 5, 9)

## Classi di Ordinamento
Classi degli Algoritmi : Quadratici, Logaritmici, Lineari.

Ordinamento basato sulla **Complessità Asintotica :**
- Quadratici - O(n<sup>2</sup>) : BubbleSort, Insertion Sort, Selection Sort
- Logaritmici - O(nlogn) : MergeSort, HeapSort, QuickSort
- Lineari - O(n) : Counting Sort

**Nota** vengono chiamati "algoritmi di ordinamento logaritmici" ma sono di complessità nlogn e **NO logn**

## HeapSort
Basato sullo **heap** come **struttura dati di ordinamento** permette con efficenza di sapere **min e max** di una sequenza. 

Algoritmo non tangibile da caso migliore o peggiore. Si comporta sempre similmente.

Heap coda a priorità non basata sull'ordine di arrivo come coda o stack **non è lifo o fifo**.

**Heap** Struttura che Rappresenta un Ordinamento Parziale sull'Insieme

**Heapify :** 
- Mantiene la proprietà dello heap
- Applica ad un elemento i
- Assumo che sottoalberi di i siano heap
- Costo O(log<sub>2</sub>n)

**BuildHeap :**
- Converte vettore A[1, ..., n] in heap
- Applica Heapify ad ogni nodo interno
- Costo O(n)

**Algoritmo HeapSort :**
1. Trasforma il vettore in heap con **BuildHeap**
2. Eliminazione Ripetuta del Massimo mantenendo la proprietà heap, tramite **iterazione heapify**

```c
void HeapSort(int A[], int dim) {
    int i = dim-1;
    BuildHeap(A, dim);
    for(; i<=1; i--) {
        swap(A[0], A[i]);
        dim--;
        Heapify(A, 0);
    }
}
```


```c
/* Metto in testa il più alto */
void max_heapify(int *A, int dim, int idP) {
	int k = 2 * idP + 1;/* idFigli */
	if(k < dim){
		int idMax = k + (k+1 != dim && A[k] < A[k+1]);
		/* se padre più piccolo */
		if(A[idMax] > A[idP]){
			swap(A, idMax, idP);
			max_heapify(A, dim, idMax);/* sistemo i figli dal lato swap */
		}
	}
}

void heapSort(int *A, int dimHeap) {
	/* sistemo i nodi, foglie coontrollate da max_heapify */
	int i = dimHeap/2;
	while(i--){
		max_heapify(A, dimHeap, i);
	}
	/* sostituisco la testa con tutti i valori */
	for(i = dimHeap - 1; i>=0; i--) {		
		swap(A, i, 0);
		max_heapify(A, i, 0);
	}
}
```

## QuikSort

Basato su **Divide et Impera**. Algoritmo ricorsivo basato su sottovettori.

Chimato quick perchè tra i migliori basati fra il confronto.

Fasi :
1. Scelgo **Pivot** un elemento 
2. Riorganizzo il vettore in base al Pivot, ordinamento parziale
    1. Sposo a sinistra tutti gli elementi <= del Pivot
    2. Quindi tutti elementi >= del Pivot saranno spostati a dx
3. Ordino Ricorsivamente le Due Partizioni


Sensibile ai dati a differenza dell'heapSort. Casi :
1. Caso Migliore, quando le due partizioni sono bilanciate : T(n) = 2T(n/2) + O(n) -> O(nlogn)
2. Caso Peggiore, quando le due partizioni sono fortemente sbilanciate : T(n) = T(n-1) + T(1) + O(n) -> $\Theta$ (n<sup>2</sup>)
3. Caso Medio O(nlogn) basta che in media le partizioni siano proporzionate al dilà delle singole

```c
int partition(int *A, int l, int r) {
    int Pivot = A[r]; /* ultimo elem Array */
    int i = l - 1, j = l;
    for(; j<r; j++){
        if(A[j] <= Pivot){
            swap(A, ++i, j);
        }
    } 
    swap(A, ++i, j);/* il Pivot si inserice tra i due sottorray, j = r */
    return i;
}

void quickSort(int *A, int l, int r) {
    if(l < r){
        int idPivot = partition(A, l, r);/* = partition(A, l, r); */
        quickSort(A, l, idPivot - 1);
        quickSort(A, idPivot + 1, r);
    }
}
```

## Limiti Teorici
Non si può fare meglio di O(nlogn) senza assunzioni sui valori e se usiamo dei confronti.

### Teorema
Un albero di decisione che ordina **n** elementi ha un altezza $\Omega$(nlogn)

### Corollario
Nessun algoritmo di ordinamento basato sui confronti può avere complessità inferiore a nlogn

### Dimostrazione
L'Albero di decisione **è binario**, data altezza **h** ha al massimo **2<sup>h-1</sup>** foglie

Num.Foglie >= Num.Permutazioni -> **2<sup>h-1</sup> >= n!**

-> **h-1 >= log<sub>2</sub>(n!)**

-> **log<sub>2</sub>(n!) >= log<sub>2</sub>(n/e)<sup>n</sup> = nlog<sub>2</sub>(n/e) = nlog<sub>2</sub>n - nlog<sub>2</sub>e**

-> **h-1 >= nlog<sub>2</sub>n - nlog<sub>2</sub>e**

-> **h = $\Omega$(nlogn)**

### Approssimazione di Stirling 
**n! >= (n/e)<sup>n</sup>** 

con e = 2.7 costante di Eulero

### Visualizzare Graficamente Limiti Teorici

**O(nlogn) è la migliore complessità possibile** per un algoritmo basato sui confronti 

Possiamo dimostrare che è la migliore complessità basandoci su una rappresenntazione dei confronti con un **albero di decisione** :
- **Nodo :** Un Confronto tra Due valori
- **Foglia :** Una delle possibili permutazioni
- **Percorso :** Da radice a foglia rappresenta una possibile esecuzione dell'algoritmo per un dato insieme di valori
- **Altezza :** numero di confronti per l'ordinamento, cioè le permutazioni nel caso peggiore

![alt text](img\LimitiTeorici.png)

