# Assenazioni e Espressioni
## Assegnazioni
<variabile\> = <valore\><**;**\>
```c
    int x;
    float y;
    x = 3;
    y = -323.9498;
```
<variabile\> = <espressioni\><**;**\>
```c
    #define N 10
    ...
    j = N - i;
    b = a*2 - 1;
```
**=** : 
Assegna alla variabile a sx il contenuto della variabile a dx

Es. a=b <> b=a

A **Sx** sempre e soltato una variabile :
 - a + 1 = a NO
 - a += 2 SI
 - a = a + 2 SI
 - - a++; a--; SI Eccezione

**swap**
```c
    void swap(int *a, int *b){
        int Temp = *a;
        *a = *b;
        *b = Temp;
    }
    swap(&a, &b);
```
```c
srand(time(NULL))
int int_rnd(int nMin, int nMax){
    int nRandonNumber = rand()%((nMax+1)-nMin) + nMin;
    return nRandonNumber;
}
```
## Espressioni Aritmetiche
 1. Operatori : +, -, *, /, %.
 2. Parentesi : ((a+b)/(a-b))
 3. Funzioni di Libreria
    1. stdio.h : printf(), scanf() 
    2. stdlib.h : malloc(), free()
    3. math.h : sqrt(), sin(), cos()
    4. string.h : strcmp(s1,s2)==0 , strcpy(s, list(i));
    5. time.h : srand(time(NULL));

Il TIPO del Risultato è il tipo delle varibili usate. Es: float c = 7/3 = 2 :
 - Quoziente 2
 - Resto 1 (7-Quoziente*3)
 - q=a/b, r=a-q*b
 - a%b = r
```c
    int a = 3, b = 7;
    float c = b/a; //2
    float d = 7.0/3.0; //2.33
    d = 7/3.0; //2.33
    d = 7.0/3; //2.33
    d = 7/3; //2
``` 
## Espressioni Relazionali e Logiche
Ritornano un booleano(0,1) o (0:Falso, Num!=0:Vero) e
Operano su quantità (numeri o char(numeri codifcati ASCII)):

< , <= , > , >= , == , !=

- ! : NOT
- && : AND
- || : OR
# Istruzioni
## Istruzioni di Stampa
 - printf("Fattore di Stampa Costante)
 - % Fattore di conversione
   - %d
   - %f 
   - %c
   - %s 'Ciao'
 - Caratteri di controllo:
   - \n a capo
   - \\ : \
```c
    int a = 3;
    char c = 'a';
    printf("Ciao");
    printf("a :%d . %f . %c\n", a, a/6.0, c);
``` 
Ad ogni fattore di conversione corrisponde una variabile, rapporto 1 a 1.
## Istruzioni di Input
Introdurre da Tastiera dei dati
```c
    int a = 3;
    float b;
    printf("Inserisci a e b:");
    scanf("%d",&a);
    scanf("%f",&b);

    scanf("%d %f",&a, &b);
``` 