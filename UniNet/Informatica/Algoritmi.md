# Obbiettivi
1. Capire quali sono le strutture dati migliori in ogni casistica con le loro relative prestazioni
2. Applicare Algoritmi generali a problemi pratici
3. Programmazzione Avanzata in C (Lez. 1-8)
4. Paradigmi Algoritmici, riutilizzo e adattamento di strutture e processi, Problemi Classici (Lez. 9-27)
5. Puntatori e vettori(stringhe) e strutture (Tipi Aggregati)

# CodeBlocks
- Multipiattaforma
- Gratuito
- Interfaccia Grafica
- Supporto per il debug
- Supporto per Progetti
- Supporto C e C++
  
# Puntatori
E' una variabile che contiene un indirizzo di memoria, inoltre è un tipo. Specificati con il '*'.

Ricorda che l'indirizzo di un **tipo** si contiene in un puntatore a quel **tipo** Es. float a -> float *pa = &a;

Perchè l'occupazione di memoria è diversa a seconda del tipo, quindi è diverso il tipo del puntatore.

```c

    <tipo> '*' <identificatore>;
    int x; int *px;
    double v; double *pv;

```

Ogni tipo di variabile ha il suo puntatore perchè l'indirizzo puntato è diverso (in lunghezza o/e struttura)

# Indirizzi
Specificati con '&'


```c

    '&' <variabile>;
    int x, *px;
    px = &x; //x == *px
    // Accesso Diretto x . Accesso Indiretto *px
```

## Accesso variabile
Con int x, *px; px = &x;
 - Accesso Diretto x  per variabile
 - Accesso Indiretto *px per puntatore con Operatore di Indirezione

## * &

**'*' Operatore di Indirezione** : Opera su una variabile indirizzo e Ritorna il valore contenuto in quell'indirizzo

**'&' Operatore di Indirizzo** : Opera su una variabile e Ritorna l'indirizzo di una variabile

**%p** per stampa puntatore, inoltre in esadecimale. Con %d inidirizzo in decimale.

```c
int x = 5, *px;
px = &x;
printf("%d == %d", x, *px);
printf("\nIndirizzo x %p == %p", &x, px);
```

-17 lez.1

## Stampare  un Puntatore
```c
printf("Indirizzo x %p\n", px);
```

## Operazioni per Puntatori

Cosa si può
```c
 p++, p+2; ///Incremento
 p--, p-=4; //Decremento
 px-py; //Sottrazione se puntano allo stesso tipo
 px = py; //Assegnazione
 px==py;  //Confronto

 px+py; //Somma non valida
 px-ppy; //Sottrazione non valida se non puntano allo stesso tipo
 p = 3; //Assegnazzione non valida.
 p = NULL; //Unico tipo di assegnazione a costante valida
```

```c
    int a, b;
    int px, py;
    px = &a;
    py = &b;
    printf("Indirizzo diff pointer %d  == %d\n", (px-py), (&a-&b));//1
```
No somma tra puntatori perchè possibile out of range

Cosa **non** si può
```c
 p=3; //Non si può assegnare a costante
 px + py; //Rischioso
 px - ppy; //Non si può sottrarre puntatori di tipo diverso
```

# Aritmetica dei Puntatori
Vanno fate in base alla dimensione **sizeof()** quindi misurata in byte, dimensione del tipo e delle strutture

A Tipi più grandi corrispondono indirizzi più distanziati
Es. int *px : 1000; px+3: 1012; px

```c
    int *px : 1000, py : 1008; 
    px+3: 1012; //con int che occupa 4 Byte
    py-px : 2; 1000 - 1008 (2*sizeof(int)) = 8
```

Accedere ad Elemento di un vettore:
- Accesso tramite indirizzo a[2]
- Accesso tramite puntatore detto scostamento o offset *(a+2)
```c
    int a[8], *aptr;
    aptr = a;
    printf("%d==%d\n", *(aptr+2), a[2]);

```

Il puntatore inizializzato per un array è fisso, non si deve sovrascrivere o modificare (a[10] -> *(a+5) SI; a=a+5 NO)

## Stringhe
```c
    char v[] = "abcd"; //la stringa parte da v
    char *p = "abcd";  //p punta a un indiirzzo da cui parte la stringa
    //Entrambe concludono con '\0'
    //Usare i puntatori per gestione stringhe es:
    char *strchr(char *s, int c);//Ritorna la prima occorrenza di c in s
```

## Struct
Per accedere tramite un puntatore a struct si usa **'->'** se è la struct **'.'**
```c
    struct complex {
        double re, im;
    } c, *pc;
    c.re = 1.0;
    c.im = 2.0;
    pc = &c;
    printf("%f %f\n", pc->re, pc->im);
```