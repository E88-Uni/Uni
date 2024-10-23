TODO: Lezione Esercizio 30
Lezione 31 dopo es. copia in V3 da V1 e V2 e ordina in Descresente con bubble_sort 
# Ordinamento
## Bubble Sort
1. Inizializzo i==0,j==0
2. Ciclo con i per dim-1
3. Ciclo all'interno per il sottoarrey con j < dim-i+1
4. Se A[j]>A[j+1] : swap((A+j), (A+j+1))

Testa se giusto
```c
void bubble_sort(int A[], int dim){
    int i,j;
    for(i = 0; i<dim-1; i++){
        for(j = 0; j < dim - i - 1; j++){
            if(A[j]>A[j+1]){
                swap(A+j, A+j+1);
            }
        }
    }
}
```
# Inserimento
PER INSERIRE :
1. Va creato un nuovo array più grande
2. Copiato cella per cella da vecchio a nuovo array
3. Ordinarlo?

# Copia Vettori
 1. Passare il vettore con già dichiarato lo spasso
 2. Se non passi vettore, malloc, e NON int A[30]
 3. Se dichiari un array in una sottofunzione es.A[30]
    1. Alla chiusura della funzioone l'array viene deallocato
    2. Devi fare malloc e free 
```c
int *merge(int A[], int dimA, int B[], int dimB){
    int i, dimC = dimA+dimB;
    //int C[dimC]; Perchè Array locale viene svuotato alla chiusura della funzione
    int *C;
    C = (int *)malloc(sizeof(int)*dimC);
    for(i=0; i<dimA; i++){
        C[i] = A[i];
    }
    for(i=0; i<dimB; i++){
        C[(i+dimA)] = B[i];
    }
    return C;
}
```