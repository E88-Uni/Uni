# Obbiettivi
1. Capire quali sono le strutture dati migliori in ogni casistica con le loro relative prestazioni
2. Applicare Algoritmi generali a problemi pratici
3. Programmazzione Avanzata in C
4. Paradigmi Algoritmici, riutilizzo e adattamento di strutture e processi
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

## * &

**'*' Operatore di Indirezione** : Opera su una variabile indirizzo e Ritorna il valore contenuto in quell'indirizzo

**'&' Operatore di Indirizzo** : Opera su una variabile e Ritorna l'indirizzo di una variabile

## Stampare  un Puntatore
```c
printf("Indirizzo x %p\n", px);
```

## Operazioni per Puntatori

Cosa si può
```c
 p++, p+2;
 p--, p-=4;
 px-py; //se puntano allo stesso tipo
 px = py; //Assegnazione
 px==py;  //Confronto

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

Accedere ad Elemento di un vettore:
- Accesso tramite indirizzo a[2]
- Accesso tramite puntatore detto scostamento o offset *(a+2)
```c
    int a[8], *aptr;
    aptr = a;
    printf("%d==%d\n", *(aptr+2), a[2]);

```

Il puntatore inizializzato per un array è fisso, non si deve sovrascrivere o modificare (a[10] -> *(a+5) SI; a=a+5 NO)

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