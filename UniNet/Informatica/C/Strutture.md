# Tipi Aggregati
# Strutture
E' possibile definire in C dati composti da elementi eterogenei, aggregandoli in una singola variabile

Es. Vettori Matrci e Array Aggregati dello stesso tipo(omogenei)

I **campi** sono informazioni eterogenee che possono essere unite a uno stesso dato detto **dato aggregato**

```c
struct coppia{
    int a, b;
};

struct studente{
    char cognome[MAX]; 
    char nome[MAX]; 
    int matricola;
    float media;
};

struct complex{
    double reale;
    double immaginaria;
};
```
## Accesso
Operatore **.** per accedere alla struttura
```c
    struct studente c
    stu1.cognome = "Gasparini";
```
## typedef
```c
typedef struct studente{
    char cognome[MAX]; 
    char nome[MAX]; 
    int matricola;
    float media;
} Stude;
/*Equivalenti*/
typedef struct{
    char cognome[MAX]; 
    char nome[MAX]; 
    int matricola;
    float media;
} Stude;

Stude stu1, stu2;
```
## Vettori Struct
```c
struct stud {
    char nome[40];
    int matricola, voto;
};
stud vettore[10];

vettore[0].voto = 27;
```