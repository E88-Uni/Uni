# Analisi Algoritmi
**Algoritmo :** Procedimento che consente di ottenere un risultato atteso, eseguendo, in un determinato ordine, un insieme finito di passi semplici, corrispondenti ad azioni scelte, da un insieme finito.

**Programmi = Algoritmi + Strutture Dati**

Definizione valida anche per un **Programma :** contiene un algoritmo come sequenza finita di istruzioni che :
 - Risolvono un dato problema
   - Opera su dei Dati
   - Ricevente/Basato in valori in ingresso
   - Genera dei valori in uscita
   - Termina dopo un numero di passi finito
 - Perchè gli Algoritmi sono Importanti
   - Motivi Pratici per Risoluzione problemi in maniera efficente ed efficace 
   - Motivi Tecnologici gli algoritmi possono essere implementati come programmi
## Esempi Algoritmi
 - Ordinare un Insieme di Oggetti
 - Trovare un elemento in un Insieme di Oggetti
 - Trovare il Percorso più Breve tra due destinazioni (Problemi di Ottimizzazione)
## Concetto di Algoritmo
**Programmi = Algoritmi + Strutture Dati**
La Scelta della Struttura Dati può influire sull'efficenza. Es. tempo di accesso
# Aspetti Legati agli Algoritmi
1. Progetto
2. Calcolo Efficenza
## Progetto di Algoritmi
Progetto : Orientare il Progetto sulla struttura del Problema da Risolvere

Classificazione Algoritmi in base al **paradigma metodologico :**
 1. **Paradigmi Generali :** 
    1. **Divide and Conquer :** Il problema viene suddiviso in Istanze progressivamente minori le quali vengono risolte ricorsivamente Es. Fattoriale
    2. **Ricerca ed enumerazione :** soluzione ottenuta tramite un ricerca all'interno di uno spazio delle soluzioni Es. Libreria di Password
 2. **Paradigmi** per Problemi di **Ottimizazzione :**
    1. **Programmazione Dinamica :** Soluzione ottimale è ottenuta dalla combinazione di soluzioni ottimali ai vari sottoproblemi . Problemi con sottoproblemi uguali o simili, così è possibile riutilizzare le soluzioni dei vari sottoproblemi.
    2. **Paradigma greedy :** Soluzione Ottima è ottenuta concatenando le soluzioni ottime ai sottoproblemi con Decisione Locale

## Analisi di Algoritmi
Prevedere le **Risorse** Richieste da un Algoritmo :
 1. **Tempo di Esecuzione :** 
 2. **Quantità di Memoria :**
 3. **Altre Risorse :** Spazio Disco, Numero Porte Comunicazione, Risorse Software

Parametri che **Influenzano** l'Analisi :
  1. Dimensioni dell'Input
  2. Tipo valori di Input
  3. Altro : Es. Modello di Esecuzione es. cpu 1core vs 8core
# Analisi Complessita
**Analisi Asintotica** Analisi semi-formale di complessità. Basata su **n** come dimensione input :
 1. Time Tempo di Esecuzione T(n) 
 2. Memoria Storage S(n)
**Requisiti** Analisi
 - Indipendente dal tipo di elaboratore
 - Complessità Asintotica : Ci intaressa efficenza basata su n -> infinito

La complessità di un algoritmo rispetto a una CPU 1000 volte più potente

![alt text](img\CPU1000.jpg)
# Notazione Standard
Identificano Classi di Funzioni :
 - O Omicro, O Grande
 - $\Omega$ Omega Grande
 - $\Theta$ Theta Grande

Limite Superiore e Inferiore : O e $\Omega$
Limite Stretto : $\Theta$

f(n) = O(g(n))
### Definizione O()
Ci intaressa che per n grandi, superiori uguali a n0 la funzione sia limitata superiormente, così da poterne definire la complessità
![alt text](img\O(g(n)).jpg)

Per f(n) = O(n<sup>2</sup>) è anche vero che f(n) = O(n<sup>3</sup>). 
Quindi ricercare il limite superiore più stretto possibile

### Definizione $\Omega$()
![alt text](img\Omega(g(n)).jpg)
Funzione di Limite Inferiore

### Definizione $\Theta$()
![alt text](img\Theta(g(n)).jpg)
Funzione limitata superiormente e inferiormente

Se f(n) = $\Theta$(g(n)) allora :
 - f(n) = O(g(n))
 - f(n) = $\Omega$(g(n))
