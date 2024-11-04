# Notazione Standard
Identificano Classi di Funzioni :
 - O Omicro, O Grande
 - $\Omega$ Omega Grande
 - $\Theta$ Theta Grande

Limite Superiore e Inferiore : O e $\Omega$
Limite Stretto : $\Theta$

f(n) = O(g(n))
### Definizione O()
Ci intaressa che per n grandi, superiori uguali a n0 la funzione sia limitata superiormente, così da poterne definire la complessità
![alt text](img\O(g(n)).jpg)

Per f(n) = O(n<sup>2</sup>) è anche vero che f(n) = O(n<sup>3</sup>). 
Quindi ricercare il limite superiore più stretto possibile

### Definizione $\Omega$()
![alt text](img\Omega(g(n)).jpg)
Funzione di Limite Inferiore

### Definizione $\Theta$()
![alt text](img\Theta(g(n)).jpg)
Funzione limitata superiormente e inferiormente

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
    for(; i<n;i++){
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
## Dipendenza dagli Input


TODO : Lez. 10 -17min . Organizza primo Esame