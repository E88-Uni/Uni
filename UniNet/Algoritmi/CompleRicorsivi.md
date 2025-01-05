# Complessità Algoritmi Ricorsivi
# Ricorrenze
Complessità di un programma ricorsivo è descritta da una ricorrenza, ossia equazione che definisce una sequenza in modo ricorsivo 

Neccessità di risolvere le ricorrenze ottenendo una soluzione in **forma chiusa** cioè non ricorsiva.

Equivalenza matematica del trasformare un programma ricorsivo in iterativo.

**Esempio :** T(n) = T(n/2)+c -> T(n)?

# Serie e Sommatorie
## Serie
### Serie Aritmetica

$$
\sum_{k=1}^n k=1+2+..+n= \frac{n(n + 1)}{2}
$$

### Serie Geometrica

$$
\sum_{k=0}^n x^k=1+x+x^2+..+n^n= \frac{x^{n+1}-1}{x-1}  \space,\space \space \forall x>1
$$
$$
\sum_{k=0}^\infin x^k = \frac{1}{x-1}  \space,\space \space \forall x<1
$$

# Soluzione di Ricorrenze
## Metodo della Sostituzione
**Ipotizzare una Soluzione** e provarla con **induzione matematica**.

Strumento potente ma non sistematico, la sua efficacia dipende dall'ipotesi iniziale ma non c'è una regola per la scelta di essa.

## Metodo Iterativo
Si espande la ricorrenza fino al caso terminale T(1), con un **espressione che dipende solo da n**. 

E' come se puntassi a trasformare un programma Ricorsivo in Iterativo.

T(n) = c + T(n/2) = c + (c + T(n/4)) = c + (c + (c + T(n/8))) = ... 

T(n) = c + T(n/2) = c*i+T(n/2<sup>i</sup>)

n/2<sup>i</sup> = 1 -> i = log<sub>2</sub>n

T(n) = c * log<sub>2</sub>n + T(1) = O(log<sub>2</sub>n) = O(log n)

### Albero di Ricorsione
Utile per Ricorrenze **Assimetriche**, cioè più termini ricorsivi di dimensione diversa.

Ricorrenza = Termine Ricorsivo + Termine Non Ricorsivo

Esempio : T(n) = 2T(n/2) + n<sup>2</sup>

![alt text](img\AlberoRicorsivo.png)

T(n) = n<sup>2</sup> + n<sup>2</sup>/2 + n<sup>2</sup>/4 + n<sup>2</sup>/8+...+1

T nel Livello i = n<sup>2</sup>/2<sup>i</sup>

Numero Livelli = n/2<sup>i</sup> = 1 -> i = log<sub>2</sub>n

$$
\sum_{i=0}^{log_2n} \frac{n^2}{2^i}=n^2+\sum_{i=0}^{log_2n} \frac 1 {2^i} = \Theta (n^2)
$$

**Nota :** Porto fuori dalla sommatria n<sup>2</sup> perchè non dipende da i

Esempio Ricorrenza Assimetrcia : T(n) = T(n/3) + T(2n/3) + n 

## Metodo Master - Principale
Metodo Sistematico per Ricorrenze 

**T(n) = a*T(n/b)+f(n)**
1. T(n) = c <-> con  n <= d
2. a*T(n/b)+f(n) <-> con  n > d

- Dove **a>=1 e b>1** e sono costanti
- f(n) Funzione Asintoticamente Positiva : Sempre costo positivo per n grandi/crescenti

Risoluzione in **3 Casi** basati sul **Confronto** tra **f(n) e n<sup>log<sub>b</sub>a</sup>** :
1. **f(n) < n<sup>log<sub>b</sub>a</sup>**
2. **f(n) = n<sup>log<sub>b</sub>a</sup>**
3. **f(n) > n<sup>log<sub>b</sub>a</sup>**

### Caso 1 
**f(n) < n<sup>log<sub>b</sub>a</sup> -> f(n) = O(n<sup>log<sub>b</sub>a-$\epsilon$</sup>)**

**f(n) < n<sup>log<sub>b</sub>a</sup> -> T(n)=$\Theta$(n<sup>log<sub>b</sub>a</sup>)** 

### Caso 2
**f(n) = n<sup>log<sub>b</sub>a</sup> -> f(n) = $\Theta$(n<sup>log<sub>b</sub>a</sup>)**

**f(n) = n<sup>log<sub>b</sub>a</sup> -> T(n)=$\Theta$(f(n) * logn) = $\Theta$(n<sup>log<sub>b</sub>a</sup> * logn)** 

### Caso 3
**f(n) > n<sup>log<sub>b</sub>a</sup> -> f(n) = $\Omega$(n<sup>log<sub>b</sub>a-$\epsilon$</sup>)**

**f(n) > n<sup>log<sub>b</sub>a</sup> -> T(n)=$\Theta$(f(n))** 

Per qualche $\epsilon$>0 e se a * f(n/b)<=$\delta$ * f(n) per qualche $\delta$<1 

### Nota Master Theorem
Le Relazioni tra f(n) e n<sup>log<sub>b</sub>a</sup> devono valere polinomialmente

Come se ci fosse un confronto **sopra e sotto**

Quindi il Confronto tra **f(n)** e 
n<sup>log<sub>b</sub>a+$\epsilon$</sup> e n<sup>log<sub>b</sub>a-$\epsilon$</sup>

## Esempi
T(n) = a * T(n/b) + f(n) -> n<sup>log<sub>b</sub>a</sup> <-> f(n) , 

n<sup>x</sup> -> a = b<sup>x</sup>

### Caso 2
T(n) = T(n/2) + c :
- T(n) = aT(n/b)+f(n) -> a=1, b=2
- log<sub>b</sub>a -> log<sub>2</sub>1 = 0 
- n<sup>log<sub>b</sub>a</sup> = n<sup>0</sup> = 1
- f(n) = $\Theta$(1)=$\Theta$(log<sub>b</sub>a)
- T(n) = 1 * log<sub>2</sub>n = log<sub>2</sub>n

### Caso 1
T(n) = 9T(n/3) + n
- a = 9, b = 3, n<sup>log<sub>b</sub>a</sup> -> a = b<sup>x</sup> -> 9 = 3<sup>2</sup> -> n<sup>2</sup>
- f(n) = n
- f(n) < n<sup>log<sub>b</sub>a</sup> -> f(n) = O(n<sup>log<sub>b</sub>a-$\epsilon$</sup>) = O(n<sup>log<sub>b</sub>a-1</sup>) = O(n<sup>1</sup>) 
- T(n) = $\Theta$(n<sup>2</sup>)

### Caso 3
T(n) = 3T(n/4) + n<sup>2</sup>
- f(n) = n<sup>2</sup> > n<sup>log<sub>b</sub>a</sup> -> 1 > log<sub>4</sub>3 -> 2 > 1
- f(n) = $\Omega$(n<sup>log<sub>b</sub>a+$\epsilon$</sup>) < n<sup>2</sup>, con $\epsilon$=1
- T(n)=$\Theta$(n<sup>2</sup>)



TODO : Risolvi dopo lezine Esempio Ricorrenza Assimetrcia : T(n) = T(n/3) + T(2n/3) + n 
