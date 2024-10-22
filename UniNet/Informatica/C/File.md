# File
Sono copmposti da **Settori** : sequenza ordinata di informazioni dello stesso tipo.
 - Organizzazione HW : Settori es. di 512Byte
 - Record SW : Insieme ordinato dei campi correlati (Settori ma SW)
    - Ogni record termina con EOF(End Of File) : carattere di fine file es.'/0'

In C c'è la gestione di **file sequenziali** con l'accesso sequenziale (stream).
Il C vede i file come un flusso detto **stream** sequenziale di byte con un byte finale di terminazione EOF.
## Accesso Sequenziale
Permette la lettura solo in avanti es. primo accesso al 10°Byte -> Futuri accessi sono dal 10°Byte in poi es.15°Byte
 - Non si può leggere indietro, si può però reiniziare la lettura dall'inizio d'accesso
 - Non si può saltare da un Byte all'altro, nello stream va fatta la lettura da Byte a Byte+1

Si usa il **file stream** per gestire informazioni legate ad un file aperto, è una sorta di puntatore. Perchè Punta al File

FILE *< nome > è supportato con #include <stdio.h>

## Funzioni File
 1. Apertura del File, crea stream con puntatore d'accesso
 2. Accesso al File
 3. Chiusura del File
 - fopen : aprire un file (1)
 - fclose : chiudere un file (3)
 - fgec e fgets : leggere dal file un carattere o una stringa (2) quando non conosco la struttura es. stringa alfanumerica
 - fputc e fputs : inserire nel file un carattere o una stringa (2) quando non conosco la struttura
 - fprintf e fscanf (2) quando conosco la struttura es. intero, float ecc.

## Gestione File
 1. FILE* fopen(char* < nome_file>, char* < modo >)
 Il modo : "r"/"w"/"a" : read/write/append
 ```c
    #include <stdio.h>
    FILE * f;
    f = fopen("nome_file.txt", "r");
    //modo : Scrittura(Creazione)/Lettura
    f = fopen("C:\\Desktop\\nome_file.txt", "w");
 ```
 Se "w" il file viene cancellato e riscritto -> sovrascritto
 Con modo : "a" puoi scrivere in **append** al file 
 
 2. int fclose(FILE* < file>)
  ```c
    int chiusura = fcolse(f);//chiusura = 0 corretta
    if(chiusura!=0){
        printf("Chiusura Errata");
    }
    //chiusura = EOF in caso di errore 
    //Puntatore f può essere usato ora per altro
  ```

## Check fopen
 ```c
    #include <stdio.h>
    FILE *f;
    f = fopen("pippo.txt", "r");
    if(f == NULL){
        printf("Impossibile Aprire il File\n");
        return 1;//exit(1);
    }
 ```
 ## Lettura
  ```c
    char str[80];
    FILE *f;
    f = fopen("pippo.txt", "r");
    if(f == NULL){
        printf("Impossibile Aprire il File\n");
        return 1;//exit(1);
    }else{
        //str : dove vettere la lettura
        // 79 : quantità massima leggibile
        // f : puntatore file
        fgets(str, 79, f);
    }
 ```
### Lettura Righe
 ```c
    char str[81];
    while(fgets(str, 80, f) != NULL){
        ...str...
    }
 ```
### Lettura fscanf
```c
    int x, z;
    float fy;
    fscanf(f, "%d %f %d", &x, &fy, &z)
    //Lettura fino a fine file
    while( fscanf(f, "%d %d", &x, &z)!=EOF){
        /*...x...z...*/
    }
```
## Scrittura
Scrive la stringa senza EOF '\n'
```c
    char str[80]="Pippo";
    int fputs(str, f);
```
### Scrittura fprintf
```c
    FILE *f;
    fprintf(f, "%d %f", 5, 6.3);
```
### EOF : EdnOfFile
```c
    int isEOF = 0;
    if(feof(f) != 0){
        printf("Fine File");
    }
```
# Esercizio
```c
#include <stdio.h>

int main(){
    FILE *f;
    FILE *fw;
    int x, y;
    f = fopen("estremi.dat", "r");
    fw = fopen("diff.dat", "w");
    if(f==NULL || fw==NULL){
        printf("Problemi di Apertura file");
    }
    while(feof(f) == 0){
        fscanf(f,"%d %d", &x, &y);
        fprintf(fw," %d ", x-y);
    }
    if(fclose(f)!=0){
        printf("Problemi di Chiusura file letto");
    }
    if(fclose(fw)!=0){
        printf("Problemi di Chiusura file scritto");
    }
    return 0;
}
```