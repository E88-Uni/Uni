# Informatica
E' la Scienza che Rappresenta e Manipola le Informazioni

Il Corso Tratta di Problematiche culturali e tecnologiche legate all'ITC (Information and Communication Technology)

# Energia & Informazioni
Movimento & Elementi Fondamentali (che Determinano e Caratterizzano) 

## Tecnologia
Come Fattore Abilitante dei Cambiamenti Industriali e Sociali
### Rivoluzioni Industriali
Passare il lavoro alle Macchine
1. 1800 Motore a Vapore : Trasporti Treno
2. 1900 Elettricità, Motore a Scoppio, Chimica(Nuovi Materiali)
3. 2000 Informatica e Telecomunicazioni

### Pervasività 
L'Informatica ha elementi in moltissimi Campi

### Rappresentazione Binaria Bit
Qualunque tipo di Informazione può essere codificata, salvata, elaborata ec.. in bit al dilà della sua natura
- Garanzia di Qualità
    - Qualità inalerata nel tempo cioè l'informazione si mantiene
    - Dati Comprimibili cioè la possibilità di rappresentare la stessa informazione con meno dati e gestirla con più efficenza
- Efficenza
    - Dati Comprimibili
    - Trasmissione dei Dati, anche con un singolo tipo di rete (es. elettricità, tv, internet)
    - Con un unico Dispositivo fruire di più canali di comunicazione (TV, Radio,...)
- Tecnologia Digitale > Tecnologia Analogica
- Bit : Binary Digit
- Byte : 8 bit es. Lettera 'a'
- **B** = **b**^8
- Word : 2 byte es.Interi , Double Word : 4 byte es. Numeri Reali(con ',')

# 3 Momenti Informatica
1. Elaborazione
2. Memorizzazione
3. Trasporto

## 1. Elaborazione
- MIPS : Milioni di Istruzioni al Secondo
- MFLOPS : Milioni di Istruzioni Aritmetiche sui Numeri Reali al Secondo

## 2. Memorizzare
In byte = B
- RAM, Dischi Rigidi, CD (Dischi Ottici)
- Chilo k = 2^10 (1024), Mega M = 2^20 (1 000 000), Giga G = 20^30(Miliardo)
- Peta P = 20^50(un milione di miliardi), Exa E = 20^60 (miliardo di migliardi)
- 640 kB = 640 * 1024 = 655.360 byte . 1 GB = 1024 * 1024 = 1.073.741.824 byte
- Pagina di Testo [2kB], Libro [1MB], Film[1GB]

## 3. Trasmissione
Si misura in **bps bit al secondo** es. K bps = 1000 bps

### Rivoluzioni
1. 1980 Personal Computer (Non sei più te che vai dalla macchina ma lei che viaggia con te)
2. 1990 Low Cost Local Storage
3. 2000 Internet, Multimedia Network
4. 2005 Web 2.0 : Google, YouTube, Facebook. Condivisione Esperienze Personali
   
# Architettura degli Elaboratori
## Costituzione
1. Unità Ingresso es. Tastiera, Scanner
2. Unità Elaborazione
3. Memoria
   1. RAM : Memoria Centrale e Volatile
   2. Dischi : Memoria di Massa, Capiente e Permanente
4. Unità Uscita es. Monitor, Stampante
   
Ingresso -> (Memoria & Elaborazione) -> Uscita

## Hardware Centri di Calcolo
Elaboratori Completi conessi a terminali e router tramite una rete LAN(Locale)

Router conessione a Internet (Rete Geografica)
# Classi degli Elaboratori
## Classi di Mercato
- Desktop - Portatili
- Server
- Mainframe (Server Potenti)
- Supercomputer
- Embedded System (Integrati. dai Router ai Telefonini)
## Tipi 
- Elaboratori di Uso Generale (General Purpose Computer) cioè si possono scegliere e lanciare programmi vari es. Browser, Scrittura, Calcoli excel, Disegni ...
- Elaboratori Dedicati (Special Purpose Compute chiamati Embedded) hanno solo un programma scelto all'origine in produzione/progetto e non può essere alterato, esso svolge funzioni specifiche es. Lettori MP
    
    - Requisito 1 : Prestazioni in tempo reale
    - Req. 2 : Riduzione al Minimo della Memoria
    - Req. 3 : Minimizzare Consumo di Energia
    - Req. 4 : Vincoli di Affidabilità
