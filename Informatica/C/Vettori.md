# Vettori e Puntatori
Serie ordinata e contigua(dello stesso tipo o di sottotipo) di un tipo o una struttura. Scritto tramite array o vettore di quel tipo,cioè un puntatore che ha instanziate un numero definite di celle. L'accesso può essere fatto tramite indice/vettore o tramite puntatore : A[i]  o *(A+i)

Il Vettore contiene una o più variabile scalare(costituita da un solo elemento/informazione)

Vettore **Insieme di variabili** dello stesso tipo, inserite in un unica entità e identificate globalmente da un nome. Ricerca della singola variabile con **indice** da 0 a n-1, essa è la posizione;

Tipo_di_Base NomeVettore [NumElementi];

```c
    int VETT[100];
```
Differenza
```c
    M[i] = M[i]+1;
    M[i] = M[i+1];
```
### Dichiarazione con **Inizializzazione**
```c
    int M[4] = {2, 0, -1, 5};
```
### Vett pari disp
```c
    int i, v[N], pari = 0, dispari = 0;
    for(i=0; i<N; i++){
        printf("Inserisci elemento %d : ", i);
        scanf("%d", &v[i]);
        ((v[i] % 2) == 0)? pari++ : dispari++;
    }
    printf("Pari : %d Dispari : %d", pari, dispari);
    scanf("%d", &i);
```

### Coppie
Quante coppie con vaore : V[i]+V[i+1] ci sono?
```c
    int i=1, max; 
    int V[N] = {1,2,3,1,2,3,1,2,3,0};
    int M[N];
    int *List;
    for(;i<N; i++){
        M[(i-1)]= V[(i-1)]+V[i];
    }
    max = M[0];
    for(i=1; i<(N-1); i++){
        if(max<M[i]){
            max = M[i];
        }
    }
    List = (int*)malloc(max*sizeof(int));
    for(i=0; i<=max; i++){
        List[i]=0;
    }
    for(i=0; i<(N-1); i++){
        List[M[i]]++;
    }
    for(i=0; i<=max; i++){
        if(List[i]!=0){
            printf("\n Ci sono %d coppie con valore %d", List[i], i);
        }    
    }
    free(List);
```