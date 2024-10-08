# Codifica Immaggini
## Compressione
Ridurre il numero di bit per rappresentare un Informazione

**Proprietà** propria del mondo digitale e non fattibile nel mondo analogico. Motivi :
1. Limitare la quantità di memoria per memorizzare un dato
2. Avere necessità di usare meno risorse (di banda) per muovere questa informazione

**Tecniche di Compressione :**
 - Lossless : Senza Perdita Es. zippare
 - Lossy : Con Perdita Es. da immagine a jpeg

## Lossless
**Codifica Run-Length** :
Es. AAAAAAABAAAAAAA (15 byte) -> A7B1A7(6 byte)

**Codifica con Dizionario** : Es. 'I Torinesi abitano a Torino' -> 'I @esi abitano a @o' con @='Torin'

**BMP**: Bipmap Formato Raster senza compressione

**GIF**: Formato Raster (Graphic Interchange Format)
 - Buona Compressione (Senza Perdita)
 - 8BPP (256 Colori) -> Immagini Semplici
  
**PNG** : Portable Network Graphics
 - Standard W3C
 - Ottima Compressione (Senza Perdita)
 - 24 BPP(16M Colori) : RGB, Palette RGB, greyscale
 - Ottimizzazioni per Grafica Es. Icone o Disegni o Fotografie
  
**JPEG** : Joint Photographic Experts Group
 - 24 BPP(16M Colori) con vasta gamma di colori e sfumature
 - Puoi sceglie quanto comprimere un immagine, da senza perdita a grande perdita ma massima compressione

### Misurare la Compressionee
**Rapporto o Fattore di Compressione** : C = dim. Dati / dim: Dati Compressi = N:1 Es. 10MB/1MB = C = 10:1

**Risparmio di Spazio %** : S = 1 - dim: Dati Compressi / dim: Dati Es. S = 1-1MB/10MB = 0.9 -> 90% . S = 1-2MB/10MB = 1 - 0.2 -> 80% . S = 1-10MB/10MB = 1 - 1 -> 0%

**Nota** Spesso l'80% di compressione è invisibile all'occhio ma un 95% di compressione è molto visibile

### Scaling
In generale funziona meglio con le immagini vettoriali, perchè si hanno le istruzioni per disegnare.

Quelle **raster** si basano sulla riduzione o ingrandimento dei pixel

## Immagini In Movimento - Filmati
Filmato basato sullo scorrimento di singole immagini chiamata **frame** o **fotogramma**

  - Minimo 16 FPS per Percezione Umana(Frame per Secondo)

  - Cinema 24 FPS
  - TV Analogica 25 FPS Europa , 30 FPS USA

**Compessione Interframe** : Se le immagini successive hanno elementi in comune memorizzo e stampo solo la parte dell'immagine in movimento, cioè con modifiche. **Trasmetto solo le variazioni**. Standars MPEG-2

MPEG : Moving Picture Experts Group. Non solo computer ma anche telefisione Satellitare e Digitale.

Standard MPEG-2 del 1994 Richiede da 4 a 10 MB al Secondo

# Codifica Suoni e Voce
Tramite **Convertitore Analogico Digitale** :
Prende il segnale da un microfono o un sensore e da segnale elettrico lo trasforma e trasferisce in una sequenza di bit
## Suoni
Convertitore A/D : 
Utilizza Input tramite Sensori poi il Trasduttore converte in segnale elettrico poi il Convertitore A/D converte in sequenze di numeri bit 

Va preso il valore dei segnali di input a **intervalli fissi** cioè la **frequenza di campionamento** che è la precisione dell'informazione espressa in **Hertz** cioè **volte al secondo** 

## Musica CD
- Percepita dall'uomo tra 0 e 20 000 Hz (20kHz)
- 44100 Hz cioè campioni al secondo
- 16 bit per campione
- 2 Canali

Quindi il **CD Audio** quanti bit al secondo ? = 44100 * 16 * 2 = 1 400 000 bit/s

**MP3** (MPEG Audio Layer 3) Algoritmo di compressione audio con perdita

**MIDI** (Musical Instrument Digital Interface) Rappresenta Spartiti Musicali Elettronici

## Voce

Voce intelleggibile per l'uomo tra 0 e 4kHz

**PCM** (Pulse Code Modulation) del 1937 Telefonia Fissa Digitale :
 - 8 kHz
 - 8 bit Campione
 - 64 kbit/s

**CELP** (Code-Excited Linear Predict)Telefonia Mobile Cellulare 10 kbit/s