## Razze Elaboratori
- Personal/Client
- Workstation
- Server Mainframe/Host
- Supercomputer
   
**Server** : Elaboratore che fornisce **Servizi** ad altri Elaboratori detti **Client** attraverso una Rete detta **Computer Network** es. Utilizzo di Google

**Server Farm** : **Insieme** di elaboratori Server collocati in un apposito **Locale** detto **Centro di Calcolo** da una 'grande' azienda

**Mainframe**: detti **Big Iron** elaboratori con grandi **prestazioni** usati come hardware da una grande azienda

**SuperComputer** : esempio con Potenza di 16 Peta Flops
(20^50(16 milionI di miliardi di moltiplicazioni/elaborazioni al s econdo) = 16000 TFLOPS)

# Componenti Computer
- Compinenti Interne
  - CPU : Microprocessore 
  - RAM : Memoria Centrale
- Componenti Esterne 
  - Memorie di Massa
  - Periferiche di Input
  - Stampanti
  - Unità Video
  - Unità per le Comunicazioni, per collegare Elab. alle Reti Es, Modem

**BUS** : Trasporta l'informazione in bit, caratterizzato da **Frequenza** cioè n° dati al secondo e **Ampiezza** n° di bit del dato. Connette il Processore con Memoria(RAM) e I/O

**Memoria Esterna** non è collegata come la RAM direttamente alla CPU dal BUS ma viene vista come Periferica I/O 

# Storico IBM - Intel
1. 1980 : 8086 un milione di somme al secondo, 30 mila transistor
2. 2000 : Pentium IV un miliardo di somme al secondo, 50 milioni transistor
3. 2010 : i7 10 miliardi di somme al secondo, 731 milioni transistor

Altri tipi di processori :
- DSP : Elaboratori Vocali (Digital Signal Processing) es.MP3
- Microprocessori/Schede Grafiche (Intel, Nvidia)
- Qualcomm e Apple : High Performance Embedded chip es. per Telefonini o Apple per Tablet
- Motorola : Low Performance chip es. Frullatore
  
Si vedono miliardi di processori all'Anno

# CPU - Central Process Unit
Composta da 4 unità + ALU e Registro
- Unità di Decodifica Istruzioni
- Unità di Gestione Indirizzi
- Unità di Gestione BUS
- Unità di Controllo
- ALU (Pollottoliere)
- Registro

Unità di Controllo <-> Registri - Memoria Locale <-> ALU - Unità Aritmetica

**ALU** Arithmetic-Logic Unit : Svolge tutti i Calcoli Aritmetici e Logici è spesso composta di Circuiti Combinatori
## Ciclo Base di un Elaboratore
1. Preleva una Istruzione dalla Memoria Locale
2. Interpreta l'Istruzione
3. Esegue l'Istruzione e Ritorno a **1**

Istruzione i-esima (Ciclo FDE) :

1. Fetch
2. Decodifica
3. Esecuzione

**Clock** Riferimento Temporale comune per tutti gli Elementi Costituenti il Sistema di Elab. **T** = periodo di Clock in 's', **f** = 1/T frequenza di Clock in 'Hz = Cicli|Frequenza al secondo'

es. i7-2700 Clock di 3.5 Ghz cioè 3.5 miliardi al secondo

# Struttura Fisica Elaboratore
- Piastra Madre Elettronica Motherboard con BUS che conettono le componenti
  - RAM
  - CPU
  - Scheda di Rete LAN
  - Scheda Video
  - Scheda Audio

**Chip** (Briciola) Circuito Integrato contenete transistor e conettori, mattone elementare di un lavoratore

