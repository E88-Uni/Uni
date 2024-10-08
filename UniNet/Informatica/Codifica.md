# Codifica
Se si ha una quantità finita di informazioni si può utilizzare una sequenza finita di bit per rappresentare quell'informazione

## Testi

Problema del telegrafo, rappresentare caratteri con sequenze binarie (linea e punto)

## ASCII
Codice **ASCII** codifica standard : American Standard Code for Information Interchange

Basato su 
- **8 bit** = 2<sup>8</sup>=256 simboli
- 52 Caratteri [a,z][A,Z]
- 10 Cifre [0,9]
- Segni di Interpunzione (.:!?)
- Caratteri di controllo ('/0')

**UNICODE e UTF-8** Superset di ASCII esprime tutti i caratteri di tutte le lingue del mondo (più di un milione)

- 1 Byte  ASCII
- 2 Byte Caratteri Latini, Simboli, Greco, Arabo, Ebraico
- 3 Byte per alcune lingue

File word(Font, Spaziatura, ...) <> ASCII

File di testo può essere memorizzato :
- Formattato (word) : contiene dei codifici prima del blocco di codice ASCII
- Non Formattato (Sublime ASCII)
  

## PDF
Problema della stampa indipendente dal dispositivo di stampa -> Formato **PDF** (Portable Document Format)

Il PDF è un file che descrive documenti contenenti sia testi che immagini in qualsiasi risoluzione

## Immagini
Si delinea introno all'immagine una matrice, composta da **Pixel**

**Pixel**
- Posizione x, y : Riga, Colonna
- Valori del Colore RGB. Il Bianco è R True, G True, B True 
- Intensità Colore

**24 bpp** : 8 bit Red + 8 bit Green + 8 bit Blue . 3 Byte . bpp(Bit Per Pixel)

Standard **True Color** 24bpp (3 Byte)

2^<sup>N</sup> Colori rappresentabili -> 2^<sup>24</sup>

**Memoria Immagine** M(bit) = Righe x Colonne x 24(bpp) 
Es. 1000(y) * 2000(x) * 24 bit = 6 000 000 Byte = 6 MB

**Dot** corrispettivo output del pixel 

**Rappresentazione Raster** : detta anche bitmap o pixmap che significa 'punto per punto', raster(cancelletto)

**Rappresentazion Vettoriale** : Fatta specificando gli elementi com Linee, Cerchi, Triangoli, Rettangoli

Es. Triangolo + Cerchio = LINE(P1, P2); LINE(P2, P3); LINE(P3, P1); CIRCLE(C, R)

**Raster** : prende in input un **file vettoriale** e  scompone in punti i vettori per la rappresentazione grafica