# Esempi I/O
Importanza di riutilizzare le variabili per l'efficenza
```c
    int a = 3, b, c;
    b = a*a; c=b*a; >> b = a*a; c=a*a*a;
``` 
# If - Then - Else
```c
    if(condizione booleana){//0 False n True
        istruzioni1;
    }else{
        istruzioni2;
    }
``` 

```c
    if(condizione booleana){//0 False n True
        istruzioni1;
    }else if(condizione booleana){
        istruzioni2;
    }else{
        istruzioni3;
    }
``` 
``` c
    //n divisibile per 3 e 8
    int n;
    printf("Inserisco n:");
    scanf("%d",&n);
    if((n%3)==0 && (n%8)==0){
         printf("%d div per 3 e 8",n);
    }else{
        printf("Non div per 3 e 8");
    }
``` 
Problema triangolo date lunghezze a,b,c. Soluzione: è un triangolo se la somma di due lati e minore della lunghezza del 3 lato.
```c
    int a, b, c;
    printf("Inserisci i Lati");
    scanf("%d %d %d", &a, &b, &c);
    if((a+b)>c && (a+c)>b && (b+c)>a){
        printf("Triangolo valido");
    }else{
        printf("Non è un Triangolo");
    }
```
# Switch
```c
    switch (espressione){

    case <cost 1>:
        <blocco1>;
        break;
    case <cost 2>:
        <blocco2>;
        break;
    default:
        <blocco_default>;
        break;
    }
```

```c
    int n;
    scanf("%d", &n);
    switch (n){
    case 1: n++;
        printf("Case 1");
        break;//input 1 case 1
    case 2: n++;
        printf("Case 2");
        break;
    default:
        printf("Def");
        break;
    }
```
Importanze dei **break**
```c
    int n;
    scanf("%d", &n);
    switch (n){
    case 1: n++;
        printf("Case 1");
    case 2: n++;
        printf("Case 2");
        break;//input 1 case 1 e 2
    default:
        printf("Def");
        break;
    }
```
# While
```c
    int i = 0, n;
    float media, ssum=0, ni;
    printf("Inserisci numero cicli: ");
    scanf("%d", &n);
    if(n<1){
        printf("Numero cicli non valido");
        return;
    }
    while(i < n){
        printf("\nNumero[%d]:", i);
        scanf("%f", &ni);
        ssum += ni;
        i++;
    }
    media = ssum / n;
    printf("\nMedia: %f", media);
```
# Do - While
Il primo blocco è sempre eseguito e poi si verifica la condizione
```c
    float sum=0, max = 500, n;
    do{
        printf("Inserisci n:");
        scanf("%f", &n);
        sum += n;
    }while(n && sum<=max);
    printf("\nSomma: %f", sum);
```
![alt text](img\dowhile.JPG)

**Tipo Stampa**
```c
    int y, z;
    float a, sum;
    sum = y/z; //Intero
    sum = y/a; //float
    sum = a/z; //float
    sum = (float)y/z;//float
```