es. i7 Transistor incisi in 20 nm(nano metri) e diametro atomo 0.5 nm (miliardesimi di metro, milionesimi di millimetro). Globulo rosso 2000nm x 7000nm
# Memoria
Caratteristiche : 
- Indirizzamento : sequenza di celle a indirizzi crescenti, contenete infomazioni accessibili in blocco e singolarmente. Ad ogni cella è associato un indirizzo numerico la che identifica univocamente
- Prallelismo : Quanti bit ci sono in una cella di memoria in multipli di byte es. 64bit 8 byte. accessibile con un unica istruzione. 
- Accesso : modalità per reperire quel tipo di Informazione

Se elaboratore a 64bit allora celle di memoria a 64 bit

Memoria Centrale (per Operazioni): Informazioni, Istruzioni e Dati è la Memoria Volatile RAM e la Memoria nella CPU. Informazioni di Comando

Memoria di Massa (Dati): Dischi che non interagiscono con il Processore direttamente

**ROM** : Memoria di Massa Permanente e con accesso più lento. Inoltre non è elettronica(come la RAM) ma ottica o magnetica, così mantiene la memoria anche da macchina spenta.
## Memorie Centrali
**RAM** : Random Access Memory, è un circuito integrato con acceso costante al dilà della cella scelta, è elettronica e interna volatile casuale. Contiene i programmi e i dati da eseguire.

**Memoria Centale**:

1. Sistema Operativo RAM
2. Programmi RAM, prelevati dalla ROM
3. Memoria Video RAM-Video
4. Programma d'Avvio ROM (Boot Program). Serve almeno un pezzo di programma nella ROM per l'avvio.

**ROM** : Read-Only Memory. Memorie a sola lettura, memorizzazione programmi es.Dischi o  Chiavette USB.

**Memorie CACHE** : Perchè la RAM è lenta per la CPU, la CPU capisce il contesto e prende i dati più richiesti dalla RAM e li mette nella Cache

**RAM** : 
- DRAM(Dinamic) es. DDR2, DDR4
- SRAM(Statiche) più veloci

# Unità I/O
Dispositivi Periferici, collegamenti in Dati e Controllo 

Trasformare informazioni da un realtà (es. mondo umano) alla realtà del computer (int, char) e viceversa. Se ne occupano i **BUS Esterni / BUS di Periferia** es. USB o SATA.

Es. Porta : Mouse, Tastiera, Video, rete LAN, Seriale, USB, Audio.


## Codificata
Codificare un informazione vuol dire associare ad un elemento una stringa di simboli
Es. Codice Fiscale, Codice a Barre.

Codice Binario associa ad ogni elemento una sequenza di bit

Dati N bit si hanno 2^N combinazioni binarie differenti. Range tra 0 e 2<sup>N</sup>-1

Dato K oggetti ci serve l'Intero N >= log<sub>2</sub>K

Sistema decimale posizionale Es. 252 
 - = 2 * 100 + 5 * 10  + 2 * 1
 - = 2 * 10<sup>2</sup> + 5 * 10<sup>1</sup> + 2 * 10<sup>0</sup>

Sistema binario posizionale Es. 101<sub>2</sub>
 = 1 * 2<sup>2</sup> + 0 * 2<sup>1</sup> + 1 * 2<sup>0</sup> = 5<sub>10</sub>
 
2<sup>10</sup> = 1024<sub>10</sub>

Da decimale a Binario si leggono i Resti al contrario

25<sub>10</sub> ->?<sub>2</sub> = 25 % 2 (1)->12 % 2 (0)->6 % 2 (0)->3 % 2 (1)->1 % 2 (1) = 11001<sub>2</sub>

11001<sub>2</sub>= 1 * 2<sup>4</sup> + 1 * 2<sup>3</sup> + 1 = 16 + 8 + 1 = 25

## Aritmetica Binaria

1+1 = 0 + 'Carry 1' (Riporto)

0101<sub>2</sub> + 0011<sub>2</sub> = 1000<sub>2</sub> = 5<sub>10</sub> + 3<sub>10</sub> = 8<sub>10</sub>

