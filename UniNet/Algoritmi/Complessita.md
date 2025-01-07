# Notazione Standard
Identificano Classi di Funzioni :
 - O Omicro, O Grande
 - $\Omega$ Omega Grande
 - $\Theta$ Theta Grande

Limite Superiore e Inferiore : O e $\Omega$
Limite Stretto : $\Theta$

f(n) = O(g(n))

**n** : numero elementi

Calcolo da 1 a n : (i=1, i<=n, i++);
### Definizione O()
Ci intaressa che per n grandi, superiori uguali a n0 la funzione sia limitata superiormente, così da poterne definire la complessità
![alt text](img\O(g(n)).jpg)

Per f(n) = O(n<sup>2</sup>) è anche vero che f(n) = O(n<sup>3</sup>). 
Quindi ricercare il limite superiore più stretto possibile

### Definizione $\Omega$()
Funzione di Limite Inferiore

![alt text](img\Omega(g(n)).jpg)


### Definizione $\Theta$()
Funzione limitata superiormente e inferiormente

![alt text](img\Theta(g(n)).jpg)


Se f(n) = $\Theta$(g(n)) allora :
 - f(n) = O(g(n))
 - f(n) = $\Omega$(g(n))

# Analisi Complessità
Se f(n) = $\Theta$(g(n)) -> a=b allora :
 - f(n) = O(g(n)) -> a<=b
 - f(n) = $\Omega$(g(n)) -> a>=b
## Proprieta Notazione Asintatica
### Transitivita
Vale per : O, $\Omega$ e $\Theta$
Es: 

Se f(n) = $\Theta$(g(n)) e g(n) = $\Theta$(h(n)) allora f(n) = $\Theta$(h(n))

Se f(n) = O(g(n)) e g(n) = O(h(n)) allora f(n) = O(h(n))
### Simmetria
 - f(n) = $\Theta$(g(n)) <-> g(n) = $\Theta$(f(n))
 - f(n) = O(g(n)) <-> g(n) = $\Omega$(f(n))
  
### Riflessivita
 - f(n)=$\Theta$(f(n))
 - f(n)=O(f(n))
 - f(n)=$\Omega$(f(n))

### Somma e Massimo
Se f(n) = f<sub>1</sub>(n)+...+f<sub>m</sub>(n) allora 

f(n)=$\Theta$(max(f(n)+...+f<sub>m</sub>(n))

Es. f(n) = 7n + 5nlogn + 3n<sup>2</sup> -> f(n)=$\Theta$(n<sup>2</sup>)

### Esempio
```c
void insertionSort(int A[], int dim){
    int i=1, j;
    for(; i<dim;i++){
        int temp = A[i];
        j = i-1;
        while(A[j]>temp && j>=0){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = temp;
    }
}
```
## Formula

T(n) = f + e*n + g * $\sum$ t<sub>j</sub> 

E' meglio **calcolare i casi** migliore, peggiore e medio **separatamente**.
## Dipendenza dagli Input

Insertion Sort : 
 - Caso Migliore con vettore già ordinato
 - Caso Peggiore con vettore ordinato in ordine inverso 

**Nota :** La sommatoria va da j-2 a n.
### Caso Migliore

t<sub>j</sub> = 1 , $\forall$<sub>j</sub> = $\sum$ t<sub>j</sub> = $\sum$<sub>j</sub> 1 = n - 1

T(n) = f + e*n + g * (n-1) = $\Theta$ (n) 

### Caso Peggiore

t<sub>j</sub> = j , $\forall$<sub>j</sub> = $\sum$ t<sub>j</sub> = $\sum$<sub>j</sub> j = $\frac{n(n + 1)}{2}$-1

T(n) = f + e*n + g * (n(n-1)/2-1) = $\Theta$ (n<sup>2</sup>) 

## Esempio Ricerca Binaria
Ricerca in un vettore già ordinato.
```c
int binarysearch(int *A, int iid, int eid, int key) {
	int mid = (eid-iid)/2 + iid;
	if(key == A[mid]) {
		return mid;
	} else if (iid >= eid) {
		return -1;
	}else if(A[mid] > key) {
		return binarysearch(A, iid, mid-1, key);
	}else{
		return binarysearch(A, mid+1, eid, key);
	}
}
```

T(n) = 1 + 1 + 1 + T(n/2) 

## Esempio Ricerca Lineare
```c
int search(int *A, int dim, int key) {
    int i = 0;
    for(; i<dim; i++) {
        if(A[i]==key) {
            return i;
        }
    }
    return -1;
}
```

- Caso Migliore : A[0] -> T(n) = O(1) : Complessità Costante
- Caso Peggiore : A[dim-1] Oppure Non Presente -> T(n) = O(n) : Complessità Lineare
- Caso Medio : Probabilità chiave in Posizione i = 1/n

**n :** numero elementi
### Caso Medio - Complessità Probabilistica
Probabilità chiave in Posizione i = 1/n

**n = dim**

T(n) = $\sum$ $\frac{1}{n}$ * i = $\frac{1}{n}$*$\frac{n*(n+1)}{2}$

T(n) = (n+1)/2 = O(n)
