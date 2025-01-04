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

Lez. 11 -16min

TODO : Risolvi dopo lezine Esempio Ricorrenza Assimetrcia : T(n) = T(n/3) + T(2n/3) + n 
