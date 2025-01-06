# Algoritmi O(n)
Algoritmi con **complessità lineare**, per oltrepassare il limite teorico $\Omega$(nlogn), bisogna andare oltre le **Assunzioni Elencate**

## O(nlogn) Ottimale
**Assunzioni** :
- Ordiname basato su **confronti**
- Ordinamento in Loco quindi no vettori di appoggio
- Nessuna Assunzione sul Valore dei Dati

## Counting Sort
Calcolo la distribuzione dei valori in un range k

**Assunzioni** :
- Ordiname NON basato su **confronti**
- Ordinamento NON in Loco quindi usa vettori di appoggio
- Assunzione sul Valore dei Dati : Elementi appartengono a un Intervallo da partenza (0/1) a k . es. Anni [0, 130], Voto [18, 30], ecc.

Conoscenza del **Range dei valori** permette di calcolare la **posizione senza confronti**

### Complessità O(k+n)
**k = Dimensione del Range**

Memoria Necessaria O(k)

Se k=O(n) allora complessità lineare
```c
void countingSort(int *A, int dim) {
	int max = 0, i = dim, id = 0;
	int *v;
	/* 1. Creo v[max+1] settato a 0 */
	while(i--){
		max = (A[i]>max)? A[i] : max;
	}
	max++;
	v = (int *)malloc(sizeof(int)*max);
	for(i=0; i<max; i++){
		v[i] = 0;
	}
	/* 2. setto v[A[i]]++ */
	for(i=0; i<dim; i++){/* indica n valori presenti corrispondenti a quell'id */
		v[A[i]]++;
	}
	/* 3. while(v[i]), Inserisco e decremento */
	for(i=0; i<max; i++){
		while(v[i]){    /* se cella valida */
			A[id++] = i;/* i di v corrisponde a un valore */
			v[i]--;		/* prendo il valore quindi decremento */
		}
	}
	free(v);
}
```

## Stabilità
Un Algoritmo di Ordinamento si dice Stabile se presenta l'ordine relativo degli elementi con identica chiave nella sequenza originale.

Esempio : Ordinamento per anno di corso di una lista per studenti già in ordine alfabetico.
L'algoritmo **è stabile** se manterrà gli studenti dello stesso anno in ordine alfabetico.

La Stabilità può essere ottenuta anche tramite un algoritmo di ordinamento non stabile **associando un sottoindice ad ogni chiave**. Es [3,3,3] -> [3<sub>0</sub>,2<sub>1</sub>,3<sub>2</sub>] 

# Conclusioni

![alt text](img\sortTable.png)
