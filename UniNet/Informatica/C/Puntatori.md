# Puntatori
Passaggio **by reference** 
Valore : Indirizzo cella di memoria

In un Array non serve l'* perchè **il nome del vettore è il suo indirizzo di memmoria**

Operatori : 
 1. & Operatore di Indirizzo -> &pippo
 2. ** Operatore di Deferimento o Operatore di Indirizzamento Indiretto  
 -> *pointer


**Usato anche per ritornare più elementi**
```c
    int n_2(int n, int *cubo){
        *cubo = n*n*n;
        return n*n;
    }
```
## Dichirazione Puntatore
```c
    <tipo> *<nome>;;
    int *p;
    float *py;
    int a;
    p = &a;
    *p = 3; //a = 3
```

```c
    void swap(int *a, int *b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    int a, b;
    swap(&a, &b);
```
### Varianza
Calcola media e varianza
1. Media 
2. Somma+=(xi-media)^2
3. Varianza = Somma/dim
```c
float varianza(int A[], int dim, float *media){
    float m = 0.0, sum = 0.0; 
    int i=0;
    for(; i<dim; i++){
        m += A[i];
    }
    m = m/dim;
    *media = m;
    for(i=0; i<dim; i++){
        sum += ((A[i]-m)*(A[i]-m));
    }
    return sum/dim;
}
```
# Matrici
Vettori multidimensionali
Per **Ogni Dimensione** ci vuole un indice Es.(i,j,z)
## Matrici Bidimensionali
Spesso Struttura Bidimensionale A[Righe][Colonne] = A[M][N] = A[y][x]
 - Colonne 0-> M-1
 - Righe 0-> N-1
```c
    int Matrix[nRighe][nColonne];
    //Dichirazione Elementi
    int M1[3][2] = {{1,2}, {3,4}, {5,6}};
    int M2[2][3] = {{1,2,3}, {4,5,6}};
    int M3[4][5][6];//Matrice Tridimensionale
```
**Inizializzazione Matrici**
```c
    int M[M][N];
    int y = 0; x;
    for(; y<M; y++){
        for(x=0; x<N; x++){
            M[y][x] = 0;
        }   
    } 
```
### Passaggio Matrici
```c
void print(int Matrix[M][N]){
    ...
}
void print(int **Matrix, int M, int N){
    ...
}
```
### Sum [2][2]==0
```c
void prin_sum(int Mat[M][N]){
    int i = 0, j, ci = 0, cj = 0, ci_max=0, cj_max=0;
    for(; i<M-1; i++){
        for(j=0; j<N-1; j++){
            int sum = Mat[i][j]+Mat[i+1][j]+Mat[i][j+1]+Mat[i+1][j+1];
            if(sum == 0){
                printf("\nIndici (%d, %d)", i, j);
                printf("\n %d %d \n %d %d\n", Mat[i][j],Mat[i][j+1],Mat[i+1][j],Mat[i+1][j+1]);
            }
        }
    }
}
```
## Random Float
```c
float random_float(float min, float max) {
    float scale = rand() / (float) RAND_MAX; // Generate a random float between 0 and 1
    return min + scale * (max - min); // Scale it to the desired range
}
```
