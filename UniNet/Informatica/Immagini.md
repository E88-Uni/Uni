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
Todo : min -11