TODO: Lezione 30
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
        for(j = 0; j < dim - i + 1; j++){
            if(A[j]>A[j+1]){
                swap(A+j, A+j+1);
            }
        }
    }
}
```
# Inserimento