0101<sub>2</sub> - 0011<sub>2</sub> = 0010<sub>2</sub> = 5<sub>10</sub> - 3<sub>10</sub> = 2<sub>10</sub>

0101<sub>2</sub> * 0011<sub>2</sub> = 0101 + 01010 = 1111<sub>2</sub>= 5<sub>10</sub> * 3<sub>10</sub> = 15<sub>10</sub>

### Overflow
Errore di risultato quando il numero di bit non è adeguato.

Es. 1111+0001=16 in 4 bit = 0000<sub>2</sub> -> max 15<sub>10</sub>

### Codifica Esadecimale
Divido il numero binario in blocchi da 4 bit da [0, F]

Es. 0101 1110 0001<sub>2</sub> = 5 E 1<sub>16</sub>

## Rappresentazione Numeri
### Numeri Relativi
Cioè quelli con **Segno** 

Es. Temperatura -12.3, +20.5

Rappresento il **+ con 0** e il **- con 1**
 -  +5 -> |0|101<sub>2</sub> 
 -  -5 -> |1|101<sub>2</sub>
 -  Segno | 0/1 | N cell numbrer
 -  Problematica +0 = -0 -> 0000 = -1000
 -  +3 + -3 = 0011<sub>2</sub> + 1011<sub>2</sub> = 1110<sub>2</sub> = -6 <> 0
 -  Intervallo di Rapprsentazione Con Modulo : 
    -  -(2<sup>N-1</sup>-1) <= x <= + (2<sup>N-1</sup>-1)
    -  Es. 4 bit -> -(8-1) <=  x <= + (8-1) -> -7<=x<=7
    -  8 bit -> [-127,+127] . 16 bit -> [-32 767,+32 767]

### Complemento a 2 - Interi
Il primo elemento ha segno negativo

Es. 101101<sub>2</sub> = (**-** 1*( 2<sup>5</sup>))+0*(2<sup>4</sup>)+1*(2<sup>3</sup>)+1*(2<sup>2</sup>)+0*(2<sup>1</sup>)+1*(2<sup>0</sup>)= **-** 32+8+4+1=-19

Es. 0101 -> +5 . 1101 ->5-8 = -3

#### +N<->-N
1. Faccio l'ooposto/il negarivo del numero
Es. +5 -> -5 : 0101 -> 1010
2. Aggiungo 1 con somma Es. 1010+1 = 1011 -> -8 + 3 = -5

Es. +7 = 0111 . -7? -> Opposto +1 : 1000 + 1 -> 1001 = -7

+7-7 = 0111+1001 = 0000 Carry(1) = 0

Con il complemento a 2 posso sommare e sotrarre indipendentemente dal bit di segno e funziona spesso anche senza il Carry nei risultati positivi

Es.00100110+11001011 =11110001 -> (2+4+32) + ((1+2+8+64)-128) = 38+(75-128)= 38+ (-53)=-15 = ((1+16+32+64)-128) = 113-128=-15

- Se gli Operandi hanno segno discorde non si ha mai Overflow
- Se gli Opeerandi hanno segno concorde si ha overflow solo quando il risultato ha segno discorde 
### Rappresentazione Numeri Reali
Cioè numeri con parte intera e decimale

Si utilizza una notazione basata su Mantissa ed Esponente Es. -3,001 -> -3001 * 10<sup>-3</sup> . +0,01 -> 1 * 10<sup>-2</sup>
### Notazione Floating Point
Notazione in **Virgola Mobile**

N = Segno(+/-) Mantissa x 2<sup>Esponente</sup>

Oltre a poter rappresetare la parte decimale mi fornisce un intervallo di rappresentazione più ampio es. 32 bit da -10<sup>38</sup> a +10<sup>38</sup>

Problemi :
  - Intervallo di Rappresentazione
  - Overflow
  - Precisione (es.1/3)

**Notazione   Scientifica** : 

Es. 13 -> 0,13 * 10<sup>2</sup> . 0,0001 -> 0,1 * 10<sup>-3</sup>