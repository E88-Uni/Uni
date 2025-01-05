#include <stdio.h>
#include<malloc.h>

void printA(int *A, int i) {
	if(i){
		printA(A, --i);
		printf(" %d ", A[i]);
	}else{
		printf("\n");
	}
}

int getNext(int *A, int i) {
	if(A[i]){
		A[i]--;
		return i;
	}else{
		return getNext(A, ++i);
	}
}

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

void heapSort(int *A, int dimHeap);
void quickSort(int *A, int l, int r);
void insertionSort(int *A, int dim);
void mergeSort(int arr[], int l, int r);

int main(){

	int A[10] = {9,8,17,6,6,6,3,1,1,11}, B[10] = {9,8,17,6,6,6,3,1,1,11}, C[10] = {9,8,17,6,6,6,3,1,1,11}, D[10] = {9,8,17,6,6,6,3,1,1,11};
	int E[10] = {9,8,17,6,6,6,3,1,1,11};

	countingSort(A, 10);
	insertionSort(B, 10);
	heapSort(C,10);
	quickSort(D, 0, 9);
	mergeSort(E, 0, 9);

	printA(A, 10);printA(B, 10);printA(C, 10);printA(D, 10);printA(E, 10);

	return 0;
}



void swap(int *A, int x, int y){int Temp = A[x];A[x] = A[y];A[y] = Temp;}




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






void insertionSort(int *A, int dim){
	int k = 1;/*partiamo dal secondo elemento, il primo è già ordinato con se stesso*/
	for(; k<dim; k++){
		int key = A[k];
		int i = k - 1;
		while(i>=0 && key < A[i]){/*se elementi che lo precedono maggiori di key*/
			A[i+1] = A[i];
			i--;/* retrocedo portando avanti elementi */
		}
		A[i + 1] = key;
	}
}







int *copy(int *A, int x, int y){
	int dim = (y-x) + 1,  i = 0;
	int *V = (int *)malloc(sizeof(int)*dim);
	for (; i < dim; i++) 
        V[i] = A[x + i]; 
    return V;
}

/* Merges two subarrays of arr[]. 
 First subarray is arr[l..m] 
 Second subarray is arr[m+1..r]*/ 
void merge(int arr[], int l, int m, int r) 
{ 
    int i = 0, j = 0; 
    int dimL = m - l + 1; 
    int dimR =  r - m; 
  
    /* create temp arrays, Copy data to temp arrays L[] and R[]*/
    int *L = copy(arr, l, m);
    int *R = copy(arr, m+1, r);

    /* Merge the temp arrays back into arr[l..r]*/
    int k = l; /* Initial index of merged subarray */
    while (i < dimL && j < dimR) { 
    	arr[k++] = (L[i] <= R[j])? L[i++] : R[j++];
    } 
    
    /* Copy the remaining elements if there are any */
    while (i < dimL || j < dimR) { 
    	arr[k++] = (i < dimL)? L[i++] : R[j++];
    }
    free(L);free(R);
} 

/* l is for left index and r is right index of the sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) { 
    if (l < r) { 
        int m = (l+r)/2; 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
        merge(arr, l, m, r); 
    } 
} 